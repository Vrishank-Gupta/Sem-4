#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class point{
public:
    int x;
    int y;
};

bool cmp1(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

bool cmp2(point a,point b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x>b.x;
}

point normalNikaal(point pp)
{
    point p;
    if(pp.x*pp.y>0){
        p.x=pp.y;
        p.y=(-1)*pp.x;
        return p;
    }
    else{
        p.x=(-1)*pp.y;
        p.y=pp.x;
        return p;
    }
}

int main()
{
    point a,b,c,d,p,q,r,s;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y>>p.x>>p.y>>q.x>>q.y>>r.x>>r.y>>s.x>>s.y;
    vector<point> v,vv,edges,normal,cw,sp;
    vector<vector<point>> itcw,itsp;
    vector<point> z;
    itcw.push_back(z);
    itcw.push_back(z);
    itcw.push_back(z);
    itcw.push_back(z);
    vector<int> num,denom;
    vector<float> tval;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(a);
    vv.push_back(p);
    vv.push_back(q);
    vv.push_back(r);
    vv.push_back(s);
    vv.push_back(p);
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            point temp;
            temp.x=v[i+1].x-v[i].x;
            temp.y=v[i+1].y-v[i].y;
            edges.insert(edges.begin()+i,temp);
            normal.insert(normal.begin()+i,normalNikaal(temp));
            point pminusei;
            pminusei.x=vv[j].x-v[i].x;
            pminusei.y=vv[j].y-v[i].y;
            int numm=(normal[i].x*pminusei.x)+(normal[i].y*pminusei.y);
            int denn=((normal[i].x*(vv[j+1].x-vv[j].x))+(normal[i].y*(vv[j+1].y-vv[j].y)))*(-1);
            float t=(float)numm/denn;
            num.insert(num.begin()+i,numm);
            denom.insert(denom.begin()+i,denn);
            tval.insert(tval.begin()+i,t);
            if(t>=0&&t<=1){
                point vx;
                vx.x=vv[j].x+(vv[j+1].x-vv[j].x)*t;
                vx.y=vv[j].y+(vv[j+1].y-vv[j].y)*t;
                cout<<"vx"<<' '<<vx.x<<' '<<vx.y<<endl;
                cout<<"hi";
                itcw[i].push_back(vx);
                cout<<"hu";
            }
        }
        for(int i=0;i<4;i++){
            cout<<tval[i]<<' ';
        }
        cout<<endl;

    }
    for(int i=0;i<4;i++){
        if((v[i+1].x>v[i].x)||(v[i+1].x==v[i].x&&v[i+1].y>v[i].y))
            sort(itcw[i].begin(),itcw[i].end(),cmp1);
        else{
            sort(itcw[i].begin(),itcw[i].end(),cmp2);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<itcw[i].size();j++){
            cout<<itcw[i][j].x<<' '<<itcw[i][j].y<<endl;
        }
    }
    for(int i=0;i<4;i++){
        cw.push_back(v[i]);
        for(int j=0;j<itcw[i].size();j++){
            cw.push_back(itcw[i][j]);
        }
    }
    for(int i=0;i<cw.size();i++)
        cout<<cw[i].x<<' '<<cw[i].y<<endl;

    return 0;
}
/// 4 12 12 7 23 15 10 1 12 18 16 8 11 10 3 6
