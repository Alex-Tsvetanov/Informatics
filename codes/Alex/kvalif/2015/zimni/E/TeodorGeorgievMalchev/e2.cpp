#include <iostream>
using namespace std;

int main (){
    long long A[20],n,i=0,a1,A1[20];
    cin >> A[0] >> A[1] >> A[2] >> n;
    A1[i+2]=A[i]+A[i+1]+A[i+2];
    while(i+3<n){
        A1[i+3]=A[i]+A[i+1]+A1[i+2];
        if(n!=4){
            i=i+3;
        }else{
            i=i+2;
        }
    }
    cout << A1[i] << endl;
return 0;
}
