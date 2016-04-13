#include <string>
#include <cctype>
#include <iostream>
using namespace std;
int main()
{
    int a, b=0, i, brp=0;
    string t;
    getline(cin, t, '.');
    a=t.length();
    for (i=0; i<t.length(); i++)
    {
        t[i]=tolower(t[i]);
        t[i+1]=tolower(t[i+1]);
        if (t[i+1]==t[i]) brp++;
        else
        {
            if (brp!=0)
            {
                if ((brp+1)/1000000!=0) b+=7;
                else if ((brp+1)/100000!=0) b+=6;
                else if ((brp+1)/10000!=0) b+=5;
                else if ((brp+1)/1000!=0) b+=4;
                else if ((brp+1)/100!=0) b+=3;
                else if ((brp+1)/10!=0) b+=2;
                else b++;
                b++;
                brp=0;
            }
            else if (brp==0)
            {
                b++;
            }
        }
    }
    cout << a-b << endl;
}
