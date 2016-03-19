#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int p = 3;
    int br = 0;
    for(int i = 1; i < n; i++){
        if((n - i) % p == 0){
            if(i % 2 != 0);
            else br++;
        }
        p = p + 2;
    }
    cout << br << endl;


    return 0;
}
