#include<iostream>
#include<stack>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long vhod[n];
    for(long long i=0;i<n;i++)
    {
        cin>>vhod[i];
    }
    stack <long long> a;
    long long maxnum=vhod[n-1];
    //cout<<"start\n";
    for(long long i=n-1;i>=0;i--)
    {
        //cout<<"i="<<i<<"\n";
        if(vhod[i]>=maxnum)
        {
            //cout<<"newmax="<<vhod[i]<<"\n";
            a.push(vhod[i]);
            maxnum=vhod[i];
        }
    }
    cout<<a.top();
    a.pop();
    while(!a.empty())
    {
        cout<<" "<<a.top();
        a.pop();
    }
    cout<<"\n";
    return 0;
}
