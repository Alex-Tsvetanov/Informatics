#include <iostream>
using namespace std;

int main () {

 long long T1,T2,T3,N,k=4,C[20];

 cin >> T1 >> T2 >> T3 >> N;

 C[1]=T1;
 C[2]=T2;
 C[3]=T3;


 while (k<=N) {
    C[k] = C[k-1]+C[k-2]+C[k-3];
    k++;
 }

 cout << C[N] << endl;

 return 0;
}
