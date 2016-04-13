#include<iostream>
using namespace std;
struct win
{
    long long x,y;
};
win w[4194304];
int main()
{
    long long a,br=0;
    cin>>a;
    long long b=1,s=1,i;
    for(i=0; i<a; i++)
    {
        if(2*i*i>=a)
        {
            b=i;
            s=i;
            break;
        }
    }
    do
    {
        if((2*s*b)+b-s==a)
        {
            w[br].x=s;
            w[br].y=b;
            br++;
            s--;
            b++;
        }
        if((2*s*b)+b-s+1==a)
        {
            w[br].x=b;
            w[br].y=s;
            br++;
            b++;
            s--;
        }
        if((2*s*b)+b-s>a)
            s--;
        if((2*s*b)+b-s+1<a)
            b++;
    }
    while(s>0);
    cout<<br<<"\n";
    for(i=br-1;i>=0;i--)
    {
        cout<<w[i].x<<" "<<w[i].y<<"\n";
    }
    return 0;
}
