#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
long long m,n,x,y,matrix[101][101],numbers[501],index=0,j;
long long answ[2];
for(j=0;j<2;j++){
cin>>m>>n;
for(y=0;y<m;y++){
   for(x=0;x<n;x++){
      cin>>matrix[x][y];
   }
}
for(x=0;x<n;x++){
  for(y=0;y<m;y++){
     numbers[index] += matrix[x][y];
  }
  index++;
}
for(y=0;y<m;y++){
    for(x=0;x<n;x++){
        numbers[index] += matrix[x][y];
    }
    index++;
}
sort(numbers, numbers + index);
bool choose = false;
for(y=numbers[index-1];y>=1;y--){
    for(x=0;x<index;x++){
        if(numbers[x]>=y and numbers[x] % y == 0){
          if(x==index-1){
            answ[j] = y;
            choose = true;
            break;
          }
        }else{
            break;
        }
    }
    if(choose){
       break;
    }
}
for(x=0;x<index;x++){
    numbers[x] = 0;
}
index=0;
}
cout<<answ[0]<<" "<<answ[1]<<endl;
if((answ[0] % answ[1] == 0) or (answ[1] % answ[0] == 0)){
  cout<<"Y"<<endl;
}else{
       cout<<"N"<<endl;
}
return 0;
}
