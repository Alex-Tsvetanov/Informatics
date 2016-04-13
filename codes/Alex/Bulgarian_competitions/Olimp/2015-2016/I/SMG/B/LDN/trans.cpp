#include<iostream>

using namespace std;

int main()
{
    long long m;
    long long p;
    cin>>p>>m;
    long long link[p];
    for(long long i=0;i<p;i++)
    {
        link[i]=0;
    }
    for(long long i=0;i<m;i++)
    {
        long long a, b;
        cin>>a>>b;
        link[a]++;
        link[b]++;
    }
    long long k;
    cin>>k;
    long long output[p];
    long long solution=0;
    for(long long i=0;i<p;i++)
    {
        if(link[i]>=k)
        {
            output[solution]=i;
            solution++;
        }
    }
    cout<<solution<<endl;
    for(long long i=0;i<solution;i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
