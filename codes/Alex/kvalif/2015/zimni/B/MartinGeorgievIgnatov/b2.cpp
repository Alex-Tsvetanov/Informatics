#include <iostream>
using namespace std;

int m,n,t,g1x,g1y,g2x,g2y,all;
bool arr[1005][1005];

int rekd(int curx,int cury,int dal,int prev){
    if(dal<t){
        if(prev==10){
            if(cury+1<n){
                if(arr[cury+1][curx]==0){
                    arr[cury+1][curx]=1;
                    all--;
                }
                rekd(curx,cury+1,dal+1,10);
            }
            if(curx+1<m){
                if(arr[cury][curx+1]==0){
                    arr[cury][curx+1]=1;
                    all--;
                }
                rekd(curx+1,cury,dal+1,1);
            }
        }
        else if(prev==1){
            if(curx+1<m){
                if(arr[cury][curx+1]==0){
                    arr[cury][curx+1]=1;
                    all--;
                }
                rekd(curx+1,cury,dal+1,1);
            }
            if(cury-1>=0){
                if(arr[cury-1][curx]==0){
                    arr[cury-1][curx]=1;
                    all--;
                }
                rekd(curx,cury-1,dal+1,-10);
            }
        }
        else if(prev==-10){
            if(cury-1>=0){
                if(arr[cury-1][curx]==0){
                    arr[cury-1][curx]=1;
                    all--;
                }
                rekd(curx,cury-1,dal+1,-10);
            }
            if(curx-1>=0){
                if(arr[cury][curx-1]==0){
                    arr[cury][curx-1]=1;
                    all--;
                }
                rekd(curx-1,cury,dal+1,-1);
            }
        }
        else if(prev==-1){
            if(curx-1>=0){
                if(arr[cury][curx-1]==0){
                    arr[cury][curx-1]=1;
                    all--;
                }
                rekd(curx-1,cury,dal+1,-1);
            }
            if(cury+1<n){
                if(arr[cury+1][curx]==0){
                    arr[cury+1][curx]=1;
                    all--;
                }
                rekd(curx,cury+1,dal+1,10);
            }
        }
        else if(prev==0){
            if(cury+1<n){
                if(arr[cury+1][curx]==0){
                    arr[cury+1][curx]=1;
                    all--;
                }
                rekd(curx,cury+1,dal+1,10);
            }
            if(curx-1>=0){
                if(arr[cury][curx-1]==0){
                    arr[cury][curx-1]=1;
                    all--;
                }
                rekd(curx-1,cury,dal+1,-1);
            }
            if(cury-1>=0){
                if(arr[cury-1][curx]==0){
                    arr[cury-1][curx]=1;
                    all--;
                }
                rekd(curx,cury-1,dal+1,-10);
            }
            if(curx+1<m){
                if(arr[cury][curx+1]==0){
                    arr[cury][curx+1]=1;
                    all--;
                }
                rekd(curx+1,cury,dal+1,1);
            }
        }
    }
}

int main(){

cin>>n>>m>>t;

cin>>g1y>>g1x;
cin>>g2y>>g2x;

arr[g1y-1][g1x-1]=1;
arr[g2y-1][g2x-1]=1;

all=n*m-2;
//all++;

rekd(g1x-1,g1y-1,0,0);
rekd(g2x-1,g2y-1,0,0);

cout<<all<<endl;

/*for(int i=n-1;i>=0;i--){
    for(int j=0;j<m;j++){
        cout<<arr[i][j]<<"   ";
    }
    cout<<endl;
}*/

return 0;
}
