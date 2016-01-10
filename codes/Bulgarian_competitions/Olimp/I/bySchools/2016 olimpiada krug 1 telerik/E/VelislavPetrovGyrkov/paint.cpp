#include <iostream>
using namespace std;
int main ()
{
    long long s[3], lv[3], st[3], a, b, minnum, boi, sum;
    for (int i=0;i<3;i++) cin >> s[i] >> lv[i] >> st[i];
    cin >> a >> b;
    boi=(a*b*4)/s[0];
    if ((a*b*4)%s[0]!=0) boi++;
    minnum=boi*(lv[0]*100+st[0]);
    for (int i=1;i<3;i++) {
        boi=(a*b*4)/s[i];
        if ((a*b*4)%s[i]!=0) boi++;
        sum=boi*(lv[i]*100+st[i]);
        if (sum<minnum) minnum=sum;
    }
    cout << minnum/100 << " " << minnum%100 << endl;
    return 0;
}
