#include<iostream>
using namespace std;
int main () {

    int m , mCounter;
    int n , nCounter ;
    cin >> n >> m ;
    nCounter=0;
    mCounter=0;
    while(n!=1){
        if(n%2==0){
            n=n/2;
            nCounter++;
        }else{
            n--;
            nCounter++;
        }
    }
    while(m!=1){
        if(m%2==0){
            m=m/2;
            mCounter++;
        }else{
            m--;
            mCounter++;
        }
    }
    cout << nCounter+mCounter;

return 0;
}
