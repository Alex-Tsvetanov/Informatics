#include<iostream>
using namespace std;
struct XY{
    int x,y;
};

long long a[1000001],b[1000001],c,d,n,j,i,k,x1,y1,mess,m1,m2,m3,m4,l,r,br=0;
XY d1,d2;
int main(){
        cin>>n;
        for(i=1;i<=n;i++){
                cin>>a[i];
        }

            for(i=1;i<=n;i++){
                for(j=i;j<=n;j++){
                    if(a[i]<a[j]){
                        i=j-1;
                        break;
                        }
                    if(j==n)cout<<a[i]<<" ";
                    }
                }



    return 0;
}

