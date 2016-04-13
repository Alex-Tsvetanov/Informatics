#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    if(n-4%3==0 || n-1%3==0)cout<<"2"<<endl;
    else cout<<"0";
    return 0;
}
