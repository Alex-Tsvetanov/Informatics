#include<iostream>
#include<cstring>

using namespace std;

int main (){
    string chis;
 int mas[3000];
bool pro[27551];
 int i=0;
 long long sum=0;
 cin>>chis;
 for (i=0;chis[i]=='0'||chis[i]=='1';i++){
    if(chis[i]=='0'){
        mas[i]=0;
    }else{
        mas[i]=1;
    }

 }
 pro[0]=false;
 pro[1]=false;
 for (int l=0;l<27550;l++){
    pro[l]=true;
 }
for (int j=2;j<13776;j++){

    for(int k=j+j;k<27550;k=k+j){
        pro[k]=false;
    }
 }

 int m=0;
 for(int j=2;j<27550;j++){

    if(m==i){
        break;
    }
    if(pro[j]==true){
        sum=sum+(mas[m]*j);
        m++;
    }

 }

cout<< sum;
return 0;
}
