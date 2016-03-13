#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
long long n,chisla[1000],br=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    //n=100;
    for(long long i=0;i<n;i++){
        cin>>chisla[i];
       //chisla[i]=1000000000;
    }

    for(long long i=0;i<n;i++){
            br=0;
        for(long long r=1;r<=chisla[i]/r;r++){
            if(chisla[i]%r==0 and chisla[i]/r==r){
                br++;
            }
            if(chisla[i]%r==0 and chisla[i]/r!=r){
                br=br+2;
            }
        }
        if(i!=n-1){
            cout<<br<<" ";
        }else{
            cout<<br<<"\n";
        }
    }
return 0;
}
