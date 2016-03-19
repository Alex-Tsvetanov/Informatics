#include<iostream>
using namespace std;
int main ()
{
    int p,n,s,br=1,j;
    cin>>p>>n>>s;
    for(int i=1; i<s; i++)
    {
        br=br+i*n;
    }
    j=p-1;
    br=br-n*j;
    cout<<br;
    return 0;
}
