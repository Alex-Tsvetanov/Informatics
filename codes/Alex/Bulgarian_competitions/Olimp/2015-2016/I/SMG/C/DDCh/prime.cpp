#include <iostream>

using namespace std;

bool isPrime(uint64_t n)
{
    if(n%2==0)
        return false;
    for(int i = 3; i*i<=n; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string inp;
    cin>>inp;
    uint64_t res = 0;
    uint64_t last = 2;
    if(inp[0]=='1')
        res+=2;
    for(uint64_t i = 1; i<inp.size(); i++)
    {
        last++;
        while(!isPrime(last))
        {
            last++;
        }
        if(inp[i]=='1')
        {
            res+=last;
        }
    }
    cout<<res<<"\n";
    return 0;
}
