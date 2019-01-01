
#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
int x,y;
};

void curve ( point p0, point p1, float rx0, float ry0, float rx1, float ry1, float rad, float m, float n, int cx, int cy)
{
    float x,y,t,X,Y;

    for ( t = 0 ; t <= 1.0 ; t = t + 0.001 )
    {
        x = ( 2*t*t*t - 3*t*t + 1 )*p0.x + (-1*2*t*t*t + 3*t*t)*p1.x + ( t*t*t - 2*t*t + t)*rx0 + ( t*t*t - t*t )*rx1;
        y = ( 2*t*t*t - 3*t*t + 1 )*p0.y + (-1*2*t*t*t + 3*t*t)*p1.y + ( t*t*t - 2*t*t + t)*ry0 + ( t*t*t - t*t )*ry1;

        X =  x*cos(rad) - y*sin(rad);
        Y =  x*sin(rad) + y*cos(rad);
        putpixel(cx+X*m,cy+Y*n,WHITE);
    }

}

/*X = - x*cos(rad) + y*sin(rad);
        Y = -x*sin(rad) - y*cos(rad); */



void func(float m, float n,int cx, int cy, float rd)
{
    //1
    point p0,p1;
    p0.x = 0;
    p0.y = 0;

    p1.x = 0;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy);

    //6
    p0.x = 100;
    p0.y = 10;

    p1.x = 30;
    p1.y = 60;

    curve(p0, p1, -150, -100, 10, 50, rd, m, n, cx, cy);

    p0.x = 30;
    p0.y = 60;

    p1.x = 80;
    p1.y = 100;

    curve(p0, p1, 15, 100, 50, 10, rd, m, n, cx, cy);

    p0.x = 80;
    p0.y = 100;

    p1.x = 30;
    p1.y = 60;

    curve(p0, p1, 200, -10, -100, 150, rd, m, n, cx, cy);


    //7

    p0.x = 200;
    p0.y = 0;

    p1.x = 130;
    p1.y = 0;

    curve(p0, p1, -20, 0, 20, 0, rd, m, n, cx, cy);

    p0.x = 200;
    p0.y = 0;

    p1.x = 160;
    p1.y = 100;
     curve(p0, p1, -4, 10, 4, -10, rd, m, n, cx, cy);

    //1

    p0.x = 220;
    p0.y = 0;

    p1.x = 220;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy);
}


int main()
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"..//BGI");

    func(1,1,320,240,0);




	getch();
	closegraph();

	return 0;

}
