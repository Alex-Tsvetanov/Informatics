#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[m][2];
    for(int i=0;i<m;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    bool arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++){
        arr1[i]=false;
        arr2[i]=0;
    }
    int change;
    int change1;
    for(int i=0;i<m;i++){
        change=arr[i][1];
        change1=arr[i][0];
        if(arr2[change-1]<=arr2[change1-1]){
            arr1[change-1]=true;
            arr2[change1-1]++;
        }else{
            arr1[change1-1]=true;
            arr2[change-1]++;
        }


    }
    int broi=0;
    for(int i=0;i<n;i++){
        if(arr1[i]==true){
            broi++;
        }
    }
    cout<<n-broi<<endl;

return 0;
}
