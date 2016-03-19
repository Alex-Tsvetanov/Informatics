#include <iostream>
using namespace std;
long long pole[200][200],M,N,s=1;
void sased(long long x,long long y,long long f){
    pole[x][y]=f;
    if(x<M-1 && pole[x+1][y]==0){pole[x+1][y]=f;sased(x+1, y, f);}
    if(x>0 &&   pole[x-1][y]==0){pole[x-1][y]=f;sased(x-1, y, f);}
    if(y<N-1 && pole[x][y+1]==0){pole[x][y+1]=f;sased(x, y+1, f);}
    if(y>0 &&   pole[x][y-1]==0){pole[x][y-1]=f;sased(x, y-1, f);}
}
int main(){
long long i,o;
cin>>M>>N;
for(o=0;o<N;o++){
    for(i=0;i<M;i++){
        cin>>pole[i][o];
        if(pole[i][o]==1){
            pole[i][o]=-2;
        }
    }
}
for(o=0;o<N;o++){
    for(i=0;i<M;i++){
        if(pole[i][o]==0){
            sased(i, o, s);
            s++;
        }
    }
}
cout<<s-1;
return 0;
}
