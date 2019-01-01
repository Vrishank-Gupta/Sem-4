

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <dos.h>
#define PI      3.1416
#define COS(a)  cos((a*PI)/((float)180))
#define SIN(a)  sin((a*PI)/((float)180))

void print(float toPrint[4][3],int columns){

    int i,j;
    int xc = getmaxx()/2;
    int yc = getmaxy()/2;
    // cout<<xc<<" "<<yc;
    for(i=0;i<columns-1;i++){
        line(xc + toPrint[0][i],yc - toPrint[1][i],xc + toPrint[0][i+1],yc - toPrint[1][i+1]);
    }

    line(xc + toPrint[0][i],yc - toPrint[1][i],xc + toPrint[0][0],yc - toPrint[1][0]);
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"..//BGI");

    int xc = getmaxx()/2, yc = getmaxy()/2;


    float triangle[4][3] = {{-10,-10,180},
						     {-10,10,0},
						     {0,0,0},
						     {1,1,1}};


	for(int ang=0; !kbhit(); ang++){

    	circle(320, 240, 200);
        circle(320, 240, 5);

        float rotx[4][4] = {{1,0,0,0},
                             {0,COS(ang),-SIN(ang),0},
                             {0,SIN(ang),COS(ang),0},
                             {0,0,0,1}};

        float roty[4][4] = {{COS(ang),0,SIN(ang),0},
                                 {0,1,0,0},
                                 {-SIN(ang),0,COS(ang),0},
                                 {0,0,0,1}};

        float rotz[4][4] = {{COS(ang),SIN(ang),0,0},
                                {-SIN(ang),COS(ang),0,0},
                                {0,0,1,0},
                                {0,0,0,1}};


        float pts[4][3];

		 for (int i = 0; i<4; i++) {
            for (int j = 0; j<3; j++) {
                int sum = 0;
                for (int k = 0; k<4; k++) {
                    sum += rotz[i][k] * triangle[k][j];
                }
                pts[i][j] = sum;
            }
        }

        print(pts,3);
    	delay(25);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}



