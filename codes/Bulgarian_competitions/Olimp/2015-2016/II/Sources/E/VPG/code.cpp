#include <iostream>
#include <cstring>
using namespace std;
char a[1000002];
int main ()
{
    long long brnis, brcode=0, s, k, cifri;
    cin >> a;
    brnis=strlen(a);
    for (int i=0;a[i]!='\0';i=i+s) {
        s=1;
        k=i+1;
        while (a[k]!='\0' and a[i]==a[k]) {s++;k++;}
        if (s==2) brcode++;
        else {
            k=s-1;
            cifri=0;
            while (k>0) {
                cifri++;
                k=k/10;
            }
            brcode=brcode+cifri+1;
        }
    }
    if (brcode>=brnis) cout << brcode-brnis << endl;
    else cout << brnis-brcode << endl;
    return 0;
}

