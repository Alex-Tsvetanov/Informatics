#include <iostream>
using namespace std;

int main () {

    int n, m, chislo=2, i, j, pr=0, pr1=0, pr2=0;
    cin >> m >> n;
    int A[m+2][n+2];
    for (i=1; i<=m; i++) {
        for (j=1; j<=n; j++) {
            cin >> A[i][j];
        }
    }
    for (i; i>=0; i--) {A[i][0] = A[i][n+1] = 0;}
    for (j = n; j>0; j--) {A[0][j] = A[m+1][j] = 0;}
    for (chislo; chislo<40000; chislo++, pr=0, pr1=0, pr2=0) {
            for (long long k=0; k<m+n-2; k++) {
                for (i=1; i<=m; i++) {
                    for (j=1; j<=n; j++) {
                        if(A[i][j]==0) {
                            if (pr1==0) {A[i][j]=chislo; pr1++;}
                            else {
                            if (A[i-1][j]==chislo) {A[i][j] = chislo;}
                            if (A[i+1][j]==chislo) {A[i][j] = chislo;}
                            if (A[i][j-1]==chislo) {A[i][j] = chislo;}
                            if (A[i][j+1]==chislo) {A[i][j] = chislo;}
                            }
                        }
                    }
                }
            }
                for (i=1; i<=m; i++) {
                    for (j=1; j<=n; j++) {
                        if(A[i][j]==0) {
                            pr = 1;
                            break;
                        }
                    }
                }
                if (pr==0) {pr2 = 1; break;}
            if (pr2==1) {break;}
    }

    cout << chislo-1 << endl;
    return 0;
}
