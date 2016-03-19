#include<iostream>
using namespace std;
int main()
{
long long int A,B,C;
cin>>A>>B>>C;
int br=0;
while(A>0||B>0||C>0)
{
if(A>=1){A--;br++;} else if(B>0)cout<<br-1<<endl;
if(B>=1){B--;br++;} else if(C>0)cout<<br-1<<endl;
if(C>=1){C--;br++;}
if(B>=1){B--;br++;}
}
return 0;
}
