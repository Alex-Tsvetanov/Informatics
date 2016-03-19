#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define pb push_back
const int nmax=1009;
unordered_map<char,bool> mp;
string s;
string st;
vector<bool>res[nmax];
inline bool calcvec(vector<bool> &curr){
   bool lst;
   lst=curr[0];
   for(int i=1;i<(int)curr.size();i++){
      lst=!(lst&curr[i]);
   }
   curr.clear();
   return lst;
}
int n;
bool st2[nmax];
inline void solve(){
   mp.clear();
   //for(int i=0;i<(int)n;i++){
   //   mp['a'+i]=st[i]-'0';
   //}
   int lvl=0;
   for(int i=0;i<(int)n;i++){
      if(s[i]=='('){
         lvl++;
      }
      if(s[i]==')'){
         bool result=calcvec(res[lvl]);
         lvl--;
         res[lvl].pb(result);
      }
      if(s[i]>='a'&&s[i]<='z'){
         res[lvl].pb((st2[(int)(s[i]-'a')]));
      }
   }
   //for(int i=0;i<res[0].size();i++){
   //   cerr<<(int)res[0][i];
   //}
   //cerr<<"\n";
   cout<<calcvec(res[0]);
   //cerr<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s;
   cin>>st;
   n=s.size();
   while(st!="2"){
      for(int i=0;i<n;i++)st2[i]=st[i]-'0';
      solve();
      cin>>st;
   }
   cout<<"\n";
}
