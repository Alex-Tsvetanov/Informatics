#include<iostream>
using namespace std;
long long c[1000001];
int main ()
{
    long long i,f=0,j,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(c[i]<c[j])
            {
                f++;
                break;
            }
        }
        if(f==0)cout << c[i] << " ";
        f=0;
    }
    cout << c[n] << endl;
    return 0;
}
