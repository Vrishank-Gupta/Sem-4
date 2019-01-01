#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <dos.h>
#define PI      3.1416
#define COS(a)  cos((a*PI)/((float)180))
#define SIN(a)  sin((a*PI)/((float)180))

void printRoll(int,int,int);

struct point
{
int x,y;
};

void curve (point p0, point p1, float rx0, float ry0, float rx1, float ry1,int xcc,int ycc, int rad)
{

	p0.x/=4;
    p0.y/=4;
    p1.x/=4;
    p1.y/=4;
    rx0/=4;
    ry0/=4;
    rx1/=4;
    ry1/=4;

	float x,y,t,X,Y;
    int xc = getmaxx()/2, yc = getmaxy()/2;
    for ( t = 0 ; t <= 1.0 ; t = t + 0.001 )
    {
	x = ( 2*t*t*t - 3*t*t + 1 )*p0.x + (-1*2*t*t*t + 3*t*t)*p1.x + ( t*t*t - 2*t*t + t)*rx0 + ( t*t*t - t*t )*rx1;
	y = ( 2*t*t*t - 3*t*t + 1 )*p0.y + (-1*2*t*t*t + 3*t*t)*p1.y + ( t*t*t - 2*t*t + t)*ry0 + ( t*t*t - t*t )*ry1;

	 X = x*COS(rad) - y*SIN(rad);
	 Y = x*SIN(rad) + y*COS(rad);

	putpixel(xc+X-200,yc-Y-50,WHITE);
    }
}

void print(float toPrint[4][3],int columns, int ang){

    int i,j;
    int yc = getmaxy()/2,xc=getmaxx()/2;
    // cout<<xc<<" "<<yc;
    for(i=0;i<columns-1;i++){
	line(xc + toPrint[0][i],yc - toPrint[1][i],xc + toPrint[0][i+1],yc - toPrint[1][i+1]);
    }
    line(xc + toPrint[0][i],yc - toPrint[1][i],xc + toPrint[0][0],yc - toPrint[1][0]);

    printRoll(xc + toPrint[0][i],yc - toPrint[1][i], ang);
}

void printRoll(int xc, int yc, int ang) {
	//1
    point p0,p1;
    p0.x = -100;
    p0.y = 100;

    p1.x = -100;
    p1.y = -100;


    curve(p0,p1,0,-10,0,-10,xc,yc,ang);

    p0.x = -125;
    p0.y = 60;

    p1.x = -125;
    p1.y = -100;


    curve(p0,p1,0,-10,0,-10,xc,yc,ang);

    p0.x = -125;
    p0.y = -100;

    p1.x = -100;
    p1.y = -100;

    curve(p0,p1,10,0,10,0,xc,yc,ang);

    p0.x = -100;
    p0.y = 100;

    p1.x = -150;
    p1.y = 80;

    curve(p0,p1,-20,-10,-20,-10,xc,yc,ang);

    p0.x = -125;
    p0.y = 60;

    p1.x = -140;
    p1.y = 55;

    curve(p0,p1,-15,-5,-15,-5,xc,yc,ang);

    p0.x = -150;
    p0.y = 80;

    p1.x = -140;
    p1.y = 55;

    curve(p0,p1,10,-25,10,-25,xc,yc,ang);

    //6
    p0.x = 0;
    p0.y = 90;

    p1.x = -80;
    p1.y = 0;


    curve(p0,p1,-120,80,20,-200,xc,yc,ang);

    p0.x = 0;
    p0.y = 90;

    p1.x = -20;
    p1.y = 70;


    curve(p0,p1,-50,-50,-50,-50,xc,yc,ang);

    p0.x = -80;
    p0.y = 0;

    p1.x = -10;
    p1.y = -100;

    curve(p0,p1,0,-100,200,50,xc,yc,ang);
}



void printsq(float toPrint[4][4], int columns){

int i,j;
    int yc = getmaxy()/2,xc=getmaxx()/2;
    // cout<<xc<<" "<<yc;
    for(i=0;i<columns-1;i++){
	line(xc + toPrint[0][i],yc - toPrint[1][i],xc + toPrint[0][i+1],yc - toPrint[1][i+1]);
    }

    line(xc + toPrint[0][i],yc - toPrint[1][i],xc + toPrint[0][0],yc - toPrint[1][0]);
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"c:/TC/BGI");

    int xc = getmaxx()/2, yc = getmaxy()/2;



    float square[4][4] = {{200,200,-200,-200},
			 {10,-10,-10,10},
			 {0,0,0,0},
			 {1,1,1,1}};

	float triangle[4][3] = {{0,-30,30},
							 {0,-30,-30},
							 {0,0,0},
							 {1,1,1}};


	int flag=0,xlimit=20;
	for(int ang=0; !kbhit(); ){

	    if(!flag)
	    ang++;

	    else
	    ang--;

	    if(ang>xlimit) {

		flag=!flag;

	    }

	    if(ang<-xlimit){

		flag=!flag;
		}

	 float rotx[4][4] = {{1,0,0,0},
					     {0,COS(ang),-SIN(ang),0},
					     {0,SIN(ang),COS(ang),0},
					     {0,0,0,1}};

	 float roty[4][4] = {{COS(ang),0,SIN(ang),0},
						     {0,1,0,0},
						     {-SIN(ang),0,COS(ang),0},
						     {0,0,0,1}};

    float rotz[4][4] = {{COS(ang),-SIN(ang),0,0},
							{SIN(ang),COS(ang),0,0},
							{0,0,1,0},
							{0,0,0,1}};

  //	line(xc,0,xc,yc*2);
  //	line(0,yc,xc*2,yc);


	float sqpts[4][4];


	for (int i = 0; i<4; i++) {
	    for (int j = 0; j<4; j++) {
		int sum = 0;
		for (int k = 0; k<4; k++) {
		    sum += rotz[i][k] * square[k][j];
		}
		sqpts[i][j] = sum;
	    }
	}
	print(triangle,3,ang);
	printsq(sqpts,4);

	delay(25);
	cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
