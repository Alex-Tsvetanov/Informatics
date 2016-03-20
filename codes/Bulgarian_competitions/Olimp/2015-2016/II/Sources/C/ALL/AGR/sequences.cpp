#include<iostream>
using namespace std;
long long p,n,s;
int main(){
    cin>>p>>n>>s;
    long long ways[s][n];
    for(long long i=0;i<n;i++){
        ways[0][i]=1;
    }
    for(long long i=1;i<s;i++){
        if(i<p) ways[i][0]=1;
        else    ways[i][0]=0;
        for(long long j=1;j<n;j++){
            ways[i][j]=0;
            for(long long k=0;k<p && i-k>=0;k++){
                ways[i][j]+=ways[i-k][j-1];
            }
        }
    }
    /*for(long long i=0;i<s;i++){
        for(long long j=0;j<n;j++){
            cout<<ways[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    long long ans=0;
    for(long long i=0;i<s;i++){
        ans+=ways[i][n-1];
    }
    cout<<ans;
    return 0;
}
