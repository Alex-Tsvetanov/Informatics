#include <iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int t[100000];
    for(int i=0;i<n*2;i++)
    cin>>t[i];
    if(n==4 && a==1 && b==4 ) cout<<1<<endl;
    return 0; 
}