#include<iostream>
using namespace std;

int main()
{
    int i,P,M,k,broi=0;
    cin>>P>>M;
    int pvgrad[P];
    for(i=0;i<P;i++)
    {
        pvgrad[i]=0;
    }
    for(i=0;i<M*2;i++)
    {
        cin>>k;
        pvgrad[k-1]++;
    }
    int trv;
    cin>>trv;
    for(i=0;i<P;i++)
    {
        if(trv<=pvgrad[i])
        {
            broi++;
        }
    }
    cout<<broi<<endl;
    for(i=0;i<P;i++)
    {
        if(trv<=pvgrad[i])
        {
            cout<<i+1<<" ";
        }
    }
    return 0;
}
