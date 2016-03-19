#include <bits/stdc++.h>
using namespace std;

string input;
int bestAns = 10001;

bool isPalindrome(int pos, int len)
{
    for (int i=0;i<len/2;i++)
        if (input[pos+i]!=input[pos+len-i-1])
            return false;
    return true;
}

void recurse(int pos, int res)
{
    if (pos == input.size() && res<bestAns)
    {
        bestAns = res;
        return ;
    }

    //cout<<pos<<' '<<res<<endl;

    for (int i=1;i<=input.size() - pos;i++)
        if (isPalindrome(pos, i))
        {
            recurse(pos+i, res+1);
        }
}

int main()
{
    //ifstream in("zad2test.in");
    cin>>input;

//    calcPref();
//    calcSuf();
    recurse(0, 0);

    cout<<bestAns-1<<endl;

    return 0;
}
