#include<iostream>
using namespace std;
long long br, all[2024][2024], i, j, k, broken[2024][2024], a[2024], b[2024], ans;
int main()
{
    cin>>br;
    all[1][1]=4;
    for(i=2; i<=2000; i++)
    {
        all[i][1]=all[i-1][1]+3;
    }
        k=3;
    for(i=1; i<=2000; i++)
    {

        for(j=2; j<=2000; j++)
        {
            all[i][j]=all[i][j-1]+k;
        }
        k=k+2;
    }
    for(i=1; i<=2000; i++)
    {
        broken[i][1]=1;
    }
    for(j=2; j<=2000; j++)
    {
        broken[1][j]=2;
    }
    for(i=2; i<=2000; i++)
    {
        for(j=2; j<=2000;j++)
        {
            if(j<=i) broken[i][j]=broken[i][j-1]+2;
            else
            if(j==i+1) broken[i][j]=broken[i][j-1]+1;
            else
            if(j>i+1) broken[i][j]=broken[i][j-1];
        }
    }
    for(i=1; i<=2000; i++)
    {
        for(j=1; j<=2000; j++)
        {
            if(all[i][j]-broken[i][j]==br)
            {
                ans++;
                a[ans]=i;
                b[ans]=j;
            }
        }
    }
    if(ans==0) cout<<0<<endl;
    else
    {
        cout<<ans<<endl;
        for(i=1; i<=ans;i++)
            cout<<a[i]<<" "<<b[i]<<endl;
    }
    return 0;
}
