#include<iostream>
#include<queue>
using namespace std;
int main (){
    queue<int>a;
    int st=0;
    int stn=0;
int P, M, K;
cin>>P>>M;
int col1[100000],col2[100000];
for(int i=0;i<M;i++){
    cin>>col1[i]>>col2[i];
}
cin>>K;
if(K==0){
    cout<<0<<endl;
    return 0;
}
for(int i=1;i<=P;i++){
    st=i;
    stn=0;
    for(int q=0;q<M;q++){
        if(col1[q]==st or col2[q]==st){
            stn++;
            if(stn>=K){
                a.push(st);
                break;
            }
        }
    }

}
cout<<a.size()<<endl;
for(int i=0;i<a.size();i++){
    cout<<a.front()<<" ";
    a.pop();
}
cout<<a.back()<<endl;
return 0;
}




