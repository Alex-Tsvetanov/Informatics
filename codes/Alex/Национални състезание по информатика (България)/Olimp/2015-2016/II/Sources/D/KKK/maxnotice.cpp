#include<iostream>
using namespace std;
bool daskaB[101][101];
int daskaI[101][101];
int main(){
    long long l,h,n;
    cin>>l>>h>>n;
    int cinX,cinY,a,b;
    for(int i=0;i<n;i++){
        cin>>cinX>>cinY>>a>>b;
        for(int k=0;k<a;k++){
            for(int j=0;j<b;j++){
                daskaB[cinX+k][cinY+j]=1;
            }
        }
    }
    for(int y=0;y<h;y++){
        for(int x=l-1;x>=0;x--){
            if(daskaB[x][y]==1){
                daskaI[x][y]=0;
            }else if(x==l-1){
                daskaI[x][y]=1;
            } else {
                daskaI[x][y]=daskaI[x+1][y]+1;
            }
        }
    }
    int ans=0;

    for(int x=0;x<l;x++){
        for(int y1=0;y1<h;y1++){
                int maxL=200;
            for(int y2=y1;y2<h;y2++){
                if(daskaI[x][y2]<maxL){
                    maxL=daskaI[x][y2];
                }
                if((y2-y1+1)*maxL>ans){
                    ans=(y2-y1+1)*maxL;
                }
            }
        }
    }
    cout<<ans<<endl;
return 0;
}
