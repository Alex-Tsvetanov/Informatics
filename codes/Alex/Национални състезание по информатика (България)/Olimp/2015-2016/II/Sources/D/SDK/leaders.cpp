#include<iostream>
using namespace std;
int main(){
    bool eshte=true;
    long long n, i, b;
    cin>>n;
    long long m[n];
    for(i=0;i<n;i++){
        cin>>m[i];
    }
    for(i=0;i<n;i++){
        for(b=i;b<n;b++){
            if(m[i]<m[b]){
                    eshte=false;
                    break;
            }
        }

        if(eshte==true){
            cout<<m[i]<<" ";
        }
        eshte=true;
    }
    cout<<endl;
    return 0;
}
