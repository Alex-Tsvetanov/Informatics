#include<bits/stdc++.h>
using namespace std;
struct pr{
int f;
int g;
int q;
int w;
};
int main()
{int ts=0,ms=0,i1,y,t=0,m=200,f1,z,k,l,h,n,i,j,o,p;
pr a[20];
bool r[150][150]={0},s=0;
cin>>h>>l;
cin>>n;
for(i=0;i<n;i++)
{cin>>a[i].f>>a[i].g>>a[i].q>>a[i].w;
}
for(i=0;i<n;i++)
{for(z=a[i].f;z<a[i].f+a[i].q;z++)
for(k=a[i].g;k<a[i].g+a[i].w;k++)r[k][z]=1;
}
for(j=0;j<h;j++)
for(i=0;i<l;i++)
{f1=j;
while(s==0)
{if(r[f1][i]==0&&f1<l)f1++;
else s=1;
}
if(r[f1][i]==1)f1--;
s=0;
for(i1=i;i1<l;i1++)
{y=i;
while(s==0)
{if(r[i1][y]==0&&y<h)y++;
else s=1;
}
s=0;
t=y-1;
if(m>t)m=t;
}
f1-=1;
ts=(m-j+1)*(f1-i+1);
if(ms<ts)ms=ts;
m=200;
}
cout<<ms<<endl;
return 0;
}
