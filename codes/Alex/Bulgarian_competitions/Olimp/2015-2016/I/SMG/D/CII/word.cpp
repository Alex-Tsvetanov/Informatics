#include<iostream>
#include<algorithm>
using namespace std;
int word[26],sortword[26];
bool used[26];
char a='0',code[6];
int main()
{
    while(a!='#')
    {
        cin>>a;
        if(a>='a' && a<='z')
        {
            sortword[a-'a']++;
            word[a-'a']++;
        }
        if(a>='A' && a<='Z')
        {
            sortword[a-'A']++;
            word[a-'A']++;
        }
    }
    sort(sortword,sortword+26);
    int i=25;
    while(i>19 && sortword[i]!=0)
    {
        for(int j=0; j<26; j++)
            if(word[j]==sortword[i] && !used[j])
            {
                used[j]=1;
                code[25-i]=char(j+'A');
                break;
            }
            i--;
    }
    cout<<code;
    return 0;
}
/**
xyzaaabbc#

abcXXxyYZpqr#

asd dfg AsD sss 456, ttt
Eeeee 4+56789#

UUDDD11 KLWWW ppp#

I hohohoooo 77777
22 ii#

Kkkkkkddddd
iiii P 9+DD9-223*56 KKK#
*/
