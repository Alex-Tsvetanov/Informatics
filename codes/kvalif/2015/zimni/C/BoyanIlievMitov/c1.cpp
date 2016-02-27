#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long mas[n];
    long long write[n];
    for (int i =0; i<n;i++){
        cin>>mas[i];
        write[i]=0;
    }

    long long max1=0;
//    for(int i=0;i<n;i++){
 //       if(mas[i]>max1){
  //          max1=mas[i];
   //     }
   // }
    for(int i=0;i<n;i++){
        for(int j =1;j<=mas[i];j++){
            if(mas[i]%j==0){
                write[i]++;
            }
        }
    }
    for (int i =0; i<n;i++){
        cout<<write[i]<<" ";
    }

    cout<<endl;

return 0;
}

