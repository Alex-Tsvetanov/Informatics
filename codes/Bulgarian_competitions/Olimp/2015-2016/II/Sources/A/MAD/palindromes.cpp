#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

bool palindrome(string s)
{
    for(int i = 0; i<s.size() / 2; ++i)
    {
        if(s[i] != s[s.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    if(palindrome(s))
    {
        cout<<0;
    }
    else
    {
        cout<<1;
    }
    return 0;
}
