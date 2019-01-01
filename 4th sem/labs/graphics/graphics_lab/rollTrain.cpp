
#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>
using namespace std;
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
    p0.x = 0;
    p0.y = 0;

    p1.x = 0;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    //6
    p0.x = 100;
    p0.y = 10;

    p1.x = 30;
    p1.y = 60;

    curve(p0, p1, -150, -100, 10, 50, rd, m, n, cx, cy,color);

    p0.x = 30;
    p0.y = 60;

    p1.x = 80;
    p1.y = 100;

    curve(p0, p1, 15, 100, 50, 10, rd, m, n, cx, cy,color);

    p0.x = 80;
    p0.y = 100;

    p1.x = 30;
    p1.y = 60;

    curve(p0, p1, 200, -10, -100, 150, rd, m, n, cx, cy,color);


    //7

    p0.x = 200;
    p0.y = 0;

    p1.x = 130;
    p1.y = 0;

    curve(p0, p1, -20, 0, 20, 0, rd, m, n, cx, cy,color);

    p0.x = 200;
    p0.y = 0;

    p1.x = 160;
    p1.y = 100;
     curve(p0, p1, -4, 10, 4, -10, rd, m, n, cx, cy,color);

    //1

    p0.x = 220;
    p0.y = 0;

    p1.x = 220;
    p1.y = 100;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);
}


int main()
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"..//BGI");

	line(0, 240, 640, 240);
	line(320, 0, 320, 480);
	line(170,390,470,390);
	line(470,390,320,90);
	line(320,90,170,390);

    while(true){
        int CX = 170;
        int CY = 390;

        while(CX<=470){
            func(0.3, 0.3, CX, CY,0,WHITE);
            delay(5);
            func(0.3,0.3, CX, CY, 0, BLACK);
            CX+=10;
        }

        CX = 470;
        CY = 390;

        while(CX >= 320){
            float y = 2*CX - 550;
            func(0.3, 0.3, CX, y,1.1,WHITE);
            delay(5);
            func(0.3,0.3, CX, y, 1.1, BLACK);
            CX-=5;
        }

        CX = 320;
        CY = 90;

        while(CX >= 170){
            float y = 730 - 2*CX;
            func(0.3, 0.3, CX, y,-1.1,WHITE);
            delay(5);
            func(0.3,0.3, CX, y, -1.1, BLACK);
            CX-=5;
        }
    }




	getch();
	closegraph();

	return 0;

}
