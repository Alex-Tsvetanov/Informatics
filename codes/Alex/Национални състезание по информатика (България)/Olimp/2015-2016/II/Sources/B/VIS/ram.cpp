#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    cin>>k;
    int cnt=0;
    for(int m=1;3*m<=k;m++)
    {
        double n1=(k-2*m*m-2*m-1)/(2*m+1)+m+1;
        double n2=(k-3*m)/(2*m-1)+1;
        if((k-2*m*m-2*m-1)%(2*m+1)==0 && m<n1)
        {
            int n=(k-2*m*m-2*m-1)/(2*m+1)+m+1;
            cnt++;
        }
        if((k-3*m)%(2*m-1)==0 && m > n2)
        {
            int n = (k-3*m)/(2*m-1)+1;
            cnt++;
        }
    }
    cout<<cnt<<endl;

    for(int m=1;3*m<=k;m++)
    {
        double n1=(k-2*m*m-2*m-1)/(2*m+1)+m+1;
        double n2=(k-3*m)/(2*m-1)+1;
        if((k-2*m*m-2*m-1)%(2*m+1)==0 && m<n1)
        {
            int n=(k-2*m*m-2*m-1)/(2*m+1)+m+1;
            cout<<m<<" "<<n<<endl;
        }
        if((k-3*m)%(2*m-1)==0 && m > n2)
        {
            int n = (k-3*m)/(2*m-1)+1;
            cout<<m<<" "<<n<<endl;
        }
    }

    return 0;
}
