#include<iostream>
using namespace std;
int main()
{
long long A,B,C,br=0;
cin>>A>>B>>C;
while(1)
{
A--;
if(B<=0)break;
else br++;
B--;
if(C<=0)break;
else br++;
C--;
if(B<=0)break;
else br++;
B--;
if(A<=0)break;
else br++;
}
cout<<br+1<<endl;



return 0;
}
