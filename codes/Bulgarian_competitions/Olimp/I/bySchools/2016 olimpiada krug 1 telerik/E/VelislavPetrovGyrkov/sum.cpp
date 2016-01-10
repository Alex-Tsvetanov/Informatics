#include <iostream>
using namespace std;
int main ()
{
    long long A, B, ed1, des1, st1, ed2, des2, st2;
    char c;
    cin >> A >> c >> B;
    ed1=A%10;
    des1=A/10%10;
    st1=A/100;
    ed2=B%10;
    des2=B/10%10;
    st2=B/100;
    cout << st1+st2;
    if (des1+des2>9) cout << des1+des2-10;
    else cout << des1+des2;
    if (ed1+ed2>9) cout << ed1+ed2-10 << endl;
    else cout << ed1+ed2 << endl;
    cout << A+B << endl;
    return 0;
}
