
#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>
using namespace std;

void drawline(int x1,int y1,int x2,int y2)
{

int x=x1,y=y1;
int dx=x2-x1,dy=y2-y1;
int d=2*dy-dx;
putpixel(x,y,WHITE);
while(x<=x2)
{
    if(d<0)
    {
        d+=2*dy;
    }
    else{
        d+=2*(dy-dx);
        y++;
    }
    x++;
    putpixel(x,y,WHITE);
}

}

struct point
{
float x,y;
};

void curve ( point p0, point p1, float rx0, float ry0, float rx1, float ry1, float rad, float m, float n, int cx, int cy, int color)
{
    float x,y,t,X,Y;

    for ( t = 0 ; t <= 1.0 ; t = t + 0.001 )
    {
        x = ( 2*t*t*t - 3*t*t + 1 )*p0.x + (-1*2*t*t*t + 3*t*t)*p1.x + ( t*t*t - 2*t*t + t)*rx0 + ( t*t*t - t*t )*rx1;
        y = ( 2*t*t*t - 3*t*t + 1 )*p0.y + (-1*2*t*t*t + 3*t*t)*p1.y + ( t*t*t - 2*t*t + t)*ry0 + ( t*t*t - t*t )*ry1;

        X =  x*cos(rad) - y*sin(rad);
        Y =  x*sin(rad) + y*cos(rad);
        putpixel(cx+X*m,cy+Y*n,color);
    }

}

/*X = - x*cos(rad) + y*sin(rad);
        Y = -x*sin(rad) - y*cos(rad); */



void func(float m, float n,int cx, int cy, float rd, int color)
{
    //1
    point p0,p1;
    p0.x = 50;
    p0.y = 0;

    p1.x = 50;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    p0.x = 40;
    p0.y = 20;

    p1.x = 40;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    p0.x = 40;
    p0.y = 0;

    p1.x = 10;
    p1.y = 40;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 22;
    p0.y = 40;

    p1.x = 40;
    p1.y = 20;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 10;
    p0.y = 40;

    p1.x = 22;
    p1.y = 40;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

        p0.x = 40;
    p0.y = 0;

    p1.x = 50;
    p1.y = 0;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

        p0.x = 35;
    p0.y = 100;

    p1.x = 55;
    p1.y = 100;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

    p0.x = 35;
    p0.y = 100;

    p1.x = 55;
    p1.y = 100;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

    p0.x = 40;
    p0.y = 100;

    p1.x = 30;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 50;
    p0.y = 100;

    p1.x = 60;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    //6
    p0.x = 70;
    p0.y = 0;

    p1.x = 70;
    p1.y = 100;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

        p0.x = 80;
    p0.y = 10;

    p1.x = 80;
    p1.y = 50;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

        p0.x = 80;
    p0.y = 60;

    p1.x = 80;
    p1.y = 90;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

        p0.x = 110;
    p0.y = 60;

    p1.x = 110;
    p1.y = 90;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

        p0.x = 120;
    p0.y = 0;

    p1.x = 120;
    p1.y = 10;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

        p0.x = 120;
    p0.y = 50;

    p1.x = 120;
    p1.y = 100;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

    p0.x = 70;
    p0.y = 0;

    p1.x = 120;
    p1.y = 0;

    curve(p0, p1, 5, 0, 5, 0, rd, m, n, cx, cy,color);

    p0.x = 80;
    p0.y = 10;

    p1.x = 120;
    p1.y = 10;

    curve(p0, p1, 5, 0, 5, 0, rd, m, n, cx, cy,color);

    p0.x = 80;
    p0.y = 50;

    p1.x = 120;
    p1.y = 50;

    curve(p0, p1, 5, 0, 5, 0, rd, m, n, cx, cy,color);

    p0.x = 80;
    p0.y = 60;

    p1.x = 110;
    p1.y = 60;

    curve(p0, p1, 5, 0, 5, 0, rd, m, n, cx, cy,color);

    p0.x = 80;
    p0.y = 90;

    p1.x = 110;
    p1.y = 90;

    curve(p0, p1, 5, 0, 5, 0, rd, m, n, cx, cy,color);

    p0.x = 70;
    p0.y = 100;

    p1.x = 120;
    p1.y = 100;

    curve(p0, p1, 5, 0, 5, 0, rd, m, n, cx, cy,color);

    p0.x = 65;
    p0.y = 100;

    p1.x = 125;
    p1.y = 100;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

    p0.x = 90;
    p0.y = 100;

    p1.x = 80;
    p1.y = 120;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

    p0.x = 100;
    p0.y = 100;

    p1.x = 110;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 50;
    p0.y = 100;

    p1.x = 60;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    //7
    p0.x = 140;
    p0.y = 0;

    p1.x = 140;
    p1.y = 10;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

    p0.x = 180;
    p0.y = 10;

    p1.x = 180;
    p1.y = 100;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

    p0.x = 190;
    p0.y = 0;

    p1.x = 190;
    p1.y = 100;

    curve(p0, p1, 0, 5, 0, 5, rd, m, n, cx, cy,color);

    p0.x = 140;
    p0.y = 0;

    p1.x = 190;
    p1.y = 0;

    curve(p0, p1, 5,0, 5, 0, rd, m, n, cx, cy,color);

     p0.x = 180;
    p0.y = 100;

    p1.x = 190;
    p1.y = 100;

    curve(p0, p1, 5,0, 5, 0, rd, m, n, cx, cy,color);

     p0.x = 140;
    p0.y = 10;

    p1.x = 180;
    p1.y = 10;

    curve(p0, p1, 5,0, 5, 0, rd, m, n, cx, cy,color);

    p0.x = 175;
    p0.y = 100;

    p1.x = 195;
    p1.y = 100;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

    p0.x = 180;
    p0.y = 100;

    p1.x = 170;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 190;
    p0.y = 100;

    p1.x = 200;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

        //1
    p0.x = 260;
    p0.y = 0;

    p1.x = 260;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    p0.x = 250;
    p0.y = 20;

    p1.x = 250;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    p0.x = 250;
    p0.y = 0;

    p1.x = 220;
    p1.y = 40;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 232;
    p0.y = 40;

    p1.x = 250;
    p1.y = 20;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 220;
    p0.y = 40;

    p1.x = 232;
    p1.y = 40;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

        p0.x = 250;
    p0.y = 0;

    p1.x = 260;
    p1.y = 0;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

        p0.x = 245;
    p0.y = 100;

    p1.x = 265;
    p1.y = 100;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

    p0.x = 245;
    p0.y = 100;

    p1.x = 265;
    p1.y = 100;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

    p0.x = 250;
    p0.y = 100;

    p1.x = 240;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);

    p0.x = 260;
    p0.y = 100;

    p1.x = 270;
    p1.y = 120;

    curve(p0,p1,5,5,5,5,rd,m,n,cx,cy,color);
}


void func2(float m, float n,int cx, int cy, float rd, int color){

    point p0, p1;
    p0.x = -200;
    p0.y = -20;

    p1.x = -200;
    p1.y = 0;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    p0.x = 200;
    p0.y = -20;

    p1.x = 200;
    p1.y = 0;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);


    p0.x = -200;
    p0.y = -20;

    p1.x = 200;
    p1.y = -20;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);

 p0.x = -200;
    p0.y = 0;

    p1.x = 200;
    p1.y = 0;

    curve(p0,p1,5,0,5,0,rd,m,n,cx,cy,color);
}


int main()
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"..//BGI");

    line(320,240,220,400);
    line(220,400,420,400);
    line(420,400,320,240);

    int ang = -1.131;
    int ang2 = 1.131;
    int page = 0;
    int X = 120;
    int Y = 190;
    while(true){
        for(float i = ang; i < ang2; i+=0.1 ){
                X = 320 - 206*cos(i);
            Y = 240 - 206*sin(i) ;
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            line(320,240,220,400);
    line(220,400,420,400);
    line(420,400,320,240);
            func(0.25,0.25, X,Y,i,WHITE);
            func2(1,1,320,240,i,WHITE);
            cout<<i<<endl;
            delay(50);
            //func2(1,1,320,240,i,BLACK);
            page=1-page;
        }

        for(float i = ang2; i > ang; i-=0.1 ){
                    X = 320 - 206*cos(i);
            Y = 240 - 206*sin(i);
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();
                    line(320,240,220,400);
    line(220,400,420,400);
    line(420,400,320,240);;
    func(0.25,0.25, X,Y,i,WHITE);
            func2(1,1,320,240,i,WHITE);
            delay(50);
           // func2(1,1,320,240,i,BLACK);
            page=1-page;
        }

    }




	getch();
	closegraph();

	return 0;

}
