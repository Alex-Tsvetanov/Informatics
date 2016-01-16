#include<iostream>
using namespace std;

int main(){
    int p,m;
    cin>>p>>m;
    int a[m],b[m];

    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }

    int k;
    cin>>k;

    int counter[p];
    for(int i=0;i<p;i++){
        counter[i]=0;
    }

    for(int i=0;i<m;i++){
        for(int j=1;j<=p;j++){
            if(a[i]==j or b[i]==j){
                counter[j-1]++;
            }
        }

    }

    int broi=0;
    for(int i=0;i<p;i++){
        if(counter[i]>=k){
            broi++;
        }
    }

    cout<<endl<<broi<<endl;;

    for(int i=0;i<p;i++){
        if(counter[i]>=k){
            cout<<i+1<<" ";
        }
    }

    return 0;
}
