#include<iostream>
using namespace std;
struct XY{
    int x,y;
};

long long a[201][201],b[201][201],c,d,n,j=1,i=1,k,y1,mess,m1,m2,m3,m4,l,r,br=0,m,brd=0,cun=0;
XY d1,d2;

int main(){
    cin>>m>>n;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0)br++;
        }
    }
        cout<<br/m<<endl;
    return 0;
}
//4 5 0 1 1 0 1 0 1 0 0 1 1 0 1 1 0 0 0 1 0 0

