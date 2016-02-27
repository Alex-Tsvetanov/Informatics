#include<iostream>
using namespace std;
long long B[100001];
int main(){
    long long N;
    cin>>N;
    long long M[N];
    for(long long i=0;i<N;i++){
        cin>>M[i];
        for(long long j=1;j<=M[i]/2+1;j=j+1){
            if(M[i]%j == 0){
                B[i] = B[i] + 1;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<B[i]+1<<" ";
    }
    cout<<endl;


    return 0;
}
///
