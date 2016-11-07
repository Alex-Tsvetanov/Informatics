#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, p, s, j=0;
long long sum=0;
long long br=0;
void rec(){
    if(j==n){
        if(sum<s) br++;
        return;
    }
    for(int i=0;i<p;i++){
        sum+=i;
        if(sum<s){
            j++;
            rec();
            j--;
        }
        sum-=i;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>p>>n>>s;
    rec();
    cout<<br<<endl;
    return 0;
}
