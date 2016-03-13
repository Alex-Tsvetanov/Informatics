#include <iostream>
using namespace std;
int M,N,m[201],n[200001];
int maxx=0,maxi=0;

int sortt(){
    bool nik=1;

    while(nik){
        nik=0;
        for(int i=1;i<M;i++){
            if(m[i-1]>m[i]){
                swap(m[i-1],m[i]);
                nik=1;
            }
        }
    }
}

int rekd(int br,int pos){
    if(br>maxx){
        maxx=br;
        maxi=pos;
    }
    for(int i=0;i<M;i++){
        if(pos+m[i]>N)break;
        rekd(br + n[ pos + m[i] ] , pos + m[i]);
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>m[i];
    }
    for(int i=0;i<=N;i++){
        cin>>n[i];
    }
    sortt();
    //for(int i=0;i<M;i++)cout<<m[i]<<" ";
    //cout<<endl;
    rekd(n[0],0);

    cout<<maxx<<" "<<maxi<<endl;

return 0;
}
