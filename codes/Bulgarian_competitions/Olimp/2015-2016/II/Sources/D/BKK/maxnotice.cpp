#include <iostream>
using namespace std;

int main () {

    int l, h, n, i, j, k, rec=0, pr=0, pr1=0, pr2=0, a, b, s, promenliva, oshteednapromenliva;
    cin >> l >> h >> n;
    ///l, h ili h, l
    int A[l+2][h+2], raz[n][4];
    for (i=0; i<l+2; i++) {
        for (j=0; j<h+2; j++) {
            A[i][j] = 0;
        }
    }
    for (i=0; i<n; i++) {cin >> raz[i][0] >> raz[i][1] >> raz[i][2] >> raz[i][3];}
    for (j=0; j<n+2; j++) {A[0][j] = A[h+1][j] = 1;}
    for (j=1; j<h+1; j++) {A[j][1] = A[j][l+1] = 1;}
    ///jyjfcfj
    for (i=0; i<n; i++) {
        for (j = raz[i][0]-1; j<raz[i][0]-1+raz[i][2]; j++) {
            for (k = raz[i][1]-1; k<raz[i][1]-1+raz[i][3]; k++) {
                A[k][j] = 1;
            }
        }
    }
    ///hgkygkj
    for(i=1; i<=n; i++) {
        for (j=1; j<=n; j++, pr=pr1=a=b=0) {
            if (A[i][j]==0) {
                    for(long long b1=b; b1<200; b1++) {
                        if (A[i+b1][j+a]==1) {pr1++; break;}
                    }
                    for(long long a1=a; a1<200; a1++) {
                        if (A[i+b][j+a1]==1) {pr1+=2; break;}
                    }
                    if (pr1==0) {pr=0; a++; b++;}
                    else {
                        if (pr==1) {
                            while (pr2==0) {
                                for (promenliva=i+b; promenliva<200; promenliva++) {
                                    for (oshteednapromenliva=j; oshteednapromenliva<j+a; oshteednapromenliva++) {
                                        if (A[promenliva][oshteednapromenliva]==1) {pr2=1; break;}
                                    }
                                }
                            }
                            s=a*b;
                            if(s>rec) {rec = s;}
                            break;
                        } else {
                            if (pr==2) {
                                while (pr2==0) {
                                    for (promenliva=j+a; promenliva<200; promenliva++) {
                                        for (oshteednapromenliva=i; oshteednapromenliva<i+b; oshteednapromenliva++) {
                                            if (A[promenliva][oshteednapromenliva]==1) {pr2=1; break;}
                                        }
                                    }
                                }
                                s=a*b;
                                if(s>rec) {rec = s;}
                                break;
                            } else {
                                s=a*b;
                                if(s>rec) {rec = s;}
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << rec << endl;
    return 0;
}
