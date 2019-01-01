//SUTHERLAND & HUDGMAN APPROACH FOR POLYGON CLIPPING
///CONCAVE POLYGONS

#include<iostream>
#include<graphics.h>
#include<vector>
#include<windows.h>
using namespace std;
#include"line.h"

int xwmin,ywmin,xwmax,ywmax;

class point{
public:
    int x;
    int y;
};

bool inside(point p, char edge)
{
    if(edge=='l'){
        if(p.x<xwmin)
            return false;
        return true;
    }
    else if(edge=='b'){
        if(p.y<ywmin)
            return false;
        return true;
    }
    else if(edge=='r'){
        if(p.x>xwmax)
            return false;
        return true;
    }
    else if(edge=='t'){
        if(p.y>ywmax)
            return false;
        return true;
    }
}

point findIntersection(char edge, point p1,point p2)
{
    point in;
    float x,y;
    if(edge=='l'){
        x=xwmin;
        y=p1.y + (float)(p2.y-p1.y)*(xwmin-p1.x)/(p2.x-p1.x);
    }
    if(edge=='b'){
        y=ywmin;
        x=p1.x +(float)(p2.x-p1.x)*(ywmin-p1.y)/(p2.y-p1.y);
    }
    if(edge=='r'){
        x=xwmax;
        y=p1.y + (float)(p2.y-p1.y)*(xwmax-p1.x)/(p2.x-p1.x);
    }
    if(edge=='t'){
        y=ywmax;
        x=p1.x +(float)(p2.x-p1.x)*(ywmax-p1.y)/(p2.y-p1.y);
    }
    in.x=(int)x;
    in.y=(int)y;
    return in;
}

void output(char  edge , point p1, point p2, vector<point> &vv)
{
    bool a1=inside(p1,edge);
    bool a2=inside(p2,edge);
    if(a1==true && a2==false){
        point in=findIntersection(edge,p1,p2);
        vv.push_back(in);
    }
    else if(a1==false && a2==true){
        point in=findIntersection(edge,p1,p2);
        vv.push_back(in);
        vv.push_back(p2);
    }
    else if(a1==true && a2==true){
        vv.push_back(p2);
    }
}

int main()
{
    point p1,p2,p3,p4,p5;
    cin>>xwmin>>ywmin>>xwmax>>ywmax;
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y>>p5.x>>p5.y;
    vector<point> v,vleft,vbot,vright,vtop;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p1);
    for(int i=0;i+1<v.size();i++){
        output('l',v[i],v[i+1],vleft);
    }
    vleft.push_back(vleft[0]);
    for(int i=0;i+1<vleft.size();i++){
        output('b',vleft[i],vleft[i+1],vbot);
    }
    vbot.push_back(vbot[0]);
    for(int i=0;i+1<vbot.size();i++){
        output('r',vbot[i],vbot[i+1],vright);
    }
    vright.push_back(vright[0]);
    for(int i=0;i+1<vright.size();i++){
        output('t',vright[i],vright[i+1],vtop);
    }
    vtop.push_back(vtop[0]);
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    mline(xwmin,ywmin,xwmin,ywmax,WHITE);
    mline(xwmin,ywmin,xwmax,ywmin,WHITE);
    mline(xwmax,ywmin,xwmax,ywmax,WHITE);
    mline(xwmin,ywmax,xwmax,ywmax,WHITE);
    for(int i=0;i+1<v.size();i++){
        mline(v[i].x,v[i].y,v[i+1].x,v[i+1].y,RED);
    }
    Sleep(1000);
    for(int i=0;i+1<vleft.size();i++){
        mline(vleft[i].x,vleft[i].y,vleft[i+1].x,vleft[i+1].y,YELLOW);
    }
    Sleep(1000);
    for(int i=0;i+1<vleft.size();i++){
        mline(vleft[i].x,vleft[i].y,vleft[i+1].x,vleft[i+1].y,BLACK);
    }
    for(int i=0;i+1<v.size();i++){
        mline(v[i].x,v[i].y,v[i+1].x,v[i+1].y,RED);
    }
    for(int i=0;i+1<vbot.size();i++){
        mline(vbot[i].x,vbot[i].y,vbot[i+1].x,vbot[i+1].y,YELLOW);
    }
    Sleep(1000);
    for(int i=0;i+1<vbot.size();i++){
        mline(vbot[i].x,vbot[i].y,vbot[i+1].x,vbot[i+1].y,BLACK);
    }
    for(int i=0;i+1<v.size();i++){
        mline(v[i].x,v[i].y,v[i+1].x,v[i+1].y,RED);
    }
    for(int i=0;i+1<vright.size();i++){
        mline(vright[i].x,vright[i].y,vright[i+1].x,vright[i+1].y,YELLOW);
    }
    Sleep(1000);
    for(int i=0;i+1<vright.size();i++){
        mline(vright[i].x,vright[i].y,vright[i+1].x,vright[i+1].y,BLACK);
    }
    for(int i=0;i+1<v.size();i++){
        mline(v[i].x,v[i].y,v[i+1].x,v[i+1].y,RED);
    }
    for(int i=0;i+1<vtop.size();i++){
        mline(vtop[i].x,vtop[i].y,vtop[i+1].x,vtop[i+1].y,YELLOW);
    }
    getch();
    closegraph();
    return 0;
}
///10 10 100 100 50 80 150 90 150 10 50 30 120 50

