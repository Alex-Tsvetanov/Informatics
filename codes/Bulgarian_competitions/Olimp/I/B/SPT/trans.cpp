#include<iostream>
#include<map>
#include<set>
using namespace std;
map<long long, long long>m;
set<long long>s;
long long p,n,k,br;
int main(){
cin>>p>>n;
for(int i=0;i<n;i++)
{
    int a,b;
    cin>>a>>b;
    m[a]++;
    m[b]++;
    s.insert(a);
    s.insert(b);
}
cin>>k;
bool ok=false;
for(set<long long>:: iterator it = s.begin();it!=s.end();it++)
{
    if(m[*it]>=k){
       br++;
    }
}
cout<<br<<endl;
if(br==0)return 0;
for(set<long long>:: iterator it = s.begin();it!=s.end();it++)
{
    if(m[*it]>=k){
       if(ok)
        cout<<" ";
       cout<<*it;
        ok=1;
    }
}
cout<<endl;
/// TESTVAJ!!!
return 0;
}
