#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int count = 1,sum=0;
    int n,p,s;
    cin>>p>>n>>s;
    int A[n];
    for(int i=0;i<n;i++) A[i]=0;
    int index=0;
    for(int i=0;i<pow(p,n)-1;i++)
    {
        sum=0;
        A[index]++;
        for(int k=0;k<n-1;k++)
        {
            if(A[k]==p)
            {
                A[k]=0;
                A[k+1]++;
            }
        }
        for(int k=0;k<n;k++) sum+=A[k];
        if(sum<s) count++;
    }
    cout<<count<<endl;
    return 0;
}
