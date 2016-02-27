#include<iostream>
using namespace std;
int main(){
int a=0;
char b[9];
for(int i=0;i<9;i++){
 cin >> b[i];
}
 for(int i=0;i<=9;i++){
   if(b[i]!=b[i]+5){
    cout << b ;
   }else{ cout << ' ';
   }
 }

return 0;
}
