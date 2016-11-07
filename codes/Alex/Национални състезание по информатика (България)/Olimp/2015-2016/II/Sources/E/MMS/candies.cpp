#include <iostream>
using namespace std;
int main()
{
    long long a,b,c,br=0;
    cin>>a>>b>>c;
     do
    {
        a=a-1;
        br++;
        b=b-1;
        br++;
        c=c-1;
        br++;
        
        c=c-1;
        br++;
        b=b-1;
        br++;
        a=a-1;
        br++;
    }
    while (a==0||b==0||c==0);
    br=br++;
    cout<<br<<endl;
    return 0;
}