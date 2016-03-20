#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long k=0;
    for(long long i=1;i<n;i*=2){
        k++;
    }
    cout<<k;
    if(n<=500){
        vector  <int> bits[k];
        for(int i=1;i<=n;i++){
            int j=i-1,b=0;
            while(j>0){
                if(j%2==1){
                    bits[b].push_back(i);
                }
                j/=2;
                b++;
            }
        }
        cout<<endl;
        for(int i=0;i<k;i++){
            cout<<bits[i].size();
            for(int j=0;j<bits[i].size();j++){
                cout<<' '<<bits[i][j];
            }
            if(i+1<k)cout<<endl;
        }
    }
}
