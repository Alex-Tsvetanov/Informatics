#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int kv=N/4;
    if(N<=kv)cout<<0<<endl;
    else cout<<N*kv<<endl;





    return 0;
}
