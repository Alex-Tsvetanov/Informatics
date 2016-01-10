#include <iostream>
using namespace std;
int main ()
{
    long long B, X, A1;
    char A;
    char znak1 = '+';
    char znak2 = '=';
    cin >> A >> znak1 >> A1 >> znak2 >> B;
    X = B - A1;
    if (A != 'X')
    {
        cout << -X << endl;
    }
    if (A == 'X')
    {
        cout << X << endl;
    }
    return 0;
}
