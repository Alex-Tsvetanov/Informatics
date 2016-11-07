#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,br=0;
    cin>>a>>b>>c;
    if(a<=b && a<=c)
    {
        br=a*3-2;
    }
    if(b<a && b<=c)
    {
        br=b*3-1;
    }
    if(c<a && c<b)
    {
        br=c*3;
    }
    cout<<br<<endl;
    return 0;
}
