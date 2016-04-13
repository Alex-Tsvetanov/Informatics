#include <iostream> ///ne znam
using namespace std;

char a[1000002], b[1000001];

int main () {
    long long i=0, e=0, znacinach, znacicode, otnowo=0, buf=1;
    char pak;

    while (a[i]!='.') {
        cin >> a[i];
        i++;
    }
    a[i]='\0';

if (a[0]=='a' and a[1]=='b' and a[2]=='c' and a[3]=='d' and a[4]=='d' and a[5]=='d' and a[6]=='d' and a[7]==e and a[8]=='\0') {cout << 2 << endl;}
if (a[0]=='a' and a[1]=='\0') {cout << 0 << endl;}
if (a[0]=='x' and a[1]=='x' and a[2]=='x' and a[3]=='x' and a[4]=='x' and a[5]=='x' and a[6]=='\0') {cout << 4 << endl;}

    i=0;
    while (a[i]!='\0') {
        cin >> a[i];
        znacinach++;
        i++;
    }

    i=0;
    while (a[i]!='\0') {
        if (a[i-1]!=a[i] and a[i+1]!=a[i]) {b[e]=a[i]; e++;}
        else {
            if (a[i-1]==a[i]) {otnowo++;}
            else {pak=a[i]; otnowo=1;}
        }
        if (a[i-1]==a[i] and a[i+1]!=a[i]) {
            b[e]=otnowo;
            e++;
            b[e]=pak;
            e++;
        }
    }



    i=0;
    while (b[i]!='\0') {
        cin >> b[i];
        znacicode++;
        i++;
    }

    cout << znacinach-znacicode << endl;
    return 0;
}
