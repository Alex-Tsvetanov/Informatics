#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[n],b[n],br=n,c[m+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=a[i];j<=b[i];j++)c[j]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<=b[i];j++)
        {
            if(c[j]!=i+1)
            {
                br--;
                break;
            }
        }
    }
    cout<<br;
    return 0;
}
