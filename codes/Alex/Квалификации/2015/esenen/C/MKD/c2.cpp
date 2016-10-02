#include<iostream>
using namespace std;
int m=0,n;
bool p[100];
void f(int c,int q)
{
    if(q==n)
    {
        m++;
        return;
    }
    for(int i=1;i<10;i++)
    {
        if(p[c*10+i])
        {
            f(i,q+1);
        }
    }
    if(q==n-1 and p[c*10])
    {
        f(0,q+1);
    }
    return;
}
int main()
{
    int d[3];
    cin>>n>>d[0]>>d[1]>>d[2];
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i*d[j]<100)
            {
                p[i*d[j]]=true;
            }
        }
    }
    for(int i=10;i<100;i++)
    {
        if(p[i] and (i%10!=0 or (i%10==0 and n==2)))
        {
            f(i%10,2);
        }
    }
    cout<<m;
    return 0;
}
