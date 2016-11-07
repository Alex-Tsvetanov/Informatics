#include<iostream>
#include<cstring>
using namespace std;

int main ()
{

    char a1[64], a2[64], b[64];
    int prenos = 0, k = 0;
    cin >> a1 >> a2;
    int size1, size2, i, j;
    size1 = strlen(a1);
    size2 = strlen(a2);
    for(i = size1 - 1, j = size2 - 1; i >= 0 && j >= 0; --i, --j)
    {
        if(a1[i] == '?' || a2[j] == '?' || prenos == -1)
        {
            b[k] = '?';
            ++k;
            if(!((prenos == 1 && (a1[i] == '1' || a2[j] == '1')) || (prenos == 0 && (a1[i] == '0' || a2[j] == '0'))))
                prenos = -1;
        } else
        {
            if(a1[i] - '0' + a2[j] - '0' + prenos == 0)
            {
                b[k] = '0';
                prenos = 0;
            }
            else if(a1[i] - '0' + a2[j] - '0' + prenos == 1)
            {
                b[k] = '1';
                prenos = 0;
            }
            else if(a1[i] - '0' + a2[j] - '0' + prenos == 2)
            {
                b[k] = '0';
                prenos = 1;
            } else if(a1[i] - '0' + a2[j] - '0' + prenos == 3)
            {
                b[k] = '1';
                prenos = 1;
            }
            ++k;
        }
    }
    if(size1 > size2)
    {
        for(; i >= 0; --i)
        {
            if(a1[i] == '?' || prenos == -1)
            {
                b[k] = '?';
                ++k;
                if(!((prenos == 1 && (a1[i] == '1')) || (prenos == 0)))
                    prenos = -1;
            } else
            {
                if(a1[i] - '0' + prenos == 0)
                {
                    b[k] = '0';
                    prenos = 0;
                }
                else if(a1[i] - '0' + prenos == 1)
                {
                    b[k] = '1';
                    prenos = 0;
                }
                else if(a1[i] - '0' + prenos == 2)
                {
                    b[k] = '0';
                    prenos = 1;
                }
                ++k;
            }
        }
    }
    if(size1 < size2)
    {
        for(; j >= 0; --j)
        {
            if(a2[j] == '?' || prenos == -1)
            {
                b[k] = '?';
                ++k;
                if(!((prenos == 1 && (a2[j] == '1')) || (prenos == 0)))
                    prenos = -1;
            } else
            {
                if(a2[j] - '0' + prenos == 0)
                {
                    b[k] = '0';
                    prenos = 0;
                }
                else if(a2[j] - '0' + prenos == 1)
                {
                    b[k] = '1';
                    prenos = 0;
                }
                else if(a2[j] - '0' + prenos == 2)
                {
                    b[k] = '0';
                    prenos = 1;
                }
                ++k;
            }
        }
    }
    if(prenos == -1)
    {
        b[k] = '?';
        ++k;
    } else if(prenos == 1)
    {
        b[k] = '1';
        ++k;
    }
    for(i = k - 1; i >= 0; --i)
        cout << b[i];
    cout << endl;
    return 0;
}
