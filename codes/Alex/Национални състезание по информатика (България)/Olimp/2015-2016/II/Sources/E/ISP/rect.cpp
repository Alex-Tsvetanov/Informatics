#include <iostream>
using namespace std;

int main() {

  long long A, B, broiPravougulnici, n, klechkiPoDuljIShir, ostanaliKlechki;
  cin >> n;

  for (A=B=1, broiPravougulnici=0; A<=(n-4)/3+1; A++, B=1) {
    for (; B<=A; B++) {
      klechkiPoDuljIShir=3*(A+B)-2;
      ostanaliKlechki=n-klechkiPoDuljIShir;
      if (ostanaliKlechki%2==0 and ostanaliKlechki/2==(A-1)*(B-1)) broiPravougulnici++;
    }
  }


  cout << broiPravougulnici << endl;

  return 0;
}
