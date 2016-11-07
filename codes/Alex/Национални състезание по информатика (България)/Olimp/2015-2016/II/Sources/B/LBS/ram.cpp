#include<iostream>
using namespace std;

int main()
{
    int K=12345,P=0,mxlen=0;// cin >> K;
    while (3*mxlen+2 <= K){mxlen++;}
    int arr[2][mxlen];
    for (int j = 1; j <= mxlen; j++)
        for (int i = 1; i <= mxlen; i++){
            if(i>j && 2*i*j+i-j==K){
                arr[0][P]=i; arr[1][P]=j;
                P++;
            }
            else if(i<=j && 2*i*j-i+j+1==K){
                arr[0][P]=i; arr[1][P]=j;
                P++;
            }
        }

    cout << P << endl;
    for (int x=0;x<P;x++) {cout << arr[1][x] << ' ' << arr[0][x] << endl;}


    return 0;
}
