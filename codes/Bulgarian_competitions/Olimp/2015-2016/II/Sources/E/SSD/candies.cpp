#include <iostream>
using namespace std;

int main()
{   long long A,B,C;
    cin >> A >> B >> C;
    while(A||B||C>0){
            A=A-1;
            B=B-1;
            C=C-1;
     if(A==0){
        cout << A+B+C << endl;
    } if(B==0){
        cout << A+B+C << endl;
    } if(C==0){
        cout << A+B+C << endl;
    }
    }


    return 0;
}
