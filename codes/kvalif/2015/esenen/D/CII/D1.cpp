#include<iostream>
using namespace std;
int n,min1=100000;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            if((i+n/i)*2<min1)
                min1=(i+n/i)*2;
        }
    }
    cout<<min1<<endl;
    return 0;
}
