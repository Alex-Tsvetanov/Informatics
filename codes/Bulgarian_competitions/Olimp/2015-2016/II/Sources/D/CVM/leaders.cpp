#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int m[n/2],m1[n/2+n%2];
    for(int i=0;i<n;i++)
    {
        if(i<n/2) cin>>m[i];
        else cin>>m1[i-n/2];
    }
    bool f1=0;
    for(int i=0;i<n;i++)
    {
        int x; bool f=1;
        if(i<n/2) x=m[i];
        else x=m1[i-n/2];
        for(int j=i+1;j<n;j++)
        {
            int y;
            if(j<n/2) y=m[j];
            else y=m1[j-n/2];
            if(y>x){f=0; break;}
        }
        if(f)
        {
            if(!f1){cout<<x; f1=1;}
            else cout<<" "<<x;
        }
    }cout<<'\n';
    return 0;
}
