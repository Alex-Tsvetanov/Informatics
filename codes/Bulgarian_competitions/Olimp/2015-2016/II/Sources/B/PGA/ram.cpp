#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    vector<int> mf,nf;
    int k,br=0,i,h,a,m,n,l;
    cin>>k;
    for(h=1;h<=k/2;h++)
    {
        a=k+h;
        if(h%2==1)
        {
            n=h/2+1;
            m=(a-n)/(2*n+1);
            if(2*m*n+m+n==a&&n<=m)
            {
                mf.push_back(m);
                nf.push_back(n);
                br++;
            }
        }
        else
        {
            m=h/2;
            n=(a-m)/(2*m+1);
            if(2*m*n+m+n==a&&m<=n)
            {
                mf.push_back(m);
                nf.push_back(n);
                br++;
            }
        }
    }
    cout<<br<<endl;
    for(i=0;i<br;i++)
        cout<<mf[i]<<" "<<nf[i]<<endl;
    return 0;
}
