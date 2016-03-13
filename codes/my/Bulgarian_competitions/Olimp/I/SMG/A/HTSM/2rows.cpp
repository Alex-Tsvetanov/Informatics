#include<iostream>

using namespace std;
typedef unsigned long long l;

int mas[100000000];
l help[100000];

int main(){

    int n,m;
    l b;
    for(int i=0;i<5;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> b;
            mas[b] = j+1;
            help[j] = b;
        }
        cin >> m;
        int k = -1;
        bool ok = true;
        for(int j=0;j<m;j++){
            cin >> b;
            if(ok){
                if(mas[b]>k){
                    k = mas[b];
                }else if(mas[b] < k && mas[b] != 0){
                    ok = false;
                }
            }
        }
        if(ok)cout << 1;
        else cout << 0;
        for(int j=0;j<n;j++)mas[help[j]] = 0;
    }

    return 0;
}
