#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include<windows.h>
using namespace std;

void bresenline(int x1,int y1,int x2,int y2,int l=640,int b=480,int col=15)
{
    int m=1;
    int x=x1,y=y1;
    int dx=x2-x1,dy=y2-y1;
    if(abs(y2-y1)<abs(x2-x1)){
        if(x2<x1)
            x=x2,y=y2,dx=x1-x2,dy=y1-y2;
        if(dy<0)
            dy=-dy,y=-y,m=-1;
        int d=dx-(dy<<1);
        while(x<=std::max(x1,x2)){
            putpixel((l>>1)+x,(b>>1)-m*y,col);
            if(d<0)
                y++,d+=(dx<<1)-(dy<<1);
            else
                d-=(dy<<1);
            x++;
        }
    }
    else{
        if(y2<y1)
            x=x2,y=y2,dx=x1-x2,dy=y1-y2;
        if(dx<0)
            dx=-dx,x=-x,m=-1;
        int d=dy-(dx<<1);
        while(y<=std::max(y1,y2)){
            putpixel((l>>1)+m*x,(b>>1)-y,col);
            if(d<0)
                x++,d+=(dy<<1)-(dx<<1);
            else
                d-=(dx<<1);
            y++;
        }
    }
}
bool check(int x1 , int y1 , int x2 , int y2, int l=640 , int b=480)
{
    if((x1>=0 && x1<=(l-5)) && (x2>=0 && x2<=(l-5)) && (y1>=0 && y1<=(b-5)) && (y2>=0 && y2<=(b-5)))
        return 0;
    return 1;
}

bool quadrantBanao(int x,int y,int xcentre=0,int ycentre=0,int l=640 , int b = 480,int col=15)
{
    int t=(l>>1)+xcentre;
    int z=(b>>1)-ycentre;
    if(check(t+x,z+y,t-x,z-y,l,b))
        return 1;
    putpixel(t+x,z-y,col);
    putpixel(t+x,z+y,col);
    putpixel(t-x,z-y,col);
    putpixel(t-x,z+y,col);
    return 0;
}
void bresencircle(int r,int l=640 , int b=480,int xcentre=0,int ycentre=0,int col=15)
{
    int d=((1-r)<<1);
    int x=0,y=r;
    while(x<=r&&y>=0){
        quadrantBanao(x,y,xcentre,ycentre,l,b,col);
        if(d<0){
            int t=(d<<1)+(y<<1)-1;
            if(t<0)
                d+=(x<<1)+3;
            else
                d+=((x-y)<<1)+6,y--;
            x++;
        }
        else if(d>0){
            int t=-1*(d<<1)+(x<<1)+1;
            if(t<0)
                d+=3-(y<<1);
            else
                d+=((x-y)<<1)+6,x++;
            y--;
        }
        else
            d+=((x-y)<<1)+6,x++,y--;
    }
}

int roundoff(float x)
{
    int a=(int)x;
    if(x-a<0.5)
        return a;
    return a+1;
}

void hermite(float p0x,float p0y,float p3x,float p3y,float p0_x,float p0_y,float p1_x,float p1_y,int x1,int y1,int r1,int x2,int y2,int r2,int col,int dx,int dy)
{
    for(float t=0;t<=1;t+=0.001){
        float x=(2*t*t*t-3*t*t+1)*p0x+(-2*t*t*t+3*t*t)*p3x+(t*t*t-2*t*t+t)*p0_x+(t*t*t-t*t)*p1_x;
        float y=(2*t*t*t-3*t*t+1)*p0y+(-2*t*t*t+3*t*t)*p3y+(t*t*t-2*t*t+t)*p0_y+(t*t*t-t*t)*p1_y;
        if(((x1-x-dx)*(x1-x-dx)+(y+dy-y1)*(y+dy-y1)-r1*r1>0)||((x1-x-dx)*(x1-x-dx)+(y+dy-y1)*(y+dy-y1)-r1*r1<=0&&(x2-x-dx)*(x2-x-dx)+(y+dy-y2)*(y+dy-y2)-r2*r2<=0))
            putpixel(roundoff(675+x+dx),roundoff(350-y-dy),col);
    }
}

void drawName(int x1,int y1,int r1,int x2,int y2,int r2,int col,int dx,int dy)
{
    //1

	hermite(60,13,60,-25,0,10,0,10,x1,y1,r1,x2,y2,r2,col,dx,dy);
	hermite(60,13,45,0,-10,-10,-10,-10,x1,y1,r1,x2,y2,r2,col,dx,dy);
	hermite(45,-25,75,-25,10,0,10,0,x1,y1,r1,x2,y2,r2,col,dx,dy);

	//6

	hermite(110,13,105,-25,-80,-10,80,-20,x1,y1,r1,x2,y2,r2,col,dx,dy);
	hermite(88,-15,105,-25,60,70,-70,-10,x1,y1,r1,x2,y2,r2,col,dx,dy);

	//4
	hermite(155,13,130,-10,5,5,5,5,x1,y1,r1,x2,y2,r2,col,dx,dy);
	hermite(155,13,155,-25,0,-10,0,-10,x1,y1,r1,x2,y2,r2,col,dx,dy);
	hermite(130,-10,170,-10,10,0,10,0,x1,y1,r1,x2,y2,r2,col,dx,dy);

	//7
	hermite(180,13,210,13,5,0,5,0,x1,y1,r1,x2,y2,r2,col,dx,dy);
	hermite(210,13,190,-25,-10,-10,-10,-10,x1,y1,r1,x2,y2,r2,col,dx,dy);
}
void drawRoll(int c1x,int c1y,int r1,int c2x,int c2y,int r2)
{
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,-300,-300);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,200,-300);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,-500,-150);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,0,-150);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,-300,0);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,200,0);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,-500,150);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,0,150);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,-300,300);
    drawName(c1x,c1y,r1,c2x,c2y,r2,WHITE,200,300);
}
int main()
{
    float pi=3.14159265359;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    initwindow(1350,700);
    int theta=0;
    int x=-450;
    setcolor(WHITE);
    int c1x=0,c1y=0;
    int c2x=75,c2y=-90,r2=50;
    int y1=100,y2=100,y3=25,y4=25,x1=75,x2=125,x3=125,x4=75;
    int tx1=-100,ty1=100,tx2=-50,ty2=50,tx3=-150,ty3=50;
    int ry1=-25,ry2=-25,ry3=-125,ry4=-125,rx1=-125,rx2=-50,rx3=-50,rx4=-125;
    int page=0;
    setactivepage(page);
    setvisualpage(1-page);
    while(x<=450){

    setactivepage(page);
    setvisualpage(1-page);
        cleardevice();
        drawRoll(c1x+x,c1y,200,c2x*cos(theta*pi/180)-c2y*sin(theta*pi/180)+x,c2x*sin(theta*pi/180)+c2y*cos(theta*pi/180),r2);
        bresencircle(200,1350,700,c1x+x,c1y,WHITE);
        bresenline(x1*cos(theta*pi/180)-y1*sin(theta*pi/180)+x,x1*sin(theta*pi/180)+y1*cos(theta*pi/180),x2*cos(theta*pi/180)-y2*sin(theta*pi/180)+x,x2*sin(theta*pi/180)+y2*cos(theta*pi/180),1350,700,WHITE);
        bresenline(x2*cos(theta*pi/180)-y2*sin(theta*pi/180)+x,x2*sin(theta*pi/180)+y2*cos(theta*pi/180),x3*cos(theta*pi/180)-y3*sin(theta*pi/180)+x,x3*sin(theta*pi/180)+y3*cos(theta*pi/180),1350,700,WHITE);
        bresenline(x3*cos(theta*pi/180)-y3*sin(theta*pi/180)+x,x3*sin(theta*pi/180)+y3*cos(theta*pi/180),x4*cos(theta*pi/180)-y4*sin(theta*pi/180)+x,x4*sin(theta*pi/180)+y4*cos(theta*pi/180),1350,700,WHITE);
        bresenline(x4*cos(theta*pi/180)-y4*sin(theta*pi/180)+x,x4*sin(theta*pi/180)+y4*cos(theta*pi/180),x1*cos(theta*pi/180)-y1*sin(theta*pi/180)+x,x1*sin(theta*pi/180)+y1*cos(theta*pi/180),1350,700,WHITE);

        bresenline(rx1*cos(theta*pi/180)-ry1*sin(theta*pi/180)+x,rx1*sin(theta*pi/180)+ry1*cos(theta*pi/180),rx2*cos(theta*pi/180)-ry2*sin(theta*pi/180)+x,rx2*sin(theta*pi/180)+ry2*cos(theta*pi/180),1350,700,WHITE);
        bresenline(rx2*cos(theta*pi/180)-ry2*sin(theta*pi/180)+x,rx2*sin(theta*pi/180)+ry2*cos(theta*pi/180),rx3*cos(theta*pi/180)-ry3*sin(theta*pi/180)+x,rx3*sin(theta*pi/180)+ry3*cos(theta*pi/180),1350,700,WHITE);
        bresenline(rx3*cos(theta*pi/180)-ry3*sin(theta*pi/180)+x,rx3*sin(theta*pi/180)+ry3*cos(theta*pi/180),rx4*cos(theta*pi/180)-ry4*sin(theta*pi/180)+x,rx4*sin(theta*pi/180)+ry4*cos(theta*pi/180),1350,700,WHITE);
        bresenline(rx4*cos(theta*pi/180)-ry4*sin(theta*pi/180)+x,rx4*sin(theta*pi/180)+ry4*cos(theta*pi/180),rx1*cos(theta*pi/180)-ry1*sin(theta*pi/180)+x,rx1*sin(theta*pi/180)+ry1*cos(theta*pi/180),1350,700,WHITE);

        bresenline(tx1*cos(theta*pi/180)-ty1*sin(theta*pi/180)+x,tx1*sin(theta*pi/180)+ty1*cos(theta*pi/180),tx2*cos(theta*pi/180)-ty2*sin(theta*pi/180)+x,tx2*sin(theta*pi/180)+ty2*cos(theta*pi/180),1350,700,WHITE);
        bresenline(tx2*cos(theta*pi/180)-ty2*sin(theta*pi/180)+x,tx2*sin(theta*pi/180)+ty2*cos(theta*pi/180),tx3*cos(theta*pi/180)-ty3*sin(theta*pi/180)+x,tx3*sin(theta*pi/180)+ty3*cos(theta*pi/180),1350,700,WHITE);
        bresenline(tx3*cos(theta*pi/180)-ty3*sin(theta*pi/180)+x,tx3*sin(theta*pi/180)+ty3*cos(theta*pi/180),tx1*cos(theta*pi/180)-ty1*sin(theta*pi/180)+x,tx1*sin(theta*pi/180)+ty1*cos(theta*pi/180),1350,700,WHITE);

        bresencircle(r2,1350,700,c2x*cos(theta*pi/180)-c2y*sin(theta*pi/180)+x,c2x*sin(theta*pi/180)+c2y*cos(theta*pi/180),WHITE);;

        page=1-page;
        theta=(theta+5)%360;
        x+=10;

    }
    getch();
    closegraph();
    return 0;
}





