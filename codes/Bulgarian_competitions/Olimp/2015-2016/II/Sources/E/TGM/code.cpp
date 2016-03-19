#include <iostream>
#include <cstring>
using namespace std;

int main (){
    long long i,n=0,a1,a2,d,e=0;
    char A[1000000];
    cin.getline(A,'.');
    for(i=0;A[i]!='.';i++){}
    a2=i;
    for(i=0;A[i]!='.';i++){
        if(n!=0 and i==a2){
            if(n<9){
                e=e+n-1;
            }
            if(n<100 and n>9){
                e=e+n-2;
            }
            if(n<1000 and n>99){
                e=e+n-3;
            }
            if(n<10000 and n>999){
                e=e+n-4;
            }
            if(n<100000 and n>9999){
                e=e+n-5;
            }
            if(n<=1000000 and n>99999){
                e=e+n-6;
            }
        }
        if(A[i]==A[i+1] and i!=0){
            n++;
        }else{
            if(n!=0){
                if(n<9 and i!=0){
                    e=e+n-1;
                }
                if(n<100 and n>9 and i!=0){
                    e=e+n-2;
                }
                if(n<1000 and n>99 and i!=0){
                    e=e+n-3;
                }
                if(n<10000 and n>999 and i!=0){
                    e=e+n-4;
                }
                if(n<100000 and n>9999 and i!=0){
                    e=e+n-5;
                }
                if(n<=1000000 and n>99999 and i!=0){
                    e=e+n-6;
                }
            }
                n=0;
        }
        if(A[i]==A[i+1] and i==0){
            n++;
        }
    }
    cout << e << endl;
    a1=i-e;
    cout << a1 << " " << a2 << endl;
    if(a1<a2){
        cout << a2-a1 << endl;
    }else{
        cout << a1-a2 << endl;
    }
return 0;
}
