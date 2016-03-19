#include<iostream>
using namespace std;
int main()
{
    long long n,s,br=0;
    cin>>n;
    
    if (n%4==0) br=n/4;
    else 
    {s=n/2; 
     br=s/4;
    }
    cout<<br<<endl;
    return 0;
    
}