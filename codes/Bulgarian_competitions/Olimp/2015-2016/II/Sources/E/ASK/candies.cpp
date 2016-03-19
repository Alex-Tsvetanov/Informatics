#include <iostream>
using namespace std;
int main()
{
    int a,b,c,i;
    cin>>a>>b>>c;
    if(a==b && b==c && c==a)cout<<a+b+c-2<<endl;
    else cout<<a+b+c-1<<endl;
    return 0;
}
