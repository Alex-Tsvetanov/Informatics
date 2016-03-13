#include<iostream>
using namespace std;
int main()
{
    int m, n, br=0;
    cin>>m>>n;
    while(!(m==1 and n==1))
    {
        if((m-m/2)*n>(n-n/2)*m and m>1 and n>1)
        {
            m-=m/2;
        }
        else
        {
            if((m-m/2)*n<=(n-n/2)*m and m>1 and n>1)
            {
                n-=n/2;
            }
            else
            {
                if(m==1)
                {
                    n-=n/2;
                }
                else
                {
                    if(n==1)
                    {
                        m-=m/2;
                    }
                }
            }
        }
        br++;
    }
    cout<<br<<endl;
    return 0;
}
