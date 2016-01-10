#include<iostream>
#include<cstring>
using namespace std;
int main (){
    char A[1000000], Chislo1[10000];
    cin>>A;
    if (A[0]!='X') {
        for (long long i=0 ; i<strlen(A) ; i++) {
                if (A[i]=='+') {
                    break;
                }else{
                    A[i]=Chislo1[i];
                }
        }
     }
cout<<"0";
cout<<endl;
return 0;
}

