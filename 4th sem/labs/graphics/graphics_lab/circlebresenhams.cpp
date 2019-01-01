#include<iostream>
#include<graphics.h>
using namespace std;

void quadrantBanao(int x,int y,int col)
{
    putpixel(320+x,240-y,col);
    putpixel(320+x,240+y,col);
    putpixel(320-x,240-y,col);
    putpixel(320-x,240+y,col);
}

void bresencircle(int r,int col)
{
    int d=2*(1-r);
    int x=0,y=r;
    putpixel(x,y,WHITE);
    while(x>=0&&y>=0){
        if(d<0){
            int t=2*d+2*y-1;
            x++;
            if(t<0){
                d+=2*x+3;
            }
            else{
                y--;
                d+=2*(x-y)+6;
            }
        }
        else if(d>0){
            int t=-2*d+2*x+1;
            y--;
            if(t<0){
                d+=3-2*y;
            }
            else{
                x++;
                d+=2*(x-y)+6;
            }
        }
        else{
            x++;
            y--;
            d+=2*(x-y)+6;
        }
        cout<<x<<' '<<y<<endl;
        quadrantBanao(x,y,col);
    }
}

int main()
{
    int r;
    cin>>r;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    bresencircle(r,WHITE);
    getch();
    closegraph();
    return 0;
}
