#include<iostream>
using namespace std;
int a[1000000];
int main ()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int z=0;
        for(int k=i+1;k<n;k++){
            if(a[i]<a[k]){
                z++;
            }
        }
        if(z==0){
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
