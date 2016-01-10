//Task; paint
//Author: Dimitar Stefanov
#include <iostream>
using namespace std;
int main ()
{
    int s1, lv1, st1, s2, lv2, st2, s3, lv3, st3, a, b;
    cin >> s1 >> lv1 >> st1 >> s2 >> lv2 >> st2  >> s3 >> lv3 >> st3 >> a >> b;
    a=4*a;
    if(a*b%s1 > 0)
    {
        s1 = (a*b)/s1 + 1;
    }
    else
    {
        s1 = (a*b)/s1;
    }
    if(a*b%s2 > 0)
    {
        s2 = (a*b)/s2 + 1;
    }
    else
    {
        s2 = (a*b)/s2;
    }
    if(a*b%s3 > 0)
    {
        s3 = (a*b)/s3 + 1;
    }
    else
    {
        s3 = (a*b)/s3;
    }

    if(s1*(100*lv1+st1) <= s2*(100*lv2+st2) && s1*(100*lv1+st1) <= s3*(100*lv3+st3))
    {
        cout << (s1*(100*lv1+st1))/100 << " " << (s1*(100*lv1+st1))%100;
    }
    else if(s2*(100*lv2+st2) <= s3*(100*lv3+st3))
    {
        cout << (s2*(100*lv2+st2))/100 << " " << (s2*(100*lv2+st2))%100;
    }
    else
    {
        cout << (s3*(100*lv3+st3))/100 << " " << (s3*(100*lv3+st3))%100;
    }
    cout<<endl;
    return 0;
}
