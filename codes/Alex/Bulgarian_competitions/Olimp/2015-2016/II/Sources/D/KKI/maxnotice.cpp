#include<iostream>
using namespace std;
int mas[100][100],h,l,k,p,x,y,n;
int generator(int x1,int y1)
{
    int s=0,maxs=0;
    bool crash=0;
    for(int i=x1;i<l;i++)
    {
        for(int j=y1;j<h;j++)
        {
            if(mas[x1+i][y]==1)break;
            if(mas[x1][y1+j]==1)break;
            if(mas[i][j]==0)s=(i-x1+1)*(j-y1+1);
            if(s>maxs)maxs=s;
        }
    }
    return maxs;
}
int main()
{

    cin>>h>>l>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>k>>p;
        for(int j=0;j<k;j++)
        for(int c=0;c<p;c++)
        {
            mas[x+j][y+c]=1;
        }

    }
    int result=0,g=0;
      for(int i=0;i<h;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(mas[i][j]==0)g=generator(i,j);
            if(g>result)result=g;
        }

    }

    cout<<result/2<<endl;


    return 0;
}
/*
12 8
2
2 0 3 3
6 1 5 4
*/
