#include<iostream>
#include<graphics.h>
#include<utility>
#include "line.h"
#include<algorithm>
#include<vector>
using namespace std;

pair<int,int> normalNikaal(int x1,int y1,int x2,int y2)
{
    if((x2-x1)*(y2-y1)>0){
        return make_pair(y2-y1,x1-x2);
    }
    else{
        return make_pair(y1-y2,x2-x1);
    }
}

int main()
{
    vector<pair<int,int>> v;
    vector<float> enter,exit;
    enter.push_back(0);
    exit.push_back(1);
    int p1x,p1y,p2x,p2y;
    for(int i=0;i<3;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        v.push_back(make_pair(temp1,temp2));
    }
    v[3]=v[0];
    cin>>p1x>>p1y>>p2x>>p2y;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    mline(p1x,p1y,p2x,p2y,WHITE);
    for(int i=0;i<3;i++){
        mline(v[i].first,v[i].second,v[i+1].first,v[i+1].second,WHITE);
        pair<int ,int> normal=normalNikaal(v[i].first,v[i].second,v[i+1].first,v[i+1].second);
        //pair<int,int> edge=make_pair(v[i+1].first-v[i].first,v[i+1].second-v[i].second);
        pair <int,int> p2minusp1= make_pair(p2x-p1x,p2y-p1y);
        pair <int,int> p1minuspe= make_pair(p1x-v[i].first,p1y-v[i].second);
        float t= (float)(normal.first*p1minuspe.first+normal.second*p1minuspe.second)*(-1)/(normal.first*p2minusp1.first+normal.second*p2minusp1.second);
        if(t>=0&&t<=1){
            if((normal.first*p2minusp1.first+normal.second*p2minusp1.second)<0)
                enter.push_back(t);
            else
                exit.push_back(t);
        }
    }

    getch();
    closegraph();
    return 0;
}
