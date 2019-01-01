#include <graphics.h>
#include<math.h>
#include <iostream>
#define PI 3.141593

using namespace std;

//for drawing line using mid-point algorithm which handles all the cases void line_mpt (int x1, int y1, int x2, int y2, int color = WHITE) {

struct point{
    double x, y;
    point(double x, double y){
        this->x=x;
        this->y=y;
    }
};

struct translateConfig{
    double x, y;
} T, Tno;

struct rotateConfig{
    double x, y;
    double theta;
} R, Rno;

colors colorConfig = WHITE;
double scaleConfig = 1;


point model_retpixel(double x, double y){
    double window_x,window_y;

    x += Tno.x;
    x += Tno.y;

    x -= R.x;
    y -= R.y;

    window_x = x*cos(R.theta) - y*sin(R.theta);
    window_y = x*sin(R.theta) + y*cos(R.theta);

    window_x += R.x;
    window_y += R.y;

    window_x *= scaleConfig;
    window_y *= scaleConfig;

    return point(window_x+T.x, window_y+T.y);
}


void line_mpt (int x1, int y1, int x2, int y2) {

    int dx = abs(x2 - x1), dy = abs(y2 - y1), xsign, ysign;
    bool compare;
    if (abs (x2 - x1) > abs (y2 - y1)) {	//major moment in x
        if ((x2 - x1) * (y2 - y1) > 0) {	//slope is +ve: mx - y + c = 0
            xsign = -1, ysign = 1, compare = 1;
            if (x1 > x2) {
            swap(x1, x2);	swap(y1, y2);
            }
        }else {	//slope is -ve: y + mx - c = 0
            xsign = 1, ysign = -1, compare = 0;
            if (x1 < x2) {
            swap(x1, x2);	swap(y1, y2);
            }
        }

        int x = x1, y = y1;
        int del = (dy * ysign) + (dx * xsign) / 2;
        point tmppt = model_retpixel(x,y);
        putpixel(tmppt.x,tmppt.y, colorConfig);
        while (x != x2) {
        x -= xsign;
        if ((compare ? del < 0 : del > 0)) {
        del += (dy * ysign);
        }

        else {
        del += ((dy * ysign) + (dx * xsign));
        y++;
        }

        point tmppt = model_retpixel(x,y);
        putpixel(tmppt.x,tmppt.y, colorConfig);

        }
    }

    else {	//major moment in y
        if ((x2 - x1) * (y2 - y1) > 0) {	//slope is +ve: mx - y + c = 0
            xsign = -1, ysign = 1, compare = 1;
            if (x1 > x2) {
            swap(x1, x2);	swap(y1, y2);
            }
        }else {	//slope is -ve: y + mx - c = 0
            xsign = 1, ysign = -1, compare = 0;
            if (x1 < x2) {
            swap(x1, x2);	swap(y1, y2);
            }
        }
        int x = x1, y = y1;
        int del = (dx * xsign) + (dy * ysign) / 2;
        point tmppt = model_retpixel(x,y);
        putpixel(tmppt.x,tmppt.y, colorConfig);
        while (y != y2) {
        y ++;
        if ((compare ? del > 0 : del < 0)) {
        del += (dx * xsign);
        }
        else {
        del += ((dx * xsign) + (dy * ysign));
        x -= xsign;
        }
        point tmppt = model_retpixel(x,y);
        putpixel(tmppt.x,tmppt.y, colorConfig);
        }

    }

}

void rollNo(){
    //Baseline at 30
    line_mpt(5,14,  5,40);
    line_mpt(5,14,-2,14);
    line_mpt(-2,14,15,0);
    line_mpt(15,0,   15,40);
    line_mpt(5,40,15,40);

    //Spans till 15, 40;


    //Starts at 30, spans till 40,40
    line_mpt(30,0,30,40);
    line_mpt(30,0,50,0);
    line_mpt(40,10,50,10);//, RED);
    line_mpt(40,10,40,20);
    line_mpt(40,20,50,20);//, RED);
    line_mpt(50,20,50,40);
    //(35,25 to 45,35)
    line_mpt(35,25,45,25);
    line_mpt(35,35,45,35);
    line_mpt(35,25,35,35);
    line_mpt(45,25,45,35);
    line_mpt(50,0,50,10);
    line_mpt(30,40,50,40);

    //7 starts at 60, spans till ,40

    line_mpt(60,0,60,10);
    line_mpt(60,0,85,0);
    line_mpt(60,10,75,10);
    line_mpt(85,0,75,40);
    line_mpt(75,10,67,40);
    line_mpt(75,40,67,40);

    //Starts at 95

    line_mpt(95,0,120,0);
    line_mpt(95,0,95,10);
    line_mpt(120,0,120,23);
    line_mpt(95,10,110,10);
    line_mpt(110,10,110,17);
    line_mpt(105,23,120,23);
    line_mpt(95,17,110,17);
    line_mpt(105,23,105,30);
    line_mpt(95,17,95,40);
    line_mpt(95,40,120,40);
    line_mpt(120,30,120,40);
    line_mpt(105,30,120,30);




}


void wedge(double x, double y){
    line_mpt(x+0,y+0,x-80,y+120);
    line_mpt(x+0,y+0,x+80,y+120);
    line_mpt(x-80,y+120,x+80,y+120);
}

void bar(double x, double y, int span){
    line_mpt(x-span/2,y-10,x+span/2,y-10);
    line_mpt(x-span/2,y+10,x+span/2,y+10);
    line_mpt(x-span/2,y-10,x-span/2,y+10);
    line_mpt(x+span/2,y-10,x+span/2,y+10);

}

int main(){

initwindow(800, 800);
T.x=300;T.y=300;
R.x=60;R.y=70;R.theta=0;
scaleConfig=1;
//rollNo();
wedge(60,85);       //60,40 is hinge point
//bar(60,70,600);

double max_theta= PI/8;
double spanPerTheta = 600/PI;
double r_x,r_y;
while(true){
    r_x=300;
    r_y=0;

    for(double t=0; t<=2*PI; t += 0.05){

        R.theta = max_theta*cos(t);
        colorConfig=WHITE;
        setcolor(WHITE);
        Tno.x=0;
        bar(60,70,600);
        Tno.x=r_x;
        rollNo();




        colorConfig = BLACK;
        setcolor(BLACK);
        Tno.x=0;
        bar(60,70,600);
        Tno.x=r_x;
        rollNo();
        r_x -= spanPerTheta*0.05;

    }
}

getch();

return 0;

}


