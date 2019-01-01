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

void hermite(float p0x,float p0y,float p3x,float p3y,float p0_x,float p0_y,float p1_x,float p1_y)
{
    for(float t=0;t<=1;t+=0.001){
        float x=(2*t*t*t-3*t*t+1)*p0x+(-2*t*t*t+3*t*t)*p3x+(t*t*t-2*t*t+t)*p0_x+(t*t*t-t*t)*p1_x;
        float y=(2*t*t*t-3*t*t+1)*p0y+(-2*t*t*t+3*t*t)*p3y+(t*t*t-2*t*t+t)*p0_y+(t*t*t-t*t)*p1_y;
        putpixel(roundoff(675+x),roundoff(350-y),WHITE);
    }
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    initwindow(1350,700);
    //da
    hermite(-250,100,300,100,50,50,50,50);
    hermite(-150,100,-150,60,10,-10,-10,-10);
    hermite(-150,60,-150,-60,-300,0,300,0);
    hermite(-150,-60,-150,-20,70,0,-70,0);
    hermite(-150,-20,-150,-60,-60,0,50,-60);
    hermite(-150,-60,-120,-100,50,-60,60,-60);
    //ma
    hermite(-50,100,-50,-20,0,-200,-20,-20);
    hermite(-50,-20,-75,10,-40,-20,20,20);
    hermite(-75,10,50,10,10,10,10,10);
    hermite(50,100,50,-100,10,-10,10,-10);
    hermite(200,100,200,-100,10,-10,10,-10);
    //k
    hermite(200,0,100,0,-200,100,-30,-90);
    hermite(100,0,200,0,-50,-150,150,300);
    hermite(200,0,270,0,80,80,60,-60);
    hermite(270,0,230,-100,60,-60,-150,-150);
    getch();
    closegraph();
    return 0;
}


