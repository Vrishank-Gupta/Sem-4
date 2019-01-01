#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
void bresenline(int x1,int y1,int x2,int y2,int col)
{
    if(abs(y2-y1)<abs(x2-x1)){
        int m=1;
        float slope=(float)(y2-y1)/(x2-x1);
        if(slope<0)
            m=-1;
        y1*=m;
        y2*=m;
        int x=x1,y=y1;
        int dx=x2-x1,dy=y2-y1;
        if(x2<x1){
            x=x2,y=y2;
            dx=x1-x2,dy=y1-y2;
        }
        int d=dx-2*dy;
        putpixel(320+x,240-m*y,col);
        while(x<=max(x1,x2)){
            if(d<0){
                y+=1;
                d+=2*dx-2*dy;
            }
            else{
                d-=2*dy;
            }
            x++;
            putpixel(320+x,240-m*y,col);
        }
    }
    else{
        int m=1;
        float slope=(float)(y2-y1)/(x2-x1);
        if(slope<0)
            m=-1;
        x1*=m;
        x2*=m;
        int dx=x2-x1,dy=y2-y1;
        int x=x1,y=y1;
        if(y2<y1){
            x=x2,y=y2;
            dx=x1-x2,dy=y1-y2;
        }

        int d=dy-2*dx;
        putpixel(320+m*x,240-y,col);
        while(y<=max(y1,y2)){
            if(d<0){
                x+=1;
                d+=2*dy-2*dx;
            }
            else{
                d-=2*dx;
            }
            y++;
            putpixel(320+m*x,240-y,col);
        }
    }
}
int main()
{
    int x1,x2,y1,y2,c;
    cin>>x1>>y1>>x2>>y2;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    bresenline(x1,y1,x2,y2,WHITE);
    getch();
    closegraph();
    return 0;
}
