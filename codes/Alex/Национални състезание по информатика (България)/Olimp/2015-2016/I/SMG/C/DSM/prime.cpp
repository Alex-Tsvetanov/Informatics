#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(long long a)
{
    long long j;
    for(j=2; j<=sqrt(a); j++)
    {
        if(a%j==0)
        {
            return false;
        }
    }
    return true;
}
char number[3005];
char current='-1';
long long indexOf=0,answ=0;
int main()
{
    long long n,i;
    cin>>number;
    for(i=2; current!='\0'; i++)
    {
      if(isPrime(i)){
        current=number[indexOf];
        indexOf++;
        if(current!='\0' and current=='1'){
          answ=answ+1*i;
        }
      }
    }
    cout<<answ<<endl;
    return 0;
}
