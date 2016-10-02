#include<iostream>
using namespace std;
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
      if(a+b==c) {
      cout<<"+"<<endl;
      }


       if(a*b==c){
      cout<<"*"<<endl;

    }  if(a-b==c){
      cout<<"-"<<endl;

    }
    if(a+b!=c&&a*b!=c&&a-b!=c){
        cout<<"0"<<endl;
    }


    return 0;
}

