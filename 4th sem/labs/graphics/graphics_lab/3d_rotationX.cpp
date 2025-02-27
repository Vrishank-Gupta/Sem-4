#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<cmath>

using namespace std;

void makecubeFront(float obj[8][4])
{
    for(int i=0;i<4;i++){
        line(210+obj[i][0],240-obj[i][1],210+obj[(i+1)%4][0],240-obj[(i+1)%4][1]);
        line(210+obj[i+4][0],240-obj[i+4][1],210+obj[((i+1)%4)+4][0],240-obj[((i+1)%4)+4][1]);
        line(210+obj[i][0],240-obj[i][1],210+obj[i+4][0],240-obj[i+4][1]);
    }
}

void multiply(float obj[][4],float trans[4][4], int rows)
{
        float mul[rows][4];
        for(int i=0;i<rows;i++){
            for(int j=0;j<4;j++){
                float sum=0;
                for(int k=0;k<4;k++){
                    sum=sum+(obj[i][k]*trans[k][j]);
                }
                mul[i][j]=sum;
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<4;j++)
                obj[i][j]=mul[i][j];
        }
}

int main()
{
    float pi=3.14159265;
    float obj[8][4]={0,120,0,0,120,120,0,0,120,0,0,0,0,0,0,0,0,120,120,0,120,120,120,0,120,0,120,0,0,0,120,0};
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    float rotx[4][4]={1,0,0,0,0,cos(pi/180),-1*sin(pi/180),0,0,sin(pi/180),cos(pi/180),0,0,0,0,1};
    float roty[4][4]={cos(pi/180),0,sin(pi/180),0,0,1,0,0,-1*sin(pi/180),0,cos(pi/180),0,0,0,0,1};
    float rotz[4][4]={cos(pi/180),-1*sin(pi/180),0,0,sin(pi/180),cos(pi/180),0,0,0,0,1,0,0,0,0,1};
    for(int theta=0;theta<90;theta++){
        multiply(obj,rotx,8);
        setcolor(WHITE);
        makecubeFront(obj);
        Sleep(200);
        setcolor(BLACK);
        makecubeFront(obj);
    }
    for(int theta=0;theta<90;theta++){
        multiply(obj,roty,8);
        setcolor(WHITE);
        makecubeFront(obj);
        Sleep(200);
        setcolor(BLACK);
        makecubeFront(obj);
    }
    for(int theta=0;theta<90;theta++){
        multiply(obj,rotz,8);
        setcolor(WHITE);
        makecubeFront(obj);
        Sleep(200);
        setcolor(BLACK);
        makecubeFront(obj);
    }
    setcolor(WHITE);
    makecubeFront(obj);
    getch();
    closegraph();
    return 0;
}
