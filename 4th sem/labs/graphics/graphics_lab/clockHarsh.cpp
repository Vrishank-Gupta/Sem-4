#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

struct point
{
    int x,y;
};


bool cross ( float x1 , float y1 , float x2 , float y2)
{
    int prd = x1*y2 - y1*x2 ;

    if ( prd >= 0)
        return true;
    else
        return false;
}

void curve ( point p0, point p1, float rx0, float ry0, float rx1, float ry1, float rad, float m, float n, int cx, int cy,float X1,float Y1,float X2,float Y2,float X3,float Y3)
{
    float x,y,t,X,Y,x1,y1;


    for ( t = 0 ; t <= 1.0 ; t = t + 0.01 )
    {
        x = ( 2*t*t*t - 3*t*t + 1 )*p0.x + (-1*2*t*t*t + 3*t*t)*p1.x + ( t*t*t - 2*t*t + t)*rx0 + ( t*t*t - t*t )*rx1;
        y = ( 2*t*t*t - 3*t*t + 1 )*p0.y + (-1*2*t*t*t + 3*t*t)*p1.y + ( t*t*t - 2*t*t + t)*ry0 + ( t*t*t - t*t )*ry1;

        X =  x*cos(rad) - y*sin(rad);
        Y =  x*sin(rad) + y*cos(rad);
        x1 = cx+X*m ;
        y1 = cy+Y*n ;

        if ( cross(X2-X1,Y2-Y1,x1-X1,y1-Y1) == TRUE  &&  cross(X3-X2,Y3-Y2,x1-X2,y1-Y2)==TRUE
             && cross(X1-X3,Y1-Y3,x1-X3,y1-Y3)==TRUE )
                 putpixel(x1,y1,BLACK);
        else putpixel(x1,y1,WHITE);
    }

}

void func(float m, float n,int cx, int cy, float rd,float X1,float Y1,float X2,float Y2,float X3,float Y3)
{
    //1
    point p0,p1;
    int k;
    p0.x = 400;
    p0.y = 100;

    p1.x = 400;
    p1.y = 160;

    curve(p0,p1,0,10,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    //6
    p0.x = 430;
    p0.y = 100;

    p1.x = 410;
    p1.y = 130;

    curve(p0,p1,-50,0,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    p0.x = 410;
    p0.y = 130;

    p1.x = 430;
    p1.y = 160;

    curve(p0,p1,0,-10,50,0,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

     p0.x = 430;
    p0.y = 160;

    p1.x = 450;
    p1.y = 130;

    curve(p0,p1,50,0,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    p0.x = 450;
    p0.y = 130;

    p1.x = 410;
    p1.y = 130;

    curve(p0,p1,0,-50,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    //6

    p0.x = 480;
    p0.y = 100;

    p1.x = 460;
    p1.y = 130;

    curve(p0,p1,-50,0,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    p0.x = 460;
    p0.y = 130;

    p1.x = 480;
    p1.y = 160;

    curve(p0,p1,0,-10,50,0,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

     p0.x = 480;
    p0.y = 160;

    p1.x = 500;
    p1.y = 130;

    curve(p0,p1,50,0,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    p0.x = 500;
    p0.y = 130;

    p1.x = 460;
    p1.y = 130;

    curve(p0,p1,0,-50,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    //4

    p0.x = 550;
    p0.y = 100;

    p1.x = 550;
    p1.y = 160;

    curve(p0,p1,0,10,0,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    p0.x = 550;
    p0.y = 100;

    p1.x = 510;
    p1.y = 140;

    curve(p0,p1,4,10,5,10,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);

    p0.x = 510;
    p0.y = 140;

    p1.x = 555;
    p1.y = 140;

    curve(p0,p1,10,0,10,0,rd,m,n,cx,cy,X1,Y1,X2,Y2,X3,Y3);
}






int main(){
    int gd = DETECT,gm;

    initgraph(&gd,&gm,"C:/TC/BGI");

    float fixptx = 320.0;
    float fixpty = 240.0;

    //func(0.6,0.6,200,300,0.0);

    for(float i = -1.57;i<1.5*3.14;i+= 3.14/36){
        circle(fixptx,fixpty,100);

        //int x = 100*cos(i);
        //int y = 100*sin(i);

       //line(fixptx,fixpty,fixptx+x,fixpty+y);
        int x1 = 325.0,y1 = 240.0,x2 = 315.0,y2 = 240.0,x3 = 320.0,y3 = 140.0;
        float X1,X2,X3,Y1,Y2,Y3;

        x1 -= 320.0;
        x2 -= 320.0;
        x3 -= 320.0;

        y1 -= 240.0;
        y2 -= 240.0;
        y3 -= 240.0;

        X1 = x1*cos(i) - y1*sin(i);
        Y1 = x1*sin(i) + y1*cos(i);

        X2 = x2*cos(i) - y2*sin(i);
        Y2 = x2*sin(i) + y2*cos(i);

        X3 = x3*cos(i) - y3*sin(i);
        Y3 = x3*sin(i) + y3*cos(i);


        X1 += 320.0;
        X2 += 320.0;
        X3 += 320.0;

        Y1 += 240.0;
        Y2 += 240.0;
        Y3 += 240.0;

        func(0.6,0.6,50,170,0.0,X1,Y1,X2,Y2,X3,Y3);

      //  clipping(X1,Y1,X2,Y2,X3,Y3);

        line(X1,Y1,X2,Y2);
        line(X1,Y1,X3,Y3);
        line(X2,Y2,X3,Y3);


        delay(50);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
