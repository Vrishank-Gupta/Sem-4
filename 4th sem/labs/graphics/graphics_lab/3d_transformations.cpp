#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>

using namespace std;

void makecubeFront(int obj[8][4])
{
    for(int i=0;i<4;i++){
        line(319+obj[i][0],120-obj[i][1],319+obj[(i+1)%4][0],120-obj[(i+1)%4][1]);
        line(319+obj[i+4][0],120-obj[i+4][1],319+obj[((i+1)%4)+4][0],120-obj[((i+1)%4)+4][1]);
        line(319+obj[i][0],120-obj[i][1],319+obj[i+4][0],120-obj[i+4][1]);
    }
}

void makecubeSide(int obj[8][4])
{
    for(int i=0;i<4;i++){
        line(106+obj[i][2],120-obj[i][1],106+obj[(i+1)%4][2],120-obj[(i+1)%4][1]);
        line(106+obj[i+4][2],120-obj[i+4][1],106+obj[((i+1)%4)+4][2],120-obj[((i+1)%4)+4][1]);
        line(106+obj[i][2],120-obj[i][1],106+obj[i+4][2],120-obj[i+4][1]);
    }
}

void makecubeTop(int obj[8][4])
{
    for(int i=0;i<4;i++){
        line(522+obj[i][0],120-obj[i][2],522+obj[(i+1)%4][0],120-obj[(i+1)%4][2]);
        line(522+obj[i+4][0],120-obj[i+4][2],522+obj[((i+1)%4)+4][0],120-obj[((i+1)%4)+4][2]);
        line(522+obj[i][0],120-obj[i][2],522+obj[i+4][0],120-obj[i+4][2]);
    }
}

int main()
{

    int obj[8][4]={0,40,0,0,40,40,0,0,40,0,0,0,0,0,0,0,0,40,40,0,40,40,40,0,40,0,40,0,0,0,40,0};
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(213,0,213,480);
    line(426,0,426,480);
    line(0,240,640,240);
    makecubeSide(obj);
    Sleep(1000);
    makecubeFront(obj);
    Sleep(1000);
    makecubeTop(obj);
    Sleep(1000);
    getch();
    closegraph();
    return 0;
}
