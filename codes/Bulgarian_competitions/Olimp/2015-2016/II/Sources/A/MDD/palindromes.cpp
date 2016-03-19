#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> breaks;
string s;

bool isPalindromeBasic(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] != str[str.size()-i-1]) return false;
    }
    return true;
}

bool isPalindrome()
{
    int first, last;
    for(int i = 0; i < breaks.size(); i++)
    {
        if(i == 0)
        {
            first = 0;
            last = breaks.at(i);
        }
        else
        {
            first = breaks.at(i-1);
            last = breaks.at(i);
        }
        if(!isPalindromeBasic(s.substr(first, last))) return false;
    }
    if(!isPalindromeBasic(s.substr(breaks.at(breaks.size()-1)))) return false;
    return true;
}

void fun(int k)
{
    if(isPalindrome()) return;
    if(breaks.at(breaks.size()-1) == s.size()-1)
    {
        if(breaks.size() == s.size()-1) return;
        else
        {
            if(breaks.size() == 1)
            {
                breaks.at(0) = k;
            }
            else
                breaks.at(breaks.size()-1) = breaks.at(breaks.size()-2)+1;
            breaks.push_back(breaks.at(breaks.size()-1)+1);
        }
    }
    else breaks.at(breaks.size()-1)++;
    fun(k);
}

int main()
{
    cin >> s;
    if(!isPalindromeBasic(s)) breaks.push_back(1);
    else
    {
        cout << 0 << endl;;
        return 0;
    }
    for(int i = 1; i < s.size(); i++)
    {
        fun(i);
    }
    cout << breaks.size() << endl;
    return 0;
}
