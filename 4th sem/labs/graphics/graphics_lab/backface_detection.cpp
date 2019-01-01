# include <conio.h>
# include <stdio.h>
# include <graphics.h>
# include <math.h>

float transform[4][4];
enum {x,y,z};

struct point
{
     float x,y,z;
};

point cube[6][4] =
{{{-10,10,-10},{-10,10,10},{10,10,10},{10,10,-10}},
 {{10,10,10},{10,10,-10},{10,-10,-10},{10,-10,10}},
 {{-10,10,10},{-10,10,-10},{-10,-10,-10},{-10,-10,10}},
 {{-10,10,10},{10,10,10},{10,-10,10},{-10,-10,10}},
 {{-10,10,-10},{10,10,-10},{10,-10,-10},{-10,-10,-10}},
 {{-10,-10,10},{10,-10,10},{10,-10,-10},{-10,-10,-10}}};

void initialise()
{
	int i,j;
	for(i=0;i<4;i++)
	      for(j=0;j<4;j++)
	     	if(i==j)
		   transform[i][j]=1;
		else
		  transform[i][j] = 0;
}

void updatecube(float ttransform[4][4])
{
	float coor[4][1],temp[4][1];
	int i,j,k,l;
	for(i=0;i<6;i++)
	    for(j=0;j<4;j++)
	    {
		coor[0][0]=cube[i][j].x;
		coor[1][0]=cube[i][j].y;
		coor[2][0]=cube[i][j].z;
		coor[3][0]=1;
		for(k=0;k<4;k++)
		      temp[k][0]=0;
		for(l=0;l<4;l++)
		       for(k=0;k<4;k++)
			temp[l][0]+=ttransform[l][k]*coor[k][0];
		cube[i][j].x=temp[0][0];
		cube[i][j].y=temp[1][0];
		cube[i][j].z=temp[2][0];
		}
}

void updatetransform(float ttransform[4][4])
{
	int i,j,k;
	float temp[4][4];
	for(i=0;i<4;i++)
	      for(j=0;j<4;j++)
		temp[i][j]=0;
	for(i=0;i<4;i++)
         	      for(j=0;j<4;j++)
	    	for(k=0;k<4;k++)
	 	     temp[i][j]+=ttransform[i][k]*transform[k][j];
	for(i=0;i<4;i++)
	     for(j=0;j<4;j++)
	           transform[i][j]=temp[i][j];
}

void rotate(float angle,int raxis)
{
	float fsin,fcos,ttransform[4][4];
	int i,j;
	for(i=0;i<4;i++)
	     for(j=0;j<4;j++)
	   	if(i==j)
	                 ttransform[i][j]=1;
		else ttransform[i][j] = 0;
	fsin=sin(angle);
	fcos=cos(angle);
	if(raxis==0)
	{
		ttransform[1][1] = fcos;
		ttransform[1][2] = -1*fsin;
		ttransform[2][1] = fsin;
		ttransform[2][2] = fcos;
	}
	else if(raxis==1)
	     {
		ttransform[0][0] = fcos;
		ttransform[0][2] = fsin;
		ttransform[2][0] = -1*fsin;
		ttransform[2][2] = fcos;
	     }
	     else
	     {
		ttransform[0][0] = fcos;
		ttransform[0][1] = -1*fsin;
		ttransform[1][0] = fsin;
		ttransform[1][1] = fcos;
	     }
	updatetransform(ttransform);
	updatecube(ttransform);
}

void translate(float Delx,float Dely,float Delz)
{
	float ttransform[4][4];
	int i,j;
	for(i=0;i<4;i++)
        	   for(j=0;j<4;j++)
	       if(i==j)
		ttransform[i][j]=1;
	       else
		ttransform[i][j]=0;
	ttransform[0][3]=Delx;
	ttransform[1][3]=Dely;
	ttransform[2][3]=Delz;
	updatetransform(ttransform);
}


void scale(float Sx,float Sy,float Sz)
{
	float ttransform[4][4];
	int i,j;
	for(i=0;i<4;i++)
	     for(j=0;j<4;j++)
	            if(i==j)
		   ttransform[i][j]=1;
		else
		   ttransform[i][j]=0;
	ttransform[0][0]=Sx;
	ttransform[1][1]=Sy;
	ttransform[2][2]=Sz;
	updatetransform(ttransform);
	updatecube(ttransform);
}

float dotproduct(struct point a,struct point b)
{
	int result;
	result=a.x*b.x+a.y*b.y+a.z*b.z;
	return(result);
}

struct point crossproduct(struct point a,struct point b)
{
	struct point result;
	result.x=b.z*a.y-b.y*a.z;
	result.y=a.z*b.x-a.x*b.z;
	result.z=a.x*b.y-b.x*a.y;
	return(result);
}

void o_project()
{
	int i,j;
	float ttransform[4][4];
	for(i=0;i<4;i++)
	      for(j=0;j<4;j++)
	   	if(i==j)
	      	    ttransform[i][j]=1;
		else
                              ttransform[i][j]=0;
	ttransform[2][2]=0;
	updatetransform(ttransform);
}

void draw(int surface)
{
	int midx,midy,i,j,k,prevx,prevy;
	float coor[4][1],temp[4][1],temp1[3];
	int flag=0;
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	for(i=0;i<4;i++)
	{
		coor[0][0]=cube[surface][i].x;
		coor[1][0]=cube[surface][i].y;
		coor[2][0]=cube[surface][i].z;
		coor[3][0]=1;
		for(j=0;j<4;j++)
		     temp[j][0]=0;
		for(j=0;j<4;j++)
		   for(k=0;k<4;k++)
		       temp[j][0]+=transform[j][k]*coor[k][0];
		if(flag!=0)
                   line(midx+prevx,midy-prevy,midx+coor[0][0],midy-coor[1][0]);
		else
		{
			flag = 1;
			temp1[0]=coor[0][0];
			temp1[1]=coor[1][0];
			temp1[2]=coor[2][0];
		}
		prevx=coor[0][0];
		prevy=coor[1][0];
	}
	line(midx+prevx,midy-prevy,midx+temp1[0],midy-temp1[1]);
}

void detect_surface()
{
	struct point n1,n2,n3;
	int i,j;
	struct point v={0,0,-1};
	for(i=0;i<6;i++)
	{
	    n2.x=cube[i][1].x-cube[i][0].x;
	    n2.y=cube[i][1].y-cube[i][0].y;
	    n2.z=cube[i][1].z-cube[i][0].z;
	    n3.x=cube[i][3].x-cube[i][0].x;
	    n3.y=cube[i][3].y-cube[i][0].y;
	    n3.z=cube[i][3].z-cube[i][0].z;
	    n1=crossproduct(n2,n3);
	    n2=cube[i][0];
	    if(dotproduct(n1,n2)<0)
	    {
	   	n1.x=-1*n1.x;
		n1.y=-1*n1.y;
		n1.z=-1*n1.z;
	    }
	    if(dotproduct(n1,v)<0)
	    draw(i);
	}
}

int main()
{
	float angle;
	int i,j;
	char ch;
	int gd = DETECT, gmode;
	initgraph( &gd, &gmode, "c:\\tc\\bgi");

	initialise();
	angle=0.05;
	ch=0;
	while(ch!=27)
	{
	   cleardevice();
	   initialise();
	   if(ch=='M')
	       rotate(angle,y);
	   if(ch=='K')
	       rotate(-1*angle,y);
	   if(ch=='P')
	       rotate(angle,x);
	   if(ch=='H')
	       rotate(-1*angle,x);
	   if(ch=='+')
	       scale(1.005,1.005,1.005);
	   if(ch=='-')
	       scale(0.995,0.995,0.995);
	   initialise();
	   detect_surface();
	   o_project();
	   fflush(stdin);
	   ch=getch();
	}
	getch();
	closegraph();
	return 0;
}
