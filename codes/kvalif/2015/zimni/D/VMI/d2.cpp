#include<iostream>
using namespace std;
int main(){

    long long N,i=0;
    long long br=0;
    cin>>N;

    char string1[N+1];
    for(i=0;i<N;i++){
        cin>>string1[i];
    }
    for(i=0;i<N;i++){
     if(string1[i]==string1[(N-i)-1]){
        br++;


     }
        if(br==N){
            cout<<0<<endl;
            return 0;
        }
    }

    cout<<(N-br)<<endl;
    for(i=(N-br);i>=0;i--){
        cout<<string1[i];
    }
    cout<<endl;
    return 0;
}
