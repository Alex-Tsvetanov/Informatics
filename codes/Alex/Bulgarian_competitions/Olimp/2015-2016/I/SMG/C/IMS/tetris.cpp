#include<iostream>
#include<cstring>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long redove,koloni,x,y,k=0,to4ki=0;
    char c;
    cin>>redove>>koloni;
    for(x=0;x<redove;x++){
        bool cqlLiE=true;
        for(y=0;y<koloni;y++){
            cin>>c;
            if(c!='*'){
                cqlLiE=false;
            }
        }
        if(cqlLiE){
            k++;
        }else{
            to4ki=to4ki+k*(k+1)/2;
            k=0;
        }
    }
    to4ki=to4ki+k*(k+1)/2;
    cout<<to4ki<<"\n";
    return 0;
}
