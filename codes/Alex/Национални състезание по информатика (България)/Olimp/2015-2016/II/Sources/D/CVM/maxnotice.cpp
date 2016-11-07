#include<iostream>
using namespace std;
bool m[101][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b; swap(a,b);
    int n,x,y,a1,b1;
    cin>>n;
    int maxi=0,mini=a,maxj=0,minj=b;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>a1>>b1; swap(x,y); swap(a1,b1);
        for(int j=x;j<x+a1;j++)
            for(int k=y;k<y+b1;k++)
                m[j][k]=1;
        if(x+a1>maxi) maxi=x+a1;
        if(y+b1>maxj) maxj=y+b1;
        if(x<mini) mini=x;
        if(y<minj) minj=y;
    }
    int s1,s2,s3,s4;
    s1=mini*b;
    s2=minj*a;
    s3=(a-maxi)*b;
    s4=(b-maxj)*a;
    cout<<max(max(max(s1,s2),s3),s4)<<'\n';
    return 0;
}
