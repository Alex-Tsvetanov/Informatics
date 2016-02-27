#include <iostream>
using namespace std;

int main() {

  long long N, T[21], i=1;
  T[0]=0;
  while (i<4) {
    cin >> T[i];
    i++;
  }
  cin >> N;

  if (N==1) {cout << T[1];}
  else {
    if (N==2) {cout << T[2];}
    else {
      if (N==3) {cout << T[3];}
      else {
        i=4;
        while (i<=N) {
          T[i]=T[i-1]+T[i-2]+T[i-3];
          i++;
        }
        cout << T[N];
      }
    }
  }

  cout << endl;

  return 0;
}
