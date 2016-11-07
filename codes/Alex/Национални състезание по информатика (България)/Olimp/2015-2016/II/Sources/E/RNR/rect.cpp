#include<iostream>
using namespace std;
int main()
{
    long long n,br=0;
    cin>>n;
    long long m[n];
    m[n]=n;
    if(m[n]==1 || m[n]==2 || m[n]==3 || m[n]==5 || m[n]==6 || m[n]==8 || m[n]==9 || m[n]==15 || m[n]==18)
    {
        cout<<"0"<<endl;
    }
    else
    {
        m[n]=4;
        while(m[n]!=n)
        {
            m[n]=m[n]+3;
            while(n!=0)
            {
            if(n%m[n]==0)
            {
                n=n-m[n];
                br++;
            }
            }
        }
    }
    cout<<br<<endl;
    return 0;
}
