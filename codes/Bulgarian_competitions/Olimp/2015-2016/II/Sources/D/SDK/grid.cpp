#include<iostream>
using namespace std;
int main(){
    long long m, n, j, sv0=1;
    cin>>m>>n;
    long long c[m*n], i, dm[m][n];
    for(i=0;i<m*n;i++){
        cin>>c[i];
    }
    for(i=0;i<m;i++){
        for(j=0;j<brn+n;j++){
            dm[i][j]=c[j];
        }
        brn+=n;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(dm[i][j]==0 and dm[i-1][j]!=0 and dm[i][j-1]!=0){
                sv0++;
            }
        }
    }
    cout<<sv0<<endl;
    return 0;
}
