#include<iostream>
using namespace std;
int n,p,s;
int k[128],used[128],br;
void check()
{
    int i,sum=0,l=0;
    for(i=1; i<=n; i++)
    {
        sum+=k[i];
    }
    if(sum<s) br++;
    else
        sum=0;
}
int comb(int i)
{
    int j;
    for(j=0; j<p; j++)
    {
        if(!used[i])
        {
            k[i]=j;
            used[j]=1;
            if(i==n)
            {
                check();
            }
            else comb(i+1);
            used[j]=0;
        }
    }
}
int main()
{
    cin>>p>>n>>s;
    comb(1);
    cout<<br<<endl;
    return 0;
}
