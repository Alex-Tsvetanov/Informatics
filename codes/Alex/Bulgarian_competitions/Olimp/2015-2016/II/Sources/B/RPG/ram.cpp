#include <iostream>

using namespace std;

int main()
{
    int a[50], b[50];

    long int k,m,n,f1,f2;
    int br1,br=0;
    cin>>k;
    for(br1=1;br1<=k/2;br1++)
    {
        for(m=1;m<=k/2;m++)
        {
            if(br1%m==0)
            {
                n=br1/m;
                f1=2*m*n-m+n;
                f2=2*m*n+m-n;
                if(m<n && (k==f1))
                {

                    a[br]=m;
                    b[br]=n;
                    br++;
                }
                else if(m>=n && (k-1)==(f2))
                {
                    a[br]=m;
                    b[br]=n;
                    br++;
                }
            }
        }
    }
    cout<<br<<endl;
    for(int j=0;j<br;j++)
    {
        cout<<a[j]<<" "<<b[j]<<endl;
    }
    return 0;
}
