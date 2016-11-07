#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    char a, prev;
    int br = 0, i = 0, l = 0;
    cin >> a;
    int g = 0;
    while(a != '.'){
        cin >> a;
        if(prev == a)br++;
        if(prev != a and i != 0){
            if(br == 0)br++;
            else{
                if(br == 1){
                    br = 1;
                    l++;
                }
                else{
                    br = 1;
                    l = l + 2;
                }
            }
        }
        if(i == 0)br++;
            prev = a;
            i++;
        }
    cout << i - l - 1 << endl;

    return 0;
}
