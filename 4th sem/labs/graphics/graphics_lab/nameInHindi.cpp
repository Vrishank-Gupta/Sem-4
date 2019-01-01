
#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
int x,y;
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



void func(float m, float n,int cx, int cy, float rd,int color)
{
    //gee
    point p0,p1;
    p0.x = 0;
    p0.y = 0;

    p1.x = 0;
    p1.y = 60;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    p0.x = 0;
    p0.y = 60;

    p1.x = 0;
    p1.y = 40;

    curve(p0,p1,-50,60,50,60,rd,m,n,cx,cy,color);

    p0.x = 20;
    p0.y = 0;

    p1.x = 20;
    p1.y = 100;

    curve(p0,p1,0,60,0,60,rd,m,n,cx,cy,color);

    p0.x = 40;
    p0.y = 0;

    p1.x = 40;
    p1.y = 100;

    curve(p0,p1,0,60,0,60,rd,m,n,cx,cy,color);

    p0.x = 20;
    p0.y = 0;

    p1.x = 40;
    p1.y = 0;

    curve(p0,p1,10,-100,10,100,rd,m,n,cx,cy,color);

    //ta

    p0.x = 90;
    p0.y = 0;

    p1.x = 90;
    p1.y = 100;

    curve(p0,p1,0,60,0,60,rd,m,n,cx,cy,color);

    p0.x = 90;
    p0.y = 50;

    p1.x = 50;
    p1.y = 50;

    curve(p0,p1,10,0,10,0,rd,m,n,cx,cy,color);

    p0.x = 50;
    p0.y = 50;

    p1.x = 70;
    p1.y = 100;

    curve(p0,p1,10,0,10,0,rd,m,n,cx,cy,color);

    p0.x = 110;
    p0.y = 0;

    p1.x = 110;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    //shu

    p0.x = 140;
    p0.y = 0;

    p1.x = 140;
    p1.y = 70;

    curve(p0,p1,70,10,-70,10,rd,m,n,cx,cy,color);

    p0.x = 140;
    p0.y = 0;

    p1.x = 153;
    p1.y = 10;

    curve(p0,p1,-50,30,50,-100,rd,m,n,cx,cy,color);

    p0.x = 140;
    p0.y = 70;

    p1.x = 150;
    p1.y = 55;

    curve(p0,p1,-50,-30,10,50,rd,m,n,cx,cy,color);

    p0.x = 150;
    p0.y = 55;

    p1.x = 160;
    p1.y = 100;

    curve(p0,p1,10,50,10,50,rd,m,n,cx,cy,color);

    p0.x = 180;
    p0.y = 0;

    p1.x = 180;
    p1.y = 100;

    curve(p0,p1,0,50,0,50,rd,m,n,cx,cy,color);

    p0.x = 175;
    p0.y = 100;

    p1.x = 205;
    p1.y = 130;

    curve(p0,p1,30,-10,10,50,rd,m,n,cx,cy,color);

    p0.x = 175;
    p0.y = 100;

    p1.x = 195;
    p1.y = 110;

    curve(p0,p1,-10,50,50,-10,rd,m,n,cx,cy,color);

    p0.x = -20;
    p0.y = 0;

    p1.x = 200;
    p1.y = 0;

    curve(p0,p1,10,0,10,0,rd,m,n,cx,cy,color);
}


int main()
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"..//BGI");

    func(1, 1, 100, 100, 0, WHITE);
    circle(210, 80, 5);


	getch();
	closegraph();

	return 0;

}



