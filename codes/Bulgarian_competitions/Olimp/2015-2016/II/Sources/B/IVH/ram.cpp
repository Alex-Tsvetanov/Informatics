#include <iostream>

using namespace std;

int main()
{
    int M[30], N[30];
    int i,count=0;
    long int k,m,n;
    cin>>k;
    for(i=1;i<=k/2;i++)
    {
        for(m=1;m<=k/2;m++)
        {
            if(i%m==0)
            {
                n=i/m;
                if(m<n && (k==2*m*n-m+n))
                {
                    M[count]=m;
                    N[count]=n;
                    count++;
                }
                else if(m>=n && ((k-1)==(2*m*n+m-n)))
                {
                    M[count]=m;
                    N[count]=n;
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
    for(int j=0;j<count;j++)
    {
        cout<<M[j]<<" "<<N[j]<<endl;
    }
    return 0;
}
