#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,d,b,c,max1,br=0,i;
string s,ss,m;
cin>>a>>b>>c;
max1=max(max(a,b),c);
for(i=1;i<=max1*3;i++){
    if(i%2==0)b--;
    if(i%4==1)a--;
    if(i%4==3)c--;
    if(b<0 || c<0 || a<0)break;
    br++;
}
cout<<br<<endl;
return 0;
}
