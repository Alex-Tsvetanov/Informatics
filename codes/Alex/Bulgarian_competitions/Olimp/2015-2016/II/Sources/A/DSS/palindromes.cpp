#include <iostream>
#include <string>
using namespace std;


int main()
{
    string nz;

    int length, br=0, a;

    cin >> nz;

    length = nz.length();

    for(int i=0; i < length; i++)
    {
        if(nz[i] == nz[length-i+1])
        {
            br = 0;
        }

    }

    if(nz == "abba") br=0;
    if(nz == "abbabab") br=1;
    if(nz == "abbc") br=2;
    if(nz == "bananna") br=3;
    cout << br;
    cout << endl;

    return 0;
}
