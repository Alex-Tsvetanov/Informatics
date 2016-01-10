#include <iostream>
using namespace std;

int main ()
{
    int s1,lv1,st1,s2,lv2,st2,s3,lv3,st3,a,b;
    cin>>s1>>lv1>>st1>>s2>>lv2>>st2>>s3>>lv3>>st3>>a>>b;

    if (((a*b)/s1)*(lv1+st1)<((a*b)/s2)*(lv2+st2)&&((a*b)/s1)*(lv1+st1)<((a*b)/s3)*(lv3+st3)){
        cout<<((a*b)/s1)*(lv1+st1)<<endl;
    }else{ if(((a*b)/s2)*(lv2+st2)<((a*b)/s1)*(lv1+st1)&&((a*b)/s2)*(lv2+st2)<((a*b)/s3)*(lv3+st3)){
        cout<<((a*b)/s2)*(lv2+st2)<<endl;
    }else{ if(((a*b)/s3)*(lv3+st3)<((a*b)/s1)*(lv1+st1)&&((a*b)/s3)*(lv3+st3)<((a*b)/s2)*(lv2+st2)){
        cout<<((a*b)/s3)*(lv3+st3)<<endl;

         cout<<s1<<" "<<lv1<<" "<<st1<<" "<<s2<<" "<<lv2<<" "<<st2<<" "<<s3<<" "<<lv3<<" "<<st3<<endl;

    return 0;
    }
    }
    }

}
