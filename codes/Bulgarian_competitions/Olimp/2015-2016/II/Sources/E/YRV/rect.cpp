#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long a,b,br=0,d,r=0,d1,j,v,n,i;
int main()
{
string s,ss,m;
cin>>n;
v=sqrt(n);
for(i=1;i<=v;i++){
    for(j=1;j<=v;j++){
        if(2*(i*j)+i+j==n){
                if(i==j){
                    br=br+2;
                }
                else
                br++;
        }
    }
}
if((n-1)%3==0)br=br+2;
cout<<br/2<<endl;

return 0;

}
