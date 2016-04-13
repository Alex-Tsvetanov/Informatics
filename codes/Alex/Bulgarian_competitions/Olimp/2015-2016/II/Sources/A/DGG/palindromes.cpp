#include<bits/stdc++.h>
using namespace std;
const int nmax=10009;
string s;
unsigned int hsh[4][nmax];
unsigned int ohsh[4][nmax];
unsigned int base[4]={0,37,1007};
unsigned int pw[4][nmax];
int dp[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s;
   int n=s.size();
   for(int k=1;k<=2;k++){
      pw[k][0]=1;
      for(int i=1;i<=n;i++){
         pw[k][i]=pw[k][i-1]*base[k];
      }
      for(int i=0;i<n;i++){
         if(i==0)hsh[k][i]=s[i]-'a';
         else hsh[k][i]=hsh[k][i-1]*base[k]+s[i]-'a';
      }
      for(int i=n-1;i>=0;i--){
         if(i==n-1)ohsh[k][i]=s[i]-'a';
         else ohsh[k][i]=ohsh[k][i+1]*base[k]+s[i]-'a';
      }
   }
   memset(dp,31,sizeof(dp));
   dp[0]=0;
   //for(int i=0;i<n;i++){
   //   for(int j=i;j<n;j++){
   //      int fl=1;
   //      for(int k=1;k<=2;k++)
   //         if(hsh[k][j]-hsh[k][i]*pw[k][j-i]!=
   //               ohsh[k][i]-ohsh[k][j]*pw[k][j-i])fl=0;
   //      if(fl){
   //         //cerr<<"ot "<<i<<" "<<"do "<<j<<" e palindrom\n";
   //      }
   //   }
   //}
   for(int i=1;i<=n;i++){
      for(int j=0;j<i;j++){
         int j1=i-1;
         int i1=j;
         int fl=1;
         for(int k=1;k<=2;k++)
            if(hsh[k][j1]-hsh[k][i1]*pw[k][j1-i1]!=
                  ohsh[k][i1]-ohsh[k][j1]*pw[k][j1-i1])fl=0;
         if(fl){
            //cerr<<"ot "<<j+1<<" "<<"do "<<i<<" e palindrom\n";
            //cerr<<dp[i]<<" "<<dp[j]+1<<"\n";
            dp[i]=min(dp[i],dp[j]+1);
         }
      }
      //cerr<<"dp["<<i<<"]="<<dp[i]<<"\n";
   }
   cout<<dp[n]-1<<"\n";
}
