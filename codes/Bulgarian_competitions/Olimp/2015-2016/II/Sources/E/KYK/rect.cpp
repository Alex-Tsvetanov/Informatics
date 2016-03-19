#include<iostream>
using namespace std;
int main()
{
    long long N,br=0;
    cin>>N;
    if(N/4)br++;
    if(N/3)br++;
    else if(N) br;
    cout<<br<<"\n";
    return 0;
}
