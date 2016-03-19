#include <iostream>
using namespace std;

int main()
{
    char s[1000000];
    int r=0;
    for (int i=0;i<1000000;i++)
    {
        cin.get(s[i]);
        if (s[i]=='.')break;
        if (s[i]==s[i-1] && s[i]==s[i-2] && s[i-1]==s[i-2]) r++;
    }
    cout<<r<<endl;
 return 0;
}