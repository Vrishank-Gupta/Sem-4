#include<iostream>
#include<list>
using namespace std;
#include<algorithm>

class point
{
public:
    int x;
    int y;

};

class edge
{
public:
    int ymax;
    int xymin;
    float onebym;
};

bool cmp1(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

bool sameHai(point a,point b)
{
    if(a.x==b.x&&a.y==b.y)
        return true;
    return false;
}

bool haiKya(edge e, vector<edge> edgearr)
{
    for(int i=0;i<edgearr.size();i++){
        if(edgearr[i].ymax==e.ymax&&edgearr[i].xymin==e.xymin&&edgearr[i].onebym==e.onebym)
            return true;
    }
    return false;
}

int main()
{
    point a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    int ymin=min(a.y,min(b.y,min(c.y,d.y)));
    int ymax=max(a.y,max(b.y,max(c.y,d.y)));
    point arr1[6];
    point arr2[4];
    arr1[0]=d;
    arr1[1]=a;
    arr1[2]=b;
    arr1[3]=c;
    arr1[4]=d;
    arr1[5]=a;
    arr2[1]=a;
    arr2[2]=b;
    arr2[3]=c;
    arr2[4]=d;
    sort(arr2,arr2+4,cmp1);
    list<edge> arr[5000];
    vector<edge> edgearr;
    for(int i=0;i<=3;i++){
        list<edge> temp;
        int j;
        point vertex=arr2[i],pichla,agla;
        for(j=1;j<5;j++){
            if(sameHai(arr2[i],arr1[j]))
                break;
        }
        if(arr1[j-1].x<arr1[j+1].x){
            pichla=arr1[j-1];
            agla=arr1[j+1];
        }
        else{
            pichla=arr1[j+1];
            agla=arr1[j-1];
        }
        edge edge1;
        edge1.ymax=max(pichla.y,vertex.y);
        if(pichla.y<vertex.y)
            edge1.xymin=pichla.x;
        else
            edge1.xymin=vertex.x;
        float m=(float)(pichla.x-vertex.x)/(pichla.y-vertex.y);
        edge1.onebym=m;
        edge edge2;
        edge2.ymax=max(agla.y,vertex.y);
        if(agla.y<vertex.y)
            edge2.xymin=agla.x;
        else
            edge2.xymin=vertex.x;
        m=(float)(agla.x-vertex.x)/(agla.y-vertex.y);
        edge2.onebym=m;
        if(haiKya(edge1,edgearr)){
            ///do nothing
        }
        else{
            cout<<'a';
            temp.push_back(edge1);
            edgearr.push_back(edge1);
        }
        if(haiKya(edge2,edgearr)){
            ///do nothing
        }
        else{
            cout<<'b';
            temp.push_back(edge2);
            edgearr.push_back(edge2);
        }
        arr[vertex.y]=temp;
    }
    list <edge> :: iterator it;
    list <edge> l=arr[1];
    for(it = l.begin(); it != l.end(); it++){
        cout << '\t' << (*it).ymax<<endl;
        }
    return 0;
}
