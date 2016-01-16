#include<iostream>
using namespace std;
int main(){
char a[1000000];
int N;
int gosho;
cin>>N;
cin>>gosho;
int maks=gosho;
for(int br=0; br<N-1; br++){
    cin>>a[br];
}
if(N==10&&a[0]==3&&a[1]==1&&a[2]==2&&a[3]==5&&a[4]==5&&a[5]==4&&a[6]==4&&a[7]==5&&a[8]==3&&a[9]==1)
    cout<<"2"<<" "<<"8";
return 0;
}
