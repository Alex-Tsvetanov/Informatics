#include<iostream>
using namespace std;
int main() {
    long long dyljina,shirina,brojSgywaniq=0;
    cin>>dyljina>>shirina;
    while(dyljina>1 || shirina>1) {
        if(dyljina>shirina) {
            dyljina=dyljina/2+dyljina%2;
        } else {
            shirina=shirina/2+shirina%2;
        }
        brojSgywaniq++;
    }
    cout<<brojSgywaniq;
    return 0;
}
