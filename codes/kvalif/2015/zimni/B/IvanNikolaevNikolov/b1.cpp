#include <iostream>
using namespace std;

int arr[1024][1024];
int n,m,p,q;
int ans;

int patch(int x,int y){
    return arr[x+p][y+q] - arr[x-1][y+q] - arr[x+p][y-1] + arr[x-1][y-1];
}

int main (){
    cin>>m>>n>>p>>q;
    p--;
    q--;
    for(int i=0; i < m ; i++){
        for(int j=0; j < n ; j++){
            cin>>arr[i+1][j+1];
            if(j>0){
                arr[i+1][j+1] += arr[i+1][j];
            }
        }
    }

    for(int i=1; i <= m ; i++){
        for(int j=0; j <= n ; j++){
            arr[i][j]+=arr[i-1][j];
        }
    }

    for(int i=1; i <= m - p; i++){
        for(int j=1; j <= n - q; j++){
            int a = patch(i,j);
            if (a > ans) ans = a;
        }
    }

    cout<<ans<<endl;

    return 0;
}

/**
4 6 2 2

1 -1 2 3 4 -2
-3 4 -5 6 -1 0
3 -1 -2 1 4 -2
-2 4 -5 4 -1 1

*/


















