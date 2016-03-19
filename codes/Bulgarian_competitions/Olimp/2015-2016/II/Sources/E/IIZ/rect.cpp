#include <iostream>
using namespace std;
int main()
{
    int a=0,b=0,n;
    cin>>n;
    if(n<4)cout<<"0"<<endl;
    else
    {
      for(int i=0;i<=n/4;i++)
       {
            if((n-i-2)%3==0)a++;
            else a==0;
       }
       if(n%4!=0)cout<<a<<endl;
       else if(n%4==0){a++;cout<<a<<endl;}


    }


    return 0;
}
