#include <iostream>
using namespace std;

int main() {

  long long A, B, C, broiIzqdeni;
  cin >> A >> B >> C;

  for (broiIzqdeni=0;;) {
    if (A==0) break;
    A--;
    broiIzqdeni++;
    if (B==0) break;
    B--;
    broiIzqdeni++;
    if (C==0) break;
    C--;
    broiIzqdeni++;
    if (B==0) break;
    B--;
    broiIzqdeni++;
  }

  cout << broiIzqdeni << endl;

  return 0;
}
