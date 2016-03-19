#include<iostream>
using namespace std;
int main()
{
    long long a, b, c, q=0;
    cin>>a>>b>>c;
    do
    {
      a+b+c=(a+b+c)-3*1;
      q++;
      (a+b+c)-1=a+b+c;
      q++;
      
    }
    while(c!=0);
    cout<<q<<endl;
    return 0;
}