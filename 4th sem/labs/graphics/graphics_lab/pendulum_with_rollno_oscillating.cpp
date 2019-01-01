
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
    //1
    point p0,p1;
    p0.x = -30;
    p0.y = -20;

    p1.x = -30;
    p1.y = 20;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);

    //6
    p0.x = -3;
    p0.y = -15;

    p1.x = -24;
    p1.y = 0;

    curve(p0, p1, -75, -50, -10, 20, rd, m, n, cx, cy,color);

    p0.x = -24;
    p0.y = 0;

    p1.x = -13;
    p1.y = 20;

    curve(p0, p1, 10, 20, 50, 10, rd, m, n, cx, cy,color);

    p0.x = -13;
    p0.y = 20;

    p1.x = -24;
    p1.y = 0;

    curve(p0, p1, 50, -10, -10, 15, rd, m, n, cx, cy,color);


    //7

    p0.x = 24;
    p0.y = -20;

    p1.x = 3;
    p1.y = -20;

    curve(p0, p1, -20, 0, 20, 0, rd, m, n, cx, cy,color);

    p0.x = 24;
    p0.y = -20;

    p1.x = 15;
    p1.y = 20;
     curve(p0, p1, -4, 10, 4, -10, rd, m, n, cx, cy,color);

    //1

    p0.x = 30;
    p0.y = -20;

    p1.x = 30;
    p1.y = 20;

    curve(p0,p1,0,5,0,5,rd,m,n,cx,cy,color);
}


int main()
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"..//BGI");

	line(0, 240, 640, 240);
	line(320, 0, 320, 480);
    int x0 = 320, y0 = 240;
    int x1 = 320, y1 = 400;
    //line(x0,y0,x1,y1);
    //circle(x1,y1,50);
    //func(1,1,x1,y1,0);
    int page=0;
    int radius = 160;
    int degree1 = 180, degree2 = 165;
    while(degree2 > 10){
        for(int degree = degree1; degree>180-degree2;degree-=5){
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();
            float rad = degree * (3.14159/180);
            float X1 = x0+radius*cos(rad);
            float Y1 = y0+radius*sin(rad);
            setcolor(WHITE);
            line(0, 240, 640, 240);
            line(320, 0, 320, 480);
            line(x0,y0,X1,Y1);
            circle(X1,Y1,50);
            func(1,1,X1,Y1,rad-1.57,WHITE);
            delay(10);
//            setcolor(BLACK);
//            line(x0,y0,X1,Y1);
//            circle(X1,Y1,50);
//            func(1,1,X1,Y1,rad-1.57,BLACK);
            page=1-page;
        }
        degree1-=30;

        for(int degree = 180-degree2; degree<degree1;degree+=5){
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();
            float rad = degree * (3.14159/180);
            float X1 = x0+radius*cos(rad);
            float Y1 = y0+radius*sin(rad);
            setcolor(WHITE);
            line(0, 240, 640, 240);
            line(320, 0, 320, 480);
            line(x0,y0,X1,Y1);
            circle(X1,Y1,50);
            func(1,1,X1,Y1,rad-1.57,WHITE);
            delay(10);
//            setcolor(BLACK);
//            line(x0,y0,X1,Y1);
//            circle(X1,Y1,50);
//            func(1,1,X1,Y1,rad-1.57,BLACK);
             page=1-page;
        }
        degree2-=30;
    }

    setcolor(WHITE);
    line(x0, y0, x1, y1);
    circle(x1, y1, 50);
    func(1,1,x1,y1,0,WHITE);


	getch();
	closegraph();

	return 0;

}


