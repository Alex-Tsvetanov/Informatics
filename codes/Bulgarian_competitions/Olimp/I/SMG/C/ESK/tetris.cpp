#include <iostream>
#include <string>
using namespace std;
int main ()
{
    long long n,m;
    long long broi[120];
    long long sum=0;
    string s;
    for(int i=0;i<120;i++)broi[i]=0;
    cin>>n>>m;
    long long posl=0;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        bool f=true;
        for(int i=0;i<m;i++)if(s[i]=='.')f=false;
        if(f==true)
        {
            posl++;
        }
        if(f==false)
        {
            sum+=posl*(posl+1)/2;
            posl=0;
        }
    }
    sum+=posl*(posl+1)/2;
    cout<<sum<<endl;
    return 0;
}
