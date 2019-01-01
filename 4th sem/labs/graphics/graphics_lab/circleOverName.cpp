#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include<windows.h>
using namespace std;

int roundoff(float x)
{
    int a=(int)x;
    if(x-a<0.5)
        return a;
    return a+1;
}

void hermite(float p0x,float p0y,float p3x,float p3y,float p0_x,float p0_y,float p1_x,float p1_y,int xx,int yy,int r,int col)
{
    for(float t=0;t<=1;t+=0.001){
        float x=(2*t*t*t-3*t*t+1)*p0x+(-2*t*t*t+3*t*t)*p3x+(t*t*t-2*t*t+t)*p0_x+(t*t*t-t*t)*p1_x;
        float y=(2*t*t*t-3*t*t+1)*p0y+(-2*t*t*t+3*t*t)*p3y+(t*t*t-2*t*t+t)*p0_y+(t*t*t-t*t)*p1_y;
        if((xx-(675+x))*(xx-(675+x))+(yy-(350-y))*(yy-(350-y))-r*r<=0)
            putpixel(roundoff(675+x),roundoff(350-y),col);
    }
}

void drawName(int x,int y,int r,int col)
{
    //da
    hermite(-250,100,300,100,50,50,50,50,x,y,r,col);
    hermite(-150,100,-150,60,10,-10,-10,-10,x,y,r,col);
    hermite(-150,60,-150,-60,-300,0,300,0,x,y,r,col);
    hermite(-150,-60,-150,-20,70,0,-70,0,x,y,r,col);
    hermite(-150,-20,-150,-60,-60,0,50,-60,x,y,r,col);
    hermite(-150,-60,-120,-100,50,-60,60,-60,x,y,r,col);
    //ma
    hermite(-50,100,-50,-20,0,-200,-20,-20,x,y,r,col);
    hermite(-50,-20,-75,10,-40,-20,20,20,x,y,r,col);
    hermite(-75,10,50,10,10,10,10,10,x,y,r,col);
    hermite(50,100,50,-100,10,-10,10,-10,x,y,r,col);
    hermite(200,100,200,-100,10,-10,10,-10,x,y,r,col);
    //k
    hermite(200,0,100,0,-200,100,-30,-90,x,y,r,col);
    hermite(100,0,200,0,-50,-150,150,300,x,y,r,col);
    hermite(200,0,270,0,80,80,60,-60,x,y,r,col);
    hermite(270,0,230,-100,60,-60,-150,-150,x,y,r,col);
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    initwindow(1350,700);
    int page=0;
    for(int y=0;y<=700;y++){
        setactivepage(page);
        setvisualpage(1-page);

        setcolor(BLACK);
        circle(675,y-2,200);
        drawName(675,y-2,200,BLACK);

        setcolor(WHITE);
        circle(675,y,200);
        drawName(675,y,200,WHITE);

        page=1-page;
    }
    getch();
    closegraph();
    return 0;
}



