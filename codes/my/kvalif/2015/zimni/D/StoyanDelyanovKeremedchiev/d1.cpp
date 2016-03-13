#include<iostream>
using namespace std;
int main(){
     long long t1, t2, t3, n, i, sb=0;
     cin>>t1>>t2>>t3>>n;
     if(n==1){
          cout<<t1<<endl;
          return 0;
     }
     if(n==2){
          cout<<t2<<endl;
          return 0;
     }
     if(n==3){
          cout<<t3<<endl;
          return 0;
     }
     for(i=3;i<n;i++){
          sb=t1+t2+t3;
          t1=t2;
          t2=t3;
          t3=sb;
     }
     cout<<sb<<endl;
     return 0;
}
