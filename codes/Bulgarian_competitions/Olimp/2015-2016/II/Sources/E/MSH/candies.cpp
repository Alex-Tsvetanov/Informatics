#include<iostream>
using namespace std;
int main()
{
    int a1,a2,a3,candie=0;
    cin>>a1>>a2>>a3;
    do
    {
        a1=a1-1;
        a2=a2-1;
        a3=a3-1;
        
    }        
            while(a2!=1)
            candie=a1;
       cout<< candie  <<" "<<endl ;
       return 0;
}