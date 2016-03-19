#include <iostream>
using namespace std;

int main() {

  char A[1000002];
  long long i, spesteniSimvoli;
  cin >> A;

  for (spesteniSimvoli=i=0; A[i]!='.';) {
    if (A[i]==A[i+1]) {
      for (; A[i]==A[i+1]; spesteniSimvoli++, i++);
      spesteniSimvoli--;
    }
    else i++;
  }

  cout << spesteniSimvoli << endl;

  return 0;
}
