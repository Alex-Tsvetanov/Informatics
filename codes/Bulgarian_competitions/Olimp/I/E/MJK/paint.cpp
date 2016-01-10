#include<iostream>
using namespace std;
int main()
{
    int s1,lv1,st1,s2,lv2,st2,s3,lv3,st3,a,b,mins,o1,o2,o3,minlv,minst;

    cin>>s1>>lv1>>st1>>s2>>lv2>>st2>>s3>>lv3>>st3>>a>>b;

    o1=a*b*4/s1;
    o2=a*b*4/s2;
    o3=a*b*4/s3;

    mins=o1;

    if (o2<mins) mins=o2;
    if (o3<mins) mins=o3;

    minlv=o1*lv1;
    minst=o1*st1;

    if (o2*lv2<minlv) minlv=o2*lv2;
    if (o3*lv3<minlv) minlv=o3*lv3;
    if (o2*st2<minst) minst=st2*o2;
    if (o3*st3<minst) minst=st3*o3;

    cout<<minlv<<" "<<minst<<endl;

    return 0;
}
