#include<iostream>
int n,a,b,br=0;
using namespace std;
int main()
{
    cin>>n;
    for(a=1; a<=n; a++)
    {
        for(b=1; b<=n; b++)
        {
            if(n==(b*(a+a+1)+a))br++;
        }
    }
    cout<<br/2<<endl;

}
