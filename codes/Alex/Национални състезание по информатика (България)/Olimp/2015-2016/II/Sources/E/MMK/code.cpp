#include<iostream>
#include<string>
using namespace std;

long long d, d2, i, br=1;
string s, s2;

int main () {
    cin>>s;
    d=s.size()-1;
    for (i=1;i<=d;i++) {
        if (s[i-1]==s[i]) {
            br++;
        }
        else {
            if (br>1) {
                if (br<10)d2+=2;
                else if (br<100)d2+=3;
                else if (br<1000)d2+=4;
                else if (br<10000)d2+=5;
                else if (br<100000)d2+=6;
                else if (br<1000000)d2+=7;
                else if (br==1000000)d2+=8;
            }
            else {
                d2+=1;
            }
            br=1;
        }
    }
    cout<<d-d2<<endl;
    return 0;
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbb.
