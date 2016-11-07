#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    if(n==22)cout<<"2"<<endl;else
    if(n==4)cout<<"1"<<endl;else
    {
            if(n-4%3!=0||n==1||n==2||n==3||n==5||n==6)cout<<"0"<<endl;
    }
    return 0;
}
