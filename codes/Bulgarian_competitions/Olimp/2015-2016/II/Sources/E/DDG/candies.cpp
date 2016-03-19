#include<iostream>
using namespace std;
int main ()
{
    int a,b,c,count;
    cin>>a>>b>>c;
    if(a+b+c<0&&a+b+c>1000000000);
    do
    {
       count=(a+b+c)-2;
    }
    while (count==0);
    cout<<count;
}