#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include "circle.h"
using namespace std;

int main()
{
    int r=360;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    for(int theta=90;theta>=-270;theta--){
        ccircle(r/2,320,240,WHITE);
        ccircle(r/6,320,240,WHITE);
        int xcen1=(r/3)*cos(theta*3.14/180);
        int ycen1=(r/3)*sin(theta*3.14/180);
        int xcen2=(r/3)*cos((theta-180)*3.14/180);
        int ycen2=(r/3)*sin((theta-180)*3.14/180);
        int xcen3=(2*r/5)*cos((theta-90)*3.14/180);
        int ycen3=(2*r/5)*sin((theta-90)*3.14/180);
        int xcen4=(2*r/5)*cos((theta+90)*3.14/180);
        int ycen4=(2*r/5)*sin((theta+90)*3.14/180);
        int xcen5=(r/6)*cos(theta*3.14/180);
        int ycen5=(r/6)*sin(theta*3.14/180);
        int xcen6=(r/6)*cos((theta-180)*3.14/180);
        int ycen6=(r/6)*sin((theta-180)*3.14/180);
        ccircle(r/6,320+xcen1,240-ycen1,WHITE);
        ccircle(r/6,320+xcen2,240-ycen2,WHITE);
        ccircle(r/10,320+xcen3,240-ycen3,WHITE);
        ccircle(r/10,320+xcen4,240-ycen4,WHITE);
        ccircle(r/3,320+xcen5,240-ycen5,WHITE);
        ccircle(r/3,320+xcen6,240-ycen6,WHITE);
        ccircle(r/6,320+xcen1,240-ycen1,BLACK);
        ccircle(r/6,320+xcen2,240-ycen2,BLACK);
        ccircle(r/10,320+xcen3,240-ycen3,BLACK);
        ccircle(r/10,320+xcen4,240-ycen4,BLACK);
        ccircle(r/3,320+xcen5,240-ycen5,BLACK);
        ccircle(r/3,320+xcen6,240-ycen6,BLACK);
    }

    getch();
    closegraph();
    return 0;
}
