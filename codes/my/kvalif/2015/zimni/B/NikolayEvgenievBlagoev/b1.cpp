#include <iostream>
using namespace std;
int main (){
int M,N,m,n;
cin>>N>>M>>n>>m;
int x,y,nicky;
int matrix[N][M],rows[N-n+1][M];
int c = N-n+1;
for(y=0;y<c;y++){
for(x=0;x<M;x++){
rows[y][x]=0;
}
}
for(y=0;y<N;y++){
for(x=0;x<M;x++){
cin>>nicky;
matrix[y][x]=nicky;

for(int i = y; i> y-n&&i>=0;i--){
rows[i][x]+=nicky;

}
}
}
int ng=-100000000;


for(y=0;y<c;y++){
int sbor=0;
for(int i=0;i<m;i++){
sbor+=rows[y][i];
}

if(sbor>ng){
ng=sbor;

}
for(x=m;x<M;x++){
sbor+=(rows[y][x]-rows[y][x-m]);

}

if(sbor>ng){
ng=sbor;

}
}
cout<<ng;
}
