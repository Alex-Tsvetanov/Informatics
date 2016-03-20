#include<iostream>
#include<algorithm>
using namespace std;
int p[128],used[128],n,bigs,k,s;
void print()
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        cout<<p[i];
        sum+=p[i];
    }
    cout<<endl;
    if(sum<s)
    bigs++;
}
int perm(int i)
{
    int j;
    for(j=0;j<k;j++)
    {
        if(used[j]==0)
        {
            p[i]=j;
            if(i==n)print();
            else
            {perm(i+1);}
        }
    }
}

int main()
{
cin>>k>>n>>s;
perm(0);
cout<<bigs/2<<endl;
return 0;
}
