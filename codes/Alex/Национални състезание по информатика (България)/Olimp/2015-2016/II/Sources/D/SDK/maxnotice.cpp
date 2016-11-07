#include<iostream>
using namespace std;
int main(){
    long long l, h, n, i;
    cin>>l>>h>>n;
    if(n==0){
        cout<<l*h<<endl;
        return 0;
    }
    long long s1[n], s2[n], s[n], v[n];
    for(i=0;i<n;i++){
        cin>>s1[i]>>s2[i]>>s[i]>>v[i];
    }
    cout<<(l*h)/2-(s[1]*v[1])<<endl;
    return 0;
}
