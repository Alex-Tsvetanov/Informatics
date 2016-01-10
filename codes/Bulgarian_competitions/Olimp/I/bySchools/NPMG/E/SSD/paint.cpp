#include <iostream>
using namespace std;

int main()
{
    long long s,lv,st,s1,lv1,st1,s2,lv2,st2,a,b;
    cin >> s >> lv >> st >> s1 >> lv1 >> st1 >> s2 >> lv2 >> st2 >> a >> b;
     if(st*(a*b*4-s)&&lv*(a*b*4-s)<lv1&&st1||st*(a*b*4-s)&&lv*(a*b*4-s)<lv2&&st2){
            cout << lv*(a*b*4-s) << " " << st*(a*b*4-s) << endl;
    }if(st1*(a*b*4-s1)&&lv1*(a*b*4-s1)<lv&&st||st1*(a*b*4-s1)&&lv1*(a*b*4-s1)<lv2&&st2){
            cout << lv1*(a*b*4-s1) << " " << st1*(a*b*4-s1) << endl;
    }if(st2*(a*b*4-s2)&&lv2*(a*b*4-s2)<lv&&st||st2*(a*b*4-s2)&&lv2*(a*b*4-s2)<lv1&&st1)  {
            cout << lv2*(a*b*4-s2) << " " << st2*(a*b*4-s2) << endl;
    }

    return 0;
}
