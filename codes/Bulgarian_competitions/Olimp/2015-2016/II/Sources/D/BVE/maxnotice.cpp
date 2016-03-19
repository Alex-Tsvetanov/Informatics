#include<iostream>
using namespace std;
int main()
{
    int l,h,n,a[101][101],cordsh[101],sh[101],cordl[101],dl[101];
    int x1,k1,y1,k2,num0=0;
    int maxs=0,s=0;
    int br0=1,bk0=1,br1=0;
    cin>>l>>h;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>cordsh[i]>>cordl[i]>>sh[i]>>dl[i];
    for(int i=0;i<n;i++)
    {
    x1=cordsh[i];
    y1=cordl[i];
    k1=sh[i]+cordsh[i];
    k2=dl[i]+cordl[i];
    for(int i=y1;i<k2;i++)
    {
    for(int j=x1;j<k1;j++)
    a[i][j]=1;
}
}
       for(int i=0;i<h;i++)
       {
       for(int j=0;j<l;j++)
       {
       br0=1;bk0=1;br1=0;
       x1=i;k1=i;
       y1=j;k2=j;
       while(a[x1][y1]==0)
       {if(x1==h-1)break;
       br0++;
       x1++;
       
       }
       while(a[y1][k1]==0)
       {
       if(y1==l-1)break;
       bk0++;
       y1++;
       }
       for(int i1=k1;i1<k1+br0;i1++)
       {
       for(int j1=k2;j1<k2+bk0;j1++)
       if(a[i1][j1]==1){br1++;}
       }
        s=bk0*br0;
       //cout<<s<<endl;
       if(br1==0&&s>maxs)maxs=s;
       }}
       cout<<maxs<<endl;
       system("pause");
       return 0;
       
       } 
/*
12 8
2 
2 0 3 3
6 1 5 4
*/
