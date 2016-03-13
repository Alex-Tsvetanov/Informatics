#include <iostream>
using namespace std;
int main ()
{
    long long x, y, d, poluP, strana1, strana2;
    cin >> x >> y;
    cin >> d;
    poluP=(x*100+y)/2;
    strana2=poluP/2-(d/2);
    strana1=strana2+d;
    cout << strana1/100 << " " << strana1%100 << endl;
    cout << strana2/100 << " " << strana2%100 << endl;
    return 0;
}
