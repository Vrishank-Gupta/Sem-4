#include<iostream>
#include<graphics.h>
#include"line.h"
#define LEFT 0x1
#define BOTTOM 0x2
#define RIGHT 0x4
#define TOP 0x8
using namespace std;
float xmin,ymin,xmax,ymax;
class point{
public:
    int x;
    int y;
};

int gencode(point p)
{
    int code=0x0;
    if(p.x<xmin)
        code|=LEFT;
    if(p.x>xmax)
        code|=RIGHT;
    if(p.y<ymin)
        code|=BOTTOM;
    if(p.y>ymax)
        code|=TOP;
    return code;
}


point func(int code, point p1,point p2)
{
    point in;
    float x,y;
    int a=LEFT&code,b=BOTTOM&code,c=RIGHT&code,d=TOP&code;
    if(a!=0x0){
        x=xmin;
        y=p1.y + (float)(p2.y-p1.y)*(xmin-p1.x)/(p2.x-p1.x);
    }
    if(b!=0){
        y=ymin;
        x=p1.x +(float)(p2.x-p1.x)*(ymin-p1.y)/(p2.y-p1.y);
    }
    if(c!=0){
        x=xmax;
        y=p1.y + (float)(p2.y-p1.y)*(xmax-p1.x)/(p2.x-p1.x);
    }
    if( d!=0x0){
        y=ymax;
        x=p1.x +(float)(p2.x-p1.x)*(ymax-p1.y)/(p2.y-p1.y);
    }
    in.x=(int)x;
    in.y=(int)y;
    return in;

}
int main()
{
    cin>>xmin>>ymin>>xmax>>ymax;
    point p1,p2,pp1,pp2;
    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    pp1.x=p1.x,pp1.y=p1.y,pp2.x=p2.x,pp2.y=p2.y;
    bool done=false;
    while(true){
        int code1=gencode(p1);
        int code2=gencode(p2);
        int andc=code1&code2;
        int orc=code1|code2;
        if((andc==0x0 )&&(orc==0x0)){
            done=true;
            break;
        }
        else if(andc!=0){
            break;
        }
        else if((andc==0x0) && (orc!=0x0)){
            if(gencode(p1)!=0x0){
                point temp=func(code1,p1,p2);
                p1.x=temp.x;
                p1.y=temp.y;

            }
            else if(gencode(p2)!=0x0){
                point temp=func(code2,p1,p2);
                p2.x=temp.x;
                p2.y=temp.y;
            }
        }
    }
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    mline(xmin,ymin,xmin,ymax,WHITE);
    mline(xmin,ymin,xmax,ymin,WHITE);
    mline(xmax,ymin,xmax,ymax,WHITE);
    mline(xmin,ymax,xmax,ymax,WHITE);
    mline(pp1.x,pp1.y,pp2.x,pp2.y,RED);
    if(done)
        mline(p1.x,p1.y,p2.x,p2.y,YELLOW);
    getch();
    closegraph();
    return 0;
}
