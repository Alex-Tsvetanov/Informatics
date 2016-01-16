#include <iostream>
using namespace std;
int main () {
    long long najmnogobroq = 0, brrazli4ni = 0, brednakvi = 0;
    char kodovaduma, vyvedeno, novovyvedeno;
    cin >> vyvedeno;
    while (vyvedeno !='#') {
        cin >> novovyvedeno;
        if (novovyvedeno != vyvedeno) {
            brrazli4ni++;
        }else {
            brednakvi++;
        }
        if (najmnogobroq < brednakvi) {
            najmnogobroq = brednakvi;
        }
        cin >> vyvedeno;
    }
    cout << kodovaduma;
}
