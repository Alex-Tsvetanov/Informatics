#include<iostream>
#include<algorithm>
using namespace std;
struct timeframe{
int x,y;
};
 timeframe b[1048576];
bool cmp(timeframe n,timeframe m)
{if(m.x>n.x) return 1;
if(n.x>m.x) return 0;
if(m.y>n.y) return 1;
else return 0;}
int main()
{
 long long d,a,pilot;

 cin>>d>>a>>pilot;
 for(long long i=0;i<a;i++)
 {cin>>b[i].x>>b[i].y;}
 sort(b,b+a,cmp);
 long long ind=0,flag=0;
 for(long long i=b[0].x;i<d;i++)
 {if(i==6) i+=2;
     for(long long j=0;j<pilot/2;j++)
     {
        if( b[ind].y<i) { flag++; break;}
         if(b[ind].x<=i) ind++;
        if(ind==a) {cout<<"OK"<<endl; return 0;}
     }
 if(flag>0) break;}
 if(flag==0) {cout<<"OK"<<endl; return 0;}
 flag=0; ind=0;
  for(long long i=b[0].x;i<d;i++)
 {
     for(long long j=0;j<pilot/2;j++)
     {
         if(b[ind].y<i) { flag++; break;}
         if(b[ind].x<=i) ind++;
         if(ind==a) {cout<<"MIXED"<<endl; return 0;}
     }
if(flag>0) break; }
 if(flag==0) cout<<"MIXED"<<endl;
 else cout<<"IMPOSSIBLE"<<endl;
 return 0;
}
