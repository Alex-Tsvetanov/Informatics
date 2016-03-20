#include <iostream>
using namespace std;
int main(){
    int p,n,s,sum=0,t;
    cin >> p >> n >> s;
    int a[n-1];
    for(int i=0; i<n; i++){
        a[n-1]=0;
    }
    for(int i=0; i<p; i++){
        while(sum != p){
            a[i]++;
            //===================
            if(a[i] > s){
                a[i] = 0;
            }
            sum=p*n+1;
        }
    }
    cout << sum <<endl;
    return 0;
}
