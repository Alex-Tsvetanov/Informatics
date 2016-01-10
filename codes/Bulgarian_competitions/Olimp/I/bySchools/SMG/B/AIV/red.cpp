#include<iostream>
using namespace std;
void vhod(int n, int a[]){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    vhod(n,a);

    int malko,golemo;
    int mIndex, gIndex;
    mIndex=1;
    gIndex=n;

    malko = a[0];
    golemo = a[n-1];

    for(int i=1;i<n;i++){
        if(a[i]<malko){
            malko = a[i];
            mIndex = i+1;
            //cout<<malko<<" "<< mIndex<<endl;
        }
    }
    //cout<<malko<<" "<< mIndex<<endl;
    for(int i=n-1;i>=0;i--){
        if(a[i]>golemo){
            golemo = a[i];
            gIndex = i+1;
            //cout<<golemo;//<<" "<< gIndex<<endl;
        }
    }
     //cout<<golemo<<" "<<gIndex<<endl;
    //cout<< malko<< " "<< mIndex+3;

    if(mIndex<gIndex){
        cout<<mIndex<<" "<<gIndex;
        return 0;
    }else{
        for(int i=n-1;i>=0;i--){
            if(a[i]==golemo){
                gIndex=i+1;
            }
        }
        cout<<gIndex<<" "<<mIndex;
    }

    return 0;
}
