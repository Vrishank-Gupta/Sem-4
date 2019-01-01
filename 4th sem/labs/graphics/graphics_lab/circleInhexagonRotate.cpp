#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include<windows.h>
#include "header.h"
using namespace std;


void multiply(float obj[][3],float trans[3][3], int rows,float mul[][3])
{
        for(int i=0;i<rows;i++){
            for(int j=0;j<3;j++){
                float sum=0;
                for(int k=0;k<3;k++){
                    sum=sum+(obj[i][k]*trans[k][j]);
                }
                mul[i][j]=sum;
            }
        }
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    initwindow(1350,700);
    int r=50;
    float vert[7][3]={0,200,1,160,80,1,160,-80,1,0,-200,1,-160,-80,1,-160,80,1,80,0,1};
    int page=0;
    for(int theta=0;theta<=360;theta+=5){
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();


        float trans[3][3]={cos(theta*pi/180),sin(theta*pi/180),0,-sin(theta*pi/180),cos(theta*pi/180),0,0,0,1};
        float mul[7][3];
        multiply(vert,trans,7,mul);

        for(int i=0;i<6;i++){
            bresenline(mul[i][0],mul[i][1],mul[(i+1)%6][0],mul[(i+1)%6][1],1350,700,WHITE);
        }
        bresencircle(r,1350,700,mul[6][0],mul[6][1],WHITE);
        Sleep(100);
        page=1-page;
    }
    getch();
    closegraph();
    return 0;
}






