#include<iostream>
using namespace std;
long long n,st,i,a,b,br=0;
int main()
{
    cin>>n;
    if (n==4) br++;
    else
    {
        for (i=1;i<=n/(i*2+1)-1;i++)
            {
                a=i;
                b=n/(a*2+1);
                if (a*(b+1)+b*(a+1)==n) br++;
            }
    }
    cout<<br<<endl;
    return 0;
}
