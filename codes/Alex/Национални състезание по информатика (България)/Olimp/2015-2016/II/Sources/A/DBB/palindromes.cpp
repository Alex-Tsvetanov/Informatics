#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s,s1;
    cin>>s;
    s1=s;
    reverse(s1.begin(),s1.end());
    cout<<((s1==s)?0:(s.size()))<<endl;
    return 0;
}
