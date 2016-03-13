#include<iostream>
using namespace std;
int a,b,res;
int main()
{
    cin>>a>>b;
    while(a!=1 || b!=1)
    {
        if((a<b && a!=1)||b==1)
        {
            if(a%2==1)
            {
                a/=2;
                a++;
            }
            else
            {
                a/=2;
            }
        }
        else
        {
            if(b%2==1)
            {
                b/=2;
                b++;
            }
            else
            {
                b/=2;
            }
        }
        res++;
    }
    cout<<res;
    return 0;
}
/**
5 3

3 1
*/
