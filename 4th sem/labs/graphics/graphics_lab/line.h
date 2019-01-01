int roundoff(float x)
{
    int a=(int)x;
    if(x-a<0.5)
        return a;
    return a+1;
}

void mline(float x1,float y1,float x2,float y2,int col)
{
    float m=(y2-y1)/(x2-x1);
    if(abs(m)<1){
        float x=x2,y=y2;
        if(x1<x2){
            x=x1;
            y=y1;
        }
        putpixel(roundoff(320+x),roundoff(240-y),col);
        while(x<=std::max(x1,x2)){
            x+=1;
            y+=m;
            putpixel(roundoff(320+x),roundoff(240-y),col);
        }
    }
    else{
        float x=x2,y=y2;
        if(y1<y2){
            y=y1;
            x=x1;
        }
        putpixel(roundoff(320+x),roundoff(240-y),col);
        while(y<=std::max(y1,y2)){
            y+=1;
            x+=(1/m);
            putpixel(roundoff(320+x),roundoff(240-y),col);
        }
    }
}
