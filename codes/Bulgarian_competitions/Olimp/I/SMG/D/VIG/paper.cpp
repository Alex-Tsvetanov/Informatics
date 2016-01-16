#include<iostream>
using namespace std;
int main(){
    int m, n, kolko=0, a=2;
    cin>>m>>n;
    while(m!=1){
        a=2;
        while(m%a!=0){
            a++;
        }
        m-=(m/a);
        kolko++;
    }
    a=2;
    while(n!=1){
        a=2;
        while(n%a!=0)a++;
        n-=(n/a);
        kolko++;
    }
    cout<<kolko<<endl;
    return 0;
}
