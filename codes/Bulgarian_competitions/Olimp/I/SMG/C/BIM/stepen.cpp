#include<iostream>
#include<vector>
using namespace std;

int main (){
    long long n;
    cin>>n;
    long long f=n/2,f1=n/2;
    int broi=0;
    long long k=0;
    vector<long long> a;
    vector<int> b;
    for(int i=0;;i++){
        if(f*f<=n){
            break;
        }
        f1=f;
        f=f/2;
    }
    for(int i=2;i<f1+1;i++){
        k=i;
        for(int j=1;k<n+2;j++){
            k=k*i;
            if(k==n){
                a.push_back(i);
                b.push_back(j+1);
                broi++;
                break;
            }
        }
    }
    cout<<broi<<endl;
    for(int i=broi-1;i>=0;i--){
        cout<<a[i]<<" ";
        cout<<b[i]<<endl;
    }
}


