#include<iostream>
using namespace std;
int main ()
{
    int a,b,s1=0,s2=0;
    cin>>a>>b;
    while(a>1){
        if(a%2==0){
            a=a/2;
            s1=s1+1;
        }
        if(a>1 and a%2==1){
            a=a-1;
            s1=s1+1;
        }
    }
    while(b>1){
        if(b%2==0){
            b=b/2;
            s2=s2+1;
        }
        if(b>1 and b%2==1){
            b=b-1;
            s2=s2+1;
        }
    }
    cout<<s1+s2<<"\n";
    return 0;
}
