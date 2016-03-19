#include<iostream>
#include<algorithm>
using namespace std;
int br;
int p,n,s,l;
void perm(int i,int c,int sum)
{
    int j;c++;sum+=i;
    if(l==0)
    for(j=0;j<p;j++)
    {
        if(c==n)
        {
            if(sum+j<s)br++;
            else return;
        }
        else perm(j,c,sum);
    }
}
int main()
{
    cin>>p>>n>>s;
    perm(0,0,0);
    cout<<br<<endl;
    return 0;
}
