#include<iostream>
#include<queue>
using namespace std;
int main(){
    int maxx=-100;
    int br=0;
int N,M,n,m;
cin>>M>>N>>m>>n;
int box[M][N];

for(int i=0;i<M;i++){
    for(int i2=0;i2<N;i2++){
        cin>>box[i][i2];
    }
}



for(int i=0;i<M-m+1;i++){
    for(int i2=0;i2<N-n+1;i2++){

            for(int m1=i;m1<i+m;m1++){
                for(int n1=i2;n1<i2+n;n1++){
                    br=br+box[m1][n1];

                }
            }

          if(br>maxx){
            maxx=br;
          }
          br=0;
    }
}

cout<<maxx;



return 0;
}

