
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include<windows.h>
#include "line.h"
using namespace std;


void ssquare(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,int col)
{
    mline(x1,y1,x2,y2,col);
    mline(x3,y3,x4,y4,col);
    mline(x4,y4,x1,y1,col);
    mline(x3,y3,x2,y2,col);
}
int main()
{
    int r,l;
    float pi=3.14159265;
    cin>>r;
    l=r/8;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    mline(-20,-40,0,0,WHITE);
    mline(0,0,20,-40,WHITE);
    mline(-20,-40,20,-40,WHITE);
    while(1){
        for(int theta=-15;theta<15;){
            float x1,x2,y1,y2,sx1,sx2,sx3,sx4,sy1,sy2,sy3,sy4;
            x1=-r*cos(theta*pi/180)/2;
            y1=-r*sin(theta*pi/180)/2;
            x2=r*cos(theta*pi/180)/2;
            y2=r*sin(theta*pi/180)/2;
            sx4=(-(r*(float)theta/30)-l/2)*cos(theta*pi/180);
            sy4=(-(r*(float)theta/30)-l/2)*sin(theta*pi/180);
            sx3=sx4+l*cos(theta*pi/180);
            sy3=sy4+l*sin(theta*pi/180);
            sx1=sx4-l*sin(theta*pi/180);
            sy1=sy4+l*cos(theta*pi/180);
            sx2=sx3-l*sin(theta*pi/180);
            sy2=sy3+l*cos(theta*pi/180);
            mline(x1,y1,x2,y2,WHITE);
            ssquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4,WHITE);
            Sleep(500);
            mline(x1,y1,x2,y2,BLACK);
            ssquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4,BLACK);
            theta+=1;
        }
        for(int theta=15;theta>-15;){
            float x1,x2,y1,y2,sx1,sx2,sx3,sx4,sy1,sy2,sy3,sy4;
            x1=-r*cos(theta*pi/180)/2;
            y1=-r*sin(theta*pi/180)/2;
            x2=r*cos(theta*pi/180)/2;
            y2=r*sin(theta*pi/180)/2;
            sx4=(-(r*(float)theta/30)-l/2)*cos(theta*pi/180);
            sy4=(-(r*(float)theta/30)-l/2)*sin(theta*pi/180);
            sx3=sx4+l*cos(theta*pi/180);
            sy3=sy4+l*sin(theta*pi/180);
            sx1=sx4-l*sin(theta*pi/180);
            sy1=sy4+l*cos(theta*pi/180);
            sx2=sx3-l*sin(theta*pi/180);
            sy2=sy3+l*cos(theta*pi/180);
            mline(x1,y1,x2,y2,WHITE);
            ssquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4,WHITE);
            Sleep(500);
            mline(x1,y1,x2,y2,BLACK);
            ssquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4,BLACK);
            theta-=1;
        }
    }
    closegraph();
    return 0;
}

