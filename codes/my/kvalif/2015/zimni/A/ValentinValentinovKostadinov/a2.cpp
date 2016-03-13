#include<cstdio>
#include<iostream>
using namespace std;
int main(){
typedef unsigned long int etw;
etw M,N;
scanf("%d",&M);
scanf("%d",&N);
etw a[M],b[M];
etw all = N;
for(etw i=0;i<N;i++){
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
}
for(etw i = 0;i<N-1;i++){
    for(etw j=i+1;j<N;j++){
        if(a[i] > a[j]){
                swap(a[i],a[j]);
        swap(b[i],b[j]);
    }
}
}
for(etw i = 0;i<N;i++){
    for(etw j =i+1;j<i+2;j++){
    if(a[j] < a[i] and b[i] < a[j]){  continue;}
    if(a[j] > a[i] and a[j] > b[i]) { continue;}
    else {
        a[j] = a[i];
    b[j] = b[i];
            all--;}
}
}
printf("%d",all);
return 0;
}
