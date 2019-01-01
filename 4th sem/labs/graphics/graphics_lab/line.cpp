#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
int round(float x)
{
    int a=(int)x;
    if(x-a<0.5)
        return a;
    return a+1;
}
void mline(int x1,int y1,int x2,int y2,int col)
{
    float m=(float)(y2-y1)/(x2-x1);
    if(m<1){
        float x=min(x1,x2),y=y1;
        putpixel(240+x,320-y,col);
        while(x<=max(x1,x2)){
            x+=1;
            y+=m;
            putpixel(240+x,320-round(y),col);
        }
    }
    else{
        float x=x1,y=min(y1,y2);
        putpixel(240+x,320-y,col);
        while(y<=max(y1,y2)){
            y+=1;
            x+=(1/m);
            putpixel(240+round(x),320-y,col);
        }
    }
}
int main()
{

    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    mline(x1,y1,x2,y2,YELLOW);
    getch();
    closegraph();
    return 0;
}

