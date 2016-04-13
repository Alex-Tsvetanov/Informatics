#include <iostream>
using namespace std;
int main(){
int M,N,m,n,best=0;
cin>>M>>N>>m>>n;
int arr[M][N];
int arrx[M][N];
int arry[M][N];

for(int i=0;i<M;i++){
    for(int j=0;j<N;j++)cin>>arr[i][j];
}

int all=0;

for(int y=0;y<M;y++){
    for(int x=0;x<N;x++){
        if(x<n-1){
            all+=arr[y][x];
        }
        else{
            all+=arr[y][x];
            arrx[y][x-n+1]=all;
            all-=arr[y][x-n+1];
        }
    }
    all=0;
}

for(int x=0;x<N-n+1;x++){
    for(int y=0;y<M;y++){
        if(y<m-1){
            all+=arrx[y][x];
        }
        else{
            all+=arrx[y][x];
            //arry[y-m+1][x]=all;
            if(all>best)best=all;
            all-=arrx[y-m+1][x];
        }
    }
    all=0;
}

/*for(int i=0;i<M-m+1;i++){
    for(int j=0;j<N-n+1;j++)cout<<arry[i][j]<<"   ";
    cout<<endl;
}*/

cout<<best<<endl;

return 0;
}
