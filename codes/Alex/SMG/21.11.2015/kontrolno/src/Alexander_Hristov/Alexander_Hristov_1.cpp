#include <iostream>
using namespace std;

int main()
{
    char chislo;
    int chas1[5],chas2[5];
    for(int i = 0; i < 4; i++)
    {
        cin >> chislo;
        if(chislo != ':')
            chas1[i] = chislo - '0';
        else i--;
    }

    for(int i = 0; i < 4; i++)
    {
        cin >> chislo;
        if(chislo != ':')
            chas2[i] = chislo - '0';
        else i--;
    }

    if((chas1[0]*10 + chas1[1]) > (chas2[0]*10 + chas2[1]))
    {
        chas2[0] = chas2[0]+2;
        chas2[1] = chas2[1]+4;
    }
    if((chas1[2]*10 + chas1[3]) > (chas2[2]*10+ chas2[3]))
    {
        chas2[2] = chas2[2]+6;
        chas2[1] = chas2[1]-1;
    }
    if(((chas2[0]*10 + chas2[1]) - (chas1[0]*10 + chas1[1])) < 10)
        cout << "0";
    cout << (chas2[0]*10 + chas2[1]) - (chas1[0]*10 + chas1[1]) << ":" << (chas2[2]*10 + chas2[3]) - (chas1[2]*10+ chas1[3]);
}
