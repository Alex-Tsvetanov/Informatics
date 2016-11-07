#include<iostream>
long long a,b,c,i,sb,br=0;
using namespace std;
int main()
{
    cin>>a>>b>>c;
    sb=a+b+c;
    for(i=1;i<=sb;i++)
    {
    a--;
    if(a>=0)br++;
    else if(a==-1)break;
    b--;
    if(b>=0)br++;
    else if(b==-1)break;
    c--;
    if(c>=0)br++;
    else if(c==-1)break;
    b--;
    if(b>=0)br++;
    else if(b==-1)break;
    }
    cout<<br<<endl;
}
