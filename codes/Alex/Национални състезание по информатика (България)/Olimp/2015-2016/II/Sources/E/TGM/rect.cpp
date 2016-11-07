#include <iostream>
using namespace std;

int main (){
    long long n,broi=0,a,b,a1;
    cin >> n;
    for(a=1;a<n;a++){
        for(b=1;b<=a;b++){
            if(n==a+b){
                if(b%(a/b+1)==0){
                    if(a%(b/a+1)==0){
                        broi++;
                    }
                }
            }
        }
    }
    cout << broi-1 << endl;
return 0;
}
