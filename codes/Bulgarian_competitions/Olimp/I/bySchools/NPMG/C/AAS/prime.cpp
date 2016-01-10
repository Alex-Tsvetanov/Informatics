#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> prime(k+10, 0);

bool isprime(int number);
void get_primes(int prs);
int main()
{
    string as;
    cin >> as;
    int ch=0;
    int k=as.size()+1;
    get_primes(k);
    for(int i=0; i<k-1; ++i)
    {
        int a=as[i]-'0';
        ch+=prime.at(i)*a;
    }
    cout << ch << endl;
    return 0;
}

bool isprime(int number)
{
    int prcount=0;
    for(int a=1; a<=number; ++a)
    {
        if(number%a==0)
        {
            ++prcount;
        }
    }
    if(prcount==2) return 1;
    else return 0;
}

void get_primes(int prs)
{
    int primesize=0;
    int maxprime=0;
    while(primesize<prs)
    {
        if(isprime(maxprime))
        {
            prime.at(primesize)=maxprime;
            ++primesize;
        }
        ++maxprime;
    }
}
