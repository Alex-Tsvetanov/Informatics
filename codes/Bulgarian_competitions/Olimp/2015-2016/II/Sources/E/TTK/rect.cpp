#include<iostream>
using namespace std;
int main()
{
    long long n,br=0,i;
    cin>>n;
    if(n%2!=0)cout<<0<<endl;
    else{ for(i=1;;i++)
    {
        if(((n-(4+(i-1)*3))%(3+(i-1)*2))==0){if((n-(4+(i-1)*3))/(3+(i-1)*2)>i)br++;
        else break;}
    }
cout<<br<<endl;
    }
return 0;    
}