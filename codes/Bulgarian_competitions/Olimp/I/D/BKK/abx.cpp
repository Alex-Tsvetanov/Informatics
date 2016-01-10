#include <iostream>
#include <string>
using namespace std;

int main () {
    string s;
    long long len, i=2, A=0, j=1, B=0, buf;
    cin >> s;
    len = s.size();
    long long n[len];
    if (s[0] == 'X') {
        n[2] = s[2];
        while (n[i]>=48 and n[i]<=57) {
        i++;
        n[i] = s[i];
        }
        buf = i;
        while (i>2) {
            A = A + (n[i-1] - 48)*j;
            i--;
            j = j*10;
        }
        i = len-1;
        j = 1;
        while (i>buf) {
            n[i] = s[i];
            B = B + (n[i] - 48)*j;
            i--;
            j = j*10;
        }
    } else {
        i = 0;
        n[0] = s[0];
        while (n[i]>=48 and n[i]<=57) {
        i++;
        n[i] = s[i];
        }
        buf = i;
        while (i>=1) {
            A = A + (n[i-1] - 48)*j;
            i--;
            j = j*10;
        }
        i = len-1;
        j = 1;
        while (i>buf+2) {
            n[i] = s[i];
            B = B + (n[i] - 48)*j;
            i--;
            j = j*10;
        }

    }

    cout << B-A << endl;
    return 0;
}
