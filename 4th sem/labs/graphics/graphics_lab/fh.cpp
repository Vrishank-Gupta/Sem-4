#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>
using namespace std;
#define pi =3.14159
#define COS(a) cos((a*pi)/180.0)
#define SIN(a) sin((a*pi)/180.0)
float* crossProduct(float p1x,float p1y,float p1z,float p2x,float p2y,float p2z){

    float ans[3] ;
    ans[0]=p1y*p2z-p2y*p1z;
    ans[1]=p2x*p1z-p1x*p2z;
    ans[2]=p1x*p2y-p1y*p2x;
    return ans;
}

float* rel(float p1x,float p1y,float p1z,float p2x,float p2y,float p2z){
float ans[3] ;
    ans[0]=p2x-p1x;
    ans[1]=p2y-p1y;
    ans[2]=p2z-p1z;
    return ans;
}

int main(){
    float normal[3] = {1,6,3};
    float centerPoint1[3] ={0,1,-1};
    float point2[3] = {6,0,-1};
    float* u = rel(centerPoint1[0],centerPoint1[1],centerPoint1[2],point2[0],point2[1],point2[2]);
    float* v = crossProduct(u[0],u[1],u[2],normal[0],normal[1],normal[2]);
    float modu = sqrt(u[0]*u[0]+u[1]*u[1]+u[2]*u[2]);
    float modv = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);


    float ang =0;
    while(ang<360){
        putpixel(centerPoint1[0]+u[0]*(80/modu)*COS(ang)+v[0]*(40/modv)*SIN(ang),centerPoint1[1]+v[1]*(40/modv)*SIN(ang)+u[0]*(80/modu)*COS(ang));
        ang++;

    }
}
