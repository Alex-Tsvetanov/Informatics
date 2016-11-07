#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
#define pb push_back
const int nmax=10009;
const double eps=1e-9;
struct vec {
   double x, y;
   vec(){}
   vec(double _x,double _y){x=_x;y=_y;}
   vec operator+(vec b){return vec(x+b.x,y+b.y);}
   vec operator-(vec b){return vec(x-b.x,y-b.y);}
   vec operator*(double k){return vec(k*x,k*y);}
   double len2(){return x*x+y*y;}
   vec rot(double alpha){
      return vec(x*cos(alpha)-y*sin(alpha),x*sin(alpha)+y*cos(alpha));
   }
   double len(){
      return sqrt(this->len2());
   }
};
double dot(vec u,vec v) {
   return u.x*v.x+u.y*v.y;
}
double cross(vec u,vec v) {
   return u.x*v.y-v.x*u.y;
}
int n,q,m;
struct circle{
   vec centre;
   double rad;
};
vec spots[nmax];
circle c[nmax];
int check(vec spot,double s){
   int br=0;
   for(int i=1;i<=n;i++){
      double r=c[i].rad;
      vec AB=c[i].centre-spot;
      if(AB.len2()<(s-r)*(s-r))br++;
   }
   return br;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>q;
   for(int i=1;i<=n;i++){
      cin>>c[i].centre.x>>c[i].centre.y;
      cin>>c[i].rad;
   }
   for(int i=1;i<=m;i++){
      cin>>spots[i].x>>spots[i].y;
   }
   vector<double> distances;
   for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
         vec AB=spots[i]-c[j].centre;
         //AB<s-c[j].rad
         //s>AB+c[j].rad
         double dist=(AB.len()+c[j].rad);
         distances.pb(dist);
      }
   }
   sort(distances.begin(),distances.end());
   //cout<<distances[0]<<"\n";
   int lastp=1;
   long long int ans=0;
   for(int i=1;i<=q;i++){
      double pw;
      long long tod=0;
      cin>>pw;
      if(!(lastp&1))pw*=2.0;
      tod=upper_bound(distances.begin(),distances.end(),pw-eps)-distances.begin();
      ans+=tod;
      lastp=tod;
   }
   //O(M*N+Q*log(M*N))
   cout<<ans<<"\n";
}
