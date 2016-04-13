#include <iostream>

using namespace std;
int a[100000];
int main()
{  int n,m,k,i,br=0;
cin>>k;

     for(n=1;m<=k;m++)
    for(m=1;n<=k;n++)
    {

        if(m>=n&&k==(m*2+n*2+(((m-1)*(n-1))*2)+(m-1)+(n-1))-((2*m)-1)){
                cout<<m<<' '<<n<<endl; br++;
                }

    else
    {
        if(k==(m*2+n*2+(((m-1)*(n-1))*2)+(m-1)+(n-1))-(2*m)) {
           cout<<m<<' '<<n<<endl; br++;
        }
    }
    }
    cout<<br;

    return 0;


}

