#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
string s;
long long i,br1=0,br2=0,d;
cin>>s; d=s.size();
for(i=1;i<d;i++)
{

if(s[i]==s[i+1]) br1++;
if(s[i-1]==s[i] && s[i]!=s[i+1]) {br1=br2;break;}
cout<<br2<<s[i];
if(s[i-1]!=s[i] && s[i]!=s[i+1]) cout<<s[i];

}cout<<endl;
return 0;
}
