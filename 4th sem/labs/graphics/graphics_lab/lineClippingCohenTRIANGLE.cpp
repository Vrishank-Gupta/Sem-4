#include<iostream>
#include<graphics.h>
#include "line.h"
#define AB 01
#define BC 04
#define CA 02
using namespace std;
class point{
public:
    int x;
    int y;
};

point pa,pb,pc;

bool ab(point p)
{
    int ans=(pa.y-p.y+(pb.y-pa.y)*(float)(p.x-pa.x)/(pb.x-pa.x));
    if((pa.y-pc.y+(pb.y-pa.y)*(float)(pc.x-pa.x)/(pb.x-pa.x))*ans>=0)
        return true;
    return false;
}

bool bc(point p)
{
    int ans=(pb.y-p.y+(pc.y-pb.y)*(float)(p.x-pb.x)/(pc.x-pb.x));
    if((pb.y-pa.y+(pc.y-pb.y)*(float)(pa.x-pb.x)/(pc.x-pb.x))*ans>=0)
        return true;
    return false;
}

bool ca(point p)
{
    int ans=(pc.y-p.y+(pa.y-pc.y)*(float)(p.x-pc.x)/(pa.x-pc.x));
    if((pc.y-pb.y+(pa.y-pc.y)*(float)(pb.x-pc.x)/(pa.x-pc.x))*ans>=0)
        return true;
    return false;
}

int gencode(point p)
{
    cout<<'a';
    int code=00;
    if(!ab(p))
        code|=AB;
    if(!bc(p))
        code|=BC;
    if(!ca(p))
        code|=CA;
    return code;
}


point func(int code, point p1,point p2)
{
    cout<<'b';
    point in;
    float x,y;
    int aa=AB&code,bb=BC&code,cc=CA&code;
    float m1=(pa.y-pb.y)/(pa.x-pb.x);
    float m2=(pb.y-pc.y)/(pb.x-pc.x);
    float m3=(pc.y-pa.y)/(pc.x-pa.x);
    float m=(p2.y-p1.y)/(p2.x-p1.x);
    float c1=pa.y-m1*pa.x;
    float c2=pb.y-m2*pb.x;
    float c3=pc.y-m3*pc.x;
    float c=p1.y-m*p1.x;
    if(aa!=00){
        cout<<" aa: "<<aa<<' ';
        in.x=(c-c1)/(m1-m);
        in.y=(m1*c-m*c1)/(m1-m);
        cout<<endl<<in.x<<' '<<in.y<<endl;
    }
    else if(bb!=00){
        cout<<" bb: "<<bb<<' ';
        in.x=(c-c2)/(m2-m);
        in.y=(m2*c-m*c2)/(m2-m);
    }
    else if(cc!=00){
        cout<<" cc: "<<cc<<' ';
        in.x=(c-c3)/(m3-m);
        in.y=(m3*c-m*c3)/(m3-m);
    }
    return in;

}
int main()
{
    cin>>pa.x>>pa.y>>pb.x>>pb.y>>pc.x>>pc.y;
    point p1,p2,pp1,pp2;
    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    pp1.x=p1.x,pp1.y=p1.y,pp2.x=p2.x,pp2.y=p2.y;
    bool done=false;
    while(true){
        int code1=gencode(p1);
        int code2=gencode(p2);
        cout<<code1<<' '<<code2<<' '<<endl;
        int andc=code1&code2;
        int orc=code1|code2;
        if((andc==00 )&&(orc==00)){
            cout<<'c';
            done=true;
            break;
        }
        else if(andc!=0){
                cout<<'d';
            break;
        }
        else if((andc==00) && (orc!=00)){
            cout<<'e';
            if(code1!=0){
                point temp=func(code1,p1,p2);
                p1.x=temp.x;
                p1.y=temp.y;
            }
            else if(code2!=0){
                point temp=func(code2,p1,p2);
                p2.x=temp.x;
                p2.y=temp.y;
            }
        }
    }
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    mline(pa.x,pa.y,pb.x,pb.y,WHITE);
    mline(pb.x,pb.y,pc.x,pc.y,WHITE);
    mline(pc.x,pc.y,pa.x,pa.y,WHITE);
    mline(pp1.x,pp1.y,pp2.x,pp2.y,RED);
    if(done){
        cout<<endl<<p1.x<<' '<<p1.y<<' '<<p2.x<<' '<<p2.y<<endl;
        mline(p1.x,p1.y,p2.x,p2.y,YELLOW);
    }
    getch();
    closegraph();
    return 0;
}
//0 0 100 100 20 50 0 50 250 70
