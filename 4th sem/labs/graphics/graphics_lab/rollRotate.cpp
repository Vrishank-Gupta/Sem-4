#include <bits/stdc++.h>
#include <graphics.h>
#include<math.h>
#define WHITE 0xffffff
#define BLACK 0x000000
#define pi 3.141592

using namespace std;
//draws a circle and rotate it

struct point{
	int x;
	int y;
};


int roundoff(float x)
{
    int a=(int)x;
    if(x-a<0.5)
        return a;
    return a+1;
}

void drawcurve(float p0x,float p0y,float p3x,float p3y,float p0_x,float p0_y,float p1_x,float p1_y,int col,int theta)
{
    for(float t=0;t<=1;t+=0.001){
        float x=(2*t*t*t-3*t*t+1)*p0x+(-2*t*t*t+3*t*t)*p3x+(t*t*t-2*t*t+t)*p0_x+(t*t*t-t*t)*p1_x;
        float y=(2*t*t*t-3*t*t+1)*p0y+(-2*t*t*t+3*t*t)*p3y+(t*t*t-2*t*t+t)*p0_y+(t*t*t-t*t)*p1_y;
        x=x*cos(theta*pi/180);
        putpixel(roundoff(320+x),roundoff(240-y),col);
    }
}

void roll(int color,int theta)
{
	//2
	drawcurve(-275,0,-245,0,10,50,-10,-50,color,theta);//miny = 112
	drawcurve(-245,0,-275,-25,-10,-50,0,-50,color,theta);
	drawcurve(-275,-25,-245,-25,60,60,40,40,color,theta);

	//0

	drawcurve(-210,13,-210,-25,-70,10,70,10,color,theta);
	drawcurve(-210,13,-210,-25,70,10,-70,10,color,theta);

	//1

	drawcurve(-165,13,-165,-25,0,10,0,10,color,theta);
	drawcurve(-165,13,-180,0,-10,-10,-10,-10,color,theta);
	drawcurve(-180,-25,-150,-25,10,0,10,0,color,theta);

	//6

	drawcurve(-115,13,-120,-25,-80,-10,80,-20,color,theta);
	drawcurve(-133,-15,-120,-25,60,70,-70,-10,color,theta);

	//U

	drawcurve(-90,13,-90,-15,0,-10,0,-10,color,theta);
	drawcurve(-90,-15,-60,-15,0,-50,0,50,color,theta);
	drawcurve(-60,13,-60,-15,0,-10,0,-10,color,theta);

	//C

	drawcurve(-15,8,-15,-20,-110,60,110,60,color,theta);

	//O

	drawcurve(15,13,15,-25,-70,10,70,10,color,theta);
	drawcurve(15,13,15,-25,70,10,-70,10,color,theta);

	//1

	drawcurve(60,13,60,-25,0,10,0,10,color,theta);
	drawcurve(60,13,45,0,-10,-10,-10,-10,color,theta);
	drawcurve(45,-25,75,-25,10,0,10,0,color,theta);

	//6

	drawcurve(110,13,105,-25,-80,-10,80,-20,color,theta);
	drawcurve(88,-15,105,-25,60,70,-70,-10,color,theta);

	//4
	drawcurve(155,13,130,-10,5,5,5,5,color,theta);
	drawcurve(155,13,155,-25,0,-10,0,-10,color,theta);
	drawcurve(130,-10,170,-10,10,0,10,0,color,theta);

	//7
	drawcurve(180,13,210,13,5,0,5,0,color,theta);
	drawcurve(210,13,190,-25,-10,-10,-10,-10,color,theta);
}




int main(int argc, char const *argv[])
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int page=0;
    for(int theta=0;theta<=360;theta+=5){
        setactivepage(page);
        setvisualpage(1-page);
        roll(BLACK,theta-10);
        roll(WHITE,theta);
        page=1-page;
    }
	delay(10000);
	closegraph();
	return 0;
}

