#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<cmath>

using namespace std;

float tx=120,ty=60,tz=-300;
void FrontsurfaceBanaDo(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4,float px,float py,float pz)
{
    float e1x=x2-x1,e1y=y2-y1,e1z=z2-z1;
    float e2x=x3-x1,e2y=y3-y1,e2z=z3-z1;
    float nx=e1y*e2z-e1z*e2y;
    float ny=e1z*e2x-e1x*e2z;
    float nz=e1x*e2y-e1y*e2x;
    float ex=px-x1,ey=py-y1,ez=pz-z1;
    if(ex*nx+ey*ny+ez*nz>0){
        nx=nx*(-1);
        ny=ny*(-1);
        nz=nz*(-1);
    }
    float cx=(x1+x2+x3+x4)/4,cy=(y1+y2+y3+y4)/4,cz=(z1+z2+z3+z4)/4;
    float lx=cx-tx,ly=cy-ty,lz=cz-tz;
    if(lx*nx+ly*ny+lz*nz<0){
        line(210+x1,240-y1,210+x2,240-y2);
        line(210+x2,240-y2,210+x3,240-y3);
        line(210+x3,240-y3,210+x4,240-y4);
        line(210+x1,240-y1,210+x4,240-y4);
    }
//    else{
//        setlinestyle(1,1,1);
//        line(210+x1,240-y1,210+x2,240-y2);
//        line(210+x2,240-y2,210+x3,240-y3);
//        line(210+x3,240-y3,210+x4,240-y4);
//        line(210+x1,240-y1,210+x4,240-y4);
//        setlinestyle(0,1,1);
//    }
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
void makeCubeFront(float obj[8][4])
{
    FrontsurfaceBanaDo(obj[0][0],obj[0][1],obj[0][2],obj[1][0],obj[1][1],obj[1][2],obj[2][0],obj[2][1],obj[2][2],obj[3][0],obj[3][1],obj[3][2],obj[6][0],obj[6][1],obj[6][2]);
    FrontsurfaceBanaDo(obj[0][0],obj[0][1],obj[0][2],obj[4][0],obj[4][1],obj[4][2],obj[7][0],obj[7][1],obj[7][2],obj[3][0],obj[3][1],obj[3][2],obj[6][0],obj[6][1],obj[6][2]);
    FrontsurfaceBanaDo(obj[1][0],obj[1][1],obj[1][2],obj[5][0],obj[5][1],obj[5][2],obj[6][0],obj[6][1],obj[6][2],obj[2][0],obj[2][1],obj[2][2],obj[7][0],obj[7][1],obj[7][2]);
    FrontsurfaceBanaDo(obj[4][0],obj[4][1],obj[4][2],obj[5][0],obj[5][1],obj[5][2],obj[6][0],obj[6][1],obj[6][2],obj[7][0],obj[7][1],obj[7][2],obj[2][0],obj[2][1],obj[2][2]);
    FrontsurfaceBanaDo(obj[4][0],obj[4][1],obj[4][2],obj[5][0],obj[5][1],obj[5][2],obj[1][0],obj[1][1],obj[1][2],obj[0][0],obj[0][1],obj[0][2],obj[2][0],obj[2][1],obj[2][2]);
    FrontsurfaceBanaDo(obj[7][0],obj[7][1],obj[7][2],obj[6][0],obj[6][1],obj[6][2],obj[2][0],obj[2][1],obj[2][2],obj[3][0],obj[3][1],obj[3][2],obj[1][0],obj[1][1],obj[1][2]);
}
int main()
{
    float pi=3.14159265;
    //float obj[4][4]={100,100,100,0,300,100,100,0,200,100,300,0,200,200,200,0};
    float obj[8][4]={0,120,0,0,
    120,120,0,0,
    120,0,0,0,
    0,0,0,0,
    0,120,120,0,
    120,120,120,0,
    120,0,120,0,
    0,0,120,0};
    //float isometric[4][4]={0.7071,-0.40825,0.7071,0,0,0.8165,0.40825,0,-0.7071,-0.40825,0.8165,0,0,0,0,1};
    //multiply(obj,isometric,8);
    float rotx[4][4]={1,0,0,0,0,cos(pi/180),-1*sin(pi/180),0,0,sin(pi/180),cos(pi/180),0,0,0,0,1};
    float roty[4][4]={cos(pi/180),0,sin(pi/180),0,0,1,0,0,-1*sin(pi/180),0,cos(pi/180),0,0,0,0,1};
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    initwindow(1400,700);
    //float isometric[4][4]={0.7071,0,-0.7071,0,-0.40825,0.8165,-0.40825,0,0.7071,0.40825,0.8165,0,0,0,0,1};
    //multiply(obj,isometric,4);
    for(int theta=0;theta<180;theta++){
        multiply(obj,roty,8);
        setcolor(WHITE);
        makeCubeFront(obj);
        Sleep(200);
        setcolor(BLACK);
        makeCubeFront(obj);
    }
    setcolor(WHITE);
    makeCubeFront(obj);
    getch();
    closegraph();
    return 0;
}

