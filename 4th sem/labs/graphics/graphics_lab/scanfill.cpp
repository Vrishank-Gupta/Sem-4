#include <iostream>
using namespace std;
#include <conio.h>
#include <graphics.h>
#include <algorithm>
#include"header.h"


void scanfill(point* vertices,int n,int col=15)
{
    float slope[20];
    int xi[20];
    int i,j,x,y,temp,k,dy,dx,min=INT_MAX,max=INT_MIN;

    for(int i=0;i<n;i++){
        if(vertices[i].y<min)
            min=vertices[i].y;
        if(vertices[i].y>max)
            max=vertices[i].y;
    }

    for(i=0; i<n; i++)
    {
        dy=vertices[(i+1)%n].y-vertices[i].y;
        dx=vertices[(i+1)%n].x-vertices[i].x;

        if(dy==0) slope[i]=1.0;
        if(dx==0) slope[i]=0.0;

        if((dy!=0)&&(dx!=0)) /*- calculate inverse slope -*/
        {
            slope[i]=(float) dx/dy;
        }
    }

    for(y=min; y<=max; y++)
    {
        k=0;
        for(i=0; i<n; i++)
        {

            if( ((vertices[i].y<=y)&&(vertices[(i+1)%n].y>y))||
                    ((vertices[i].y>y)&&(vertices[(i+1)%n].y<=y)))
            {
                xi[k]=(int)(vertices[i].x+slope[i]*(y-vertices[i].y));
                k++;
            }
        }

        sort(xi,xi+k);

        setcolor(35);
        for(i=0; i<k; i+=2)
        {
            bresenline(xi[i],y,xi[i+1]+1,y,1350,700,col);
        }

    }
}

int main()
{

    int n,tempx,tempy;
    point vertices[20];


//clrscr();
    cout<<"Enter the no. of edges of polygon : ";
    cin>>n;
    cout<<"Enter the cordinates of polygon : \n";

    for(int i=0; i<n; i++)
    {
        cin>>vertices[i].x>>vertices[i].y;
    }


    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    initwindow(1350,700);


    /*- draw polygon -*/

    for(int i=0;i<n;i++)
    {
    bresenline(vertices[i].x,vertices[i].y,vertices[(i+1)%n].x,vertices[(i+1)%n].y,1350,700,WHITE);
    }
    scanfill(vertices,n);
    getch();
    return 0;

}
