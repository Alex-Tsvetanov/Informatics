#include<iostream>
#include<cstring>
using namespace std;
int i, n1,a[100000001],n2,br,a1,j,as1,as2;
char sotg[6];
bool fl;
int main () {
for(i=1;i<=5;i++) {
 sotg[i]='9';
 cin>>n1;
 for(j=1;j<=n1;j++) {
  cin>>a[j];
 }
 cin>>n2;
 br=0;
 fl=0;
 for(j=1;j<=n2;j++) {
  cin>>a1;
  if(j==1) {
   as1=a1;
  }
  if(j==n2) {
   as2=a1;
  }
  if(fl==0 && a1==a[br+1] && br+1<=n1) {
   br++;
  }
  else {
   if(fl==0) {
    if(br!=0) {
     if(br==n1 ) {
      sotg[i]='0';
      br=0;
      fl=1;
     }
     else {
      br=0;
     }
    }
   }
  }
 }
 if(br>=1) {
   sotg[i]='0';
   fl=1;
 }
 if(fl==0) {
    sotg[i]='1';
 }
if(as1==a[n1] || as2==a[1]) {
    sotg[i]='0';
}


}
for(i=1;i<=5;i++) {
 cout<<sotg[i];
}
cout<<endl;

return 0;
}
/*
3 1 2 3
4 1 3 5 6
3 5 1 4
4 150 1 20 5
4 1 5 6 2
3 2 1 6
5 100 20 45 10 3
4 3 100 80 10
5 90 1 4 8 80
5 90 1 8 100 5
*/
