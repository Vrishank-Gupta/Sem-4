#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
//#include "graphicss.h"
#define pi 3.14159
#define COS(a) cos((a*pi)/180.0)
#define SIN(a) sin((a*pi)/180.0)
using namespace std;

void midLine(int x1,int y1,int x2,int y2,int ang =0,int col=15,int l=1270,int b=650)
{
    int m=1;
    int x=x1,y=y1;
    int dx=x2-x1,dy=y2-y1;
    if(abs(y2-y1)<abs(x2-x1))
    {
        if(x2<x1)
            x=x2,y=y2,dx=x1-x2,dy=y1-y2;
        if(dy<0)
            dy=-dy,y=-y,m=-1;
        int d=dx-(dy<<1);
        while(x<=std::max(x1,x2))
        {
            putpixel((l>>1)+x*COS(ang)-m*y*SIN(ang),(b>>1)-m*y*COS(ang)-x*SIN(ang),col);
            if(d<0)
                y++,d+=(dx<<1)-(dy<<1);
            else
                d-=(dy<<1);
            x++;
        }
    }
    else
    {
        if(y2<y1)
            x=x2,y=y2,dx=x1-x2,dy=y1-y2;
        if(dx<0)
            dx=-dx,x=-x,m=-1;
        int d=dy-(dx<<1);
        while(y<=std::max(y1,y2))
        {
            putpixel((l>>1)+m*x*COS(ang)-y*SIN(ang),(b>>1)-y*COS(ang)-m*x*SIN(ang),col);
            if(d<0)
                x++,d+=(dy<<1)-(dx<<1);
            else
                d-=(dx<<1);
            y++;
        }
    }
}

void drawOne(float start_x,float start_y,float ang)
{
    midLine(start_x-200,start_y+100,start_x-190,start_y+100,ang);
    midLine(start_x-200,start_y+100,start_x-200,start_y+50,ang);
    midLine(start_x-200,start_y+50,start_x-190,start_y+50,ang);
    midLine(start_x-190,start_y+50,start_x-190,start_y+100,ang);
}
void drawSix(float start_x,float start_y,float ang)
{
    midLine(start_x-180,start_y+100,start_x-150,start_y+100,ang);
    midLine(start_x-150,start_y+90,start_x-150,start_y+100,ang);
    midLine(start_x-150,start_y+90,start_x-170,start_y+90,ang);
    midLine(start_x-170,start_y+90,start_x-170,start_y+70,ang);
    midLine(start_x-150,start_y+70,start_x-170,start_y+70,ang);
    midLine(start_x-150,start_y+50,start_x-150,start_y+70,ang);
    midLine(start_x-180,start_y+50,start_x-150,start_y+50,ang);
    midLine(start_x-180,start_y+100,start_x-180,start_y+50,ang);


    midLine(start_x-155,start_y+55,start_x-170,start_y+55,ang);
    midLine(start_x-170,start_y+65,start_x-170,start_y+55,ang);
    midLine(start_x-155,start_y+65,start_x-155,start_y+55,ang);
    midLine(start_x-155,start_y+65,start_x-170,start_y+65,ang);

//    midLine(start_x-200,start_y+50,start_x-190,start_y+50,ang);
//    midLine(start_x-190,start_y+50,start_x-190,start_y+100,ang);
}
void drawEight(float start_x,float start_y,float ang)
{
    midLine(start_x-140,start_y+100,start_x-110,start_y+100,ang);
    midLine(start_x-110,start_y+50,start_x-110,start_y+100,ang);
    midLine(start_x-140,start_y+50,start_x-140,start_y+100,ang);
    midLine(start_x-110,start_y+50,start_x-140,start_y+50,ang);

    midLine(start_x-135,start_y+97,start_x-115,start_y+97,ang);
    midLine(start_x-115,start_y+78,start_x-115,start_y+97,ang);
    midLine(start_x-135,start_y+78,start_x-135,start_y+97,ang);
    midLine(start_x-115,start_y+78,start_x-135,start_y+78,ang);

    midLine(start_x-135,start_y+72,start_x-115,start_y+72,ang);
    midLine(start_x-115,start_y+53,start_x-115,start_y+72,ang);
    midLine(start_x-135,start_y+53,start_x-135,start_y+72,ang);
    midLine(start_x-115,start_y+53,start_x-135,start_y+53,ang);

//    midLine(start_x-200,start_y+50,start_x-190,start_y+50,ang);
//    midLine(start_x-190,start_y+50,start_x-190,start_y+100,ang);
}
void drawSeven(float start_x,float start_y,float ang)
{
    midLine(start_x-100,start_y+100,start_x-70,start_y+100,ang);
    midLine(start_x-100,start_y+100,start_x-100,start_y+90,ang);
    midLine(start_x-70,start_y+100,start_x-70,start_y+90,ang);
    midLine(start_x-100,start_y+90,start_x-80,start_y+90,ang);
    midLine(start_x-100,start_y+50,start_x-80,start_y+90,ang);
    midLine(start_x-90,start_y+50,start_x-70,start_y+90,ang);
    midLine(start_x-90,start_y+50,start_x-100,start_y+50,ang);
//    midLine(start_x-200,start_y+100,start_x-200,start_y+50,ang);
//    midLine(start_x-200,start_y+50,start_x-190,start_y+50,ang);
//    midLine(start_x-190,start_y+50,start_x-190,start_y+100,ang);
}
void drawNumber(int start_x,int start_y,float ang)
{
    drawOne(start_x,start_y,ang);
    drawSix(start_x,start_y,ang);
    drawEight(start_x,start_y,ang);
    drawSeven(start_x,start_y,ang);
}
void drawSeeSaw(float start_x,float start_y,float ang)
{
    midLine(start_x-200,start_y+0,start_x+200,start_y+0,ang);
    midLine(start_x-200,start_y+20,start_x+200,start_y+20,ang);
    midLine(start_x-200,start_y+0,start_x-200,start_y+20,ang);
    midLine(start_x+200,start_y+0,start_x+200,start_y+20,ang);
}
void drawLegs1(float start_x,float start_y,float ang)
{
    midLine(start_x-200,start_y+48,start_x-190,start_y+48,ang);
    midLine(start_x-195,start_y+48,start_x-190,start_y+38,ang);
    midLine(start_x-195,start_y+48,start_x-200,start_y+38,ang);
//                midLine(start_x-195,start_y+48,start_x-200,start_y+38,ang);



    midLine(start_x-180,start_y+48,start_x-150,start_y+48,ang);
    midLine(start_x-165,start_y+48,start_x-150,start_y+38,ang);
    midLine(start_x-165,start_y+48,start_x-180,start_y+38,ang);

    midLine(start_x-140,start_y+48,start_x-110,start_y+48,ang);
    midLine(start_x-125,start_y+48,start_x-110,start_y+38,ang);
    midLine(start_x-125,start_y+48,start_x-140,start_y+38,ang);

    midLine(start_x-100,start_y+48,start_x-90,start_y+48,ang);
    midLine(start_x-95,start_y+48,start_x-90,start_y+38,ang);
    midLine(start_x-95,start_y+48,start_x-100,start_y+38,ang);
}
void drawLegs2(float start_x,float start_y,float ang)
{
    midLine(start_x-200,start_y+48,start_x-190,start_y+48,ang);
    midLine(start_x-197,start_y+48,start_x-193,start_y+38,ang);
    midLine(start_x-193,start_y+48,start_x-198,start_y+38,ang);
//                midLine(start_x-195,start_y+48,start_x-200,start_y+38,ang);



    midLine(start_x-180,start_y+48,start_x-150,start_y+48,ang);
    midLine(start_x-170,start_y+48,start_x-155,start_y+38,ang);
    midLine(start_x-160,start_y+48,start_x-175,start_y+38,ang);

    midLine(start_x-140,start_y+48,start_x-110,start_y+48,ang);
    midLine(start_x-130,start_y+48,start_x-115,start_y+38,ang);
    midLine(start_x-120,start_y+48,start_x-135,start_y+38,ang);

    midLine(start_x-100,start_y+48,start_x-90,start_y+48,ang);
    midLine(start_x-97,start_y+48,start_x-93,start_y+38,ang);
    midLine(start_x-93,start_y+48,start_x-98,start_y+38,ang);
}
void drawSeeSawTri(float start_x,float start_y,float ang)
{
    midLine(start_x,start_y,start_x-50,start_y-50,ang);
    midLine(start_x,start_y,start_x+50,start_y-50,ang);
    midLine(start_x+50,start_y-50,start_x-50,start_y-50,ang);
//    midLine(start_x+200,start_y+0,start_x+200,start_y+20,ang);
}


int main()
{
    int gm,gd=DETECT;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    initwindow(1270,650);
    drawSeeSaw(0,0,0);
    drawNumber(0,0,0);
//    drawLegs2(0,0,0);
    float ang =20;
    int page = 0;
    int strtx=0,strty=-20;

    while(ang>=-20)
    {

        setactivepage(page);
        setvisualpage(1-page);
        page=1-page;
        cleardevice();
    drawSeeSawTri(0,0,0);
        if(strty>-20)
        {
            strty--;
        }
        else
        {
            strty++;
        }
        strtx+=7;
        drawNumber(strtx,strty,ang);
        drawLegs1(strtx,strty,ang);
        drawSeeSaw(0,0,ang);
        ang=ang-1;
        delay(50);
        setactivepage(page);
        setvisualpage(1-page);
        page=1-page;
        cleardevice();
            drawSeeSawTri(0,0,0);
        if(strty>-20)
        {
            strty--;
        }
        else
        {
            strty++;
        }
        strtx+=7;

    drawNumber(strtx,strty,ang);
    drawLegs2(strtx,strty,ang);
    drawSeeSaw(0,0,ang);
    ang=ang-1;
    delay(50);
    }
    cout<<strty;
//    cout<<ang;
    while(ang<20)
    {

        setactivepage(page);
        setvisualpage(1-page);

        cleardevice();
            drawSeeSawTri(0,0,0);
        page=1-page;
//            strty++;
        if(strty<-20)
        {
            strty++;
        }
        else
        {
            strty--;
        }
        strtx-=7;
        drawNumber(strtx,strty,ang);
        drawLegs1(strtx,strty,ang);
        drawSeeSaw(0,0,ang);
        ang=ang+1;
        delay(50);
        setactivepage(page);
        setvisualpage(1-page);
        page=1-page;
        cleardevice();
            drawSeeSawTri(0,0,0);
            if(strty<-20)
        {
            strty++;
        }
        else
        {
            strty--;
        }
            strty++;
        strtx-=7;

    drawNumber(strtx,strty,ang);
    drawLegs2(strtx,strty,ang);
    drawSeeSaw(0,0,ang);
    ang=ang+1;
    delay(50);
    }

    getch();
    closegraph();
}
