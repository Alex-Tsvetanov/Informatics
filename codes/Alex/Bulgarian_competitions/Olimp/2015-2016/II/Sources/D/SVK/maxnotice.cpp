#include <iostream>
using namespace std;
int main ()
{int l,h,n,d[100][100],c1,c2,v1,v2,maxs=0,s=0,a,b,b2,br=0,p=0,r=0,t=0,k=0,l1=0;
cin>>l>>h;
for(int i=0;i<h;i++)
{for(int j=0;j<l;j++)
d[i][j]=0;
}
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>c1>>c2>>v1>>v2;
    for(int j=c1;j<c1+v1;j++)
    {for(int q=c2;q<=c2+v2-1;q++)
     d[q][j]=1;
    }
    c1=0;
    c2=0;
    v1=0;
    v2=0;
}
for(int i=0;i<h;i++)
{cout<<endl;
    for(int j=0;j<l;j++)
    cout<<d[i][j];
}
cout<<endl;
maxs=0;
for(int i=0;i<h;i++)
    for(int j=0;j<l;j++)
    {k=i;l1=j;p=h;
    while(k<h && d[k][j]!=1)
    {
        l1=j;
        while(l1<l && d[k][l1]!=1)l1++;
        p=l1;k++;
        s=(k-i)*(p-j);
        if(maxs<s){maxs=s;cout<<maxs<<endl;s=0;}

    }
s=0;
    }
cout<<maxs<<endl;
return 0;
}
