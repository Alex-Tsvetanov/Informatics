#include <iostream>
using namespace std;
int main() {
    long long s1 , s2 , s3 , lv1 , lv2 , lv3 , st1 , st2 , st3 , a , b , min1 , s1c , s2c , s3c ;
    cin>>s1>>lv1>>st1>>s2>>lv2>>st2>>s3>>lv3>>st3>>a>>b;
    a=a*b;

    s1c=s1;
    s2c=s2;
    s3c=s3;

    lv1=lv1*100;
    lv2=lv2*100;
    lv3=lv3*100;

    lv1=lv1+st1;
    lv2=lv2+st2;
    lv3=lv3+st3;

    s1=s1*lv1;
    s2=s2*lv2;
    s3=s3*lv3;


    if (s1<s2 and s1<s3) {
        min1=s1;
        lv1=min1/s1c;
    } else if (s2<s3) {
        min1=s2;
        lv1=min1/s2c;
    } else {
        min1=s3;
        lv1=min1/s3c;
    }

    a=a/min1;
    lv2=a*lv2;
    lv2=lv1/100;
    cout<<lv2<<' ';
    lv2=lv2*100;
    lv2=lv1-lv2;

    cout<<lv2;

    return 0;
}


