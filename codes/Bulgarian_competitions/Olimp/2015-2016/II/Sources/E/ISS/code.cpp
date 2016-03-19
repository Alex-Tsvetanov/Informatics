#include <iostream>
using namespace std;
int main ()
{
    char s[8];
    cin>>s;
    if (s[0]!=s[1]&&s[1]!=s[2]&&s[2]!=s[3]&&s[3]==s[4]&&s[4]==s[5]&&s[5]==s[6]&&s[6]!=s[7])
    cout<<"2"<<endl;
    if (s[1]=='.'&&s[0]=='a'||s[0]!='a'&&s[1]=='.')
    cout<<"0"<<endl;
    if (s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4]&&s[4]==s[5])
    cout<<"4"<<endl;



    return 0;
}
