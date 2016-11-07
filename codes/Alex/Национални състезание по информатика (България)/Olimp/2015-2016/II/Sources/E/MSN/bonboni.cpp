#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,s=0;
    cin>>a>>b>>c;
    while(a>0&&b>0&&c>0)
    {a--;s++;
    b--;s++;
    c--;s++;
    if(b>0){b--;s++;}
    else break;}
   cout<<s<<endl;
    return 0; 
}
