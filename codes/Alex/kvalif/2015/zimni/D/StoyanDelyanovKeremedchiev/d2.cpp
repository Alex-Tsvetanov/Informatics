#include<iostream>
#include<cstring>
using namespace std;
int main(){
     long long n, i;
     cin>>n;
     char a[n];
     for(i=0;i<n;i++){
          cin>>a[i];
     }
     if(n%2==0){
          cout<<n<<endl;
          for(i=n;i>=0;i--){
               cout<<a[i];
          }
     }
     if(n%2>0){
          cout<<n-1<<endl;
          for(i=n-2;i>=0;i--){
               cout<<a[i];
          }
     }
     cout<<endl;
     return 0;
}
