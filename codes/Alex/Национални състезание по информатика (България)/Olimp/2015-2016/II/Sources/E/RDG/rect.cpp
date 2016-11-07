#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    if(n%2>0)cout<<"0"<<endl;
    else if(n%4==0) cout<<n/4<<endl;
    else if(n%4>0)cout<<n%4<<endl;


return 0;
}
