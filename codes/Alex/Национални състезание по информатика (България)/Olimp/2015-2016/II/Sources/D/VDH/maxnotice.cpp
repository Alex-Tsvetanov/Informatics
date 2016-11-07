#include <iostream>
using namespace std;
int a1[102][102];
int main()
{

    int l, h, n;
    cin>>l>>h;
    cin>>n;
  /*  for (int i=0; i<h; i++)
    {
        for (int j=0; j<l; j++)
        {
            a[i][j]=0;
        }
    }*/
  /*  int x=4, y=3, a=2, b=1;
   for (int i=y; i<b; i++)
   {
       for (int j=x; j<a; j++) cout<<a[i][j]<<endl;
   }*/
   int x, y, a, b;
    for (int k=0; k<n; k++)
    {

        cin>>x>>y>>a>>b;
        int y1=y+b;
        int x1=x+a;
        for (int i=y; i<y1; i++)
        {
            for (int j=x; j<x1; j++)
            {
                a1[i][j]=1;
            }
        }
    }
   /* for (int i=0; i<h; i++)
    {
        for (int j=0; j<l; j++) cout<<a1[i][j]<<" ";
        cout<<endl;
    }*/
    int maxs=0;
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<l; j++)
        {
            if (a1[i][j]!=1)
            {
                int c=0, d=0, c1=10003;
                for(int i1=i; i1<h; i1++)
                {

                    if (a1[i1][j]==1) break;
                    d++;
                    c=0;
                    for (int j1=j; j1<l; j1++)
                    {

                        if (a1[i1][j1]==1) break;
                        c++;
                    }
                    if (c<c1) c1=c;
                }
                //cout<<i<<" "<<j<<" -> "<<d<<" "<<c1<<endl;
                if (c1==10003) c1=0;
                if (c1*d>maxs) maxs=c1*d;
                if (maxs==l*h) break;
            }
        }
    }
    cout<<maxs<<endl;
    return 0;
}/*
12 8
2
2 0 3 3
6 1 5 4
*/
