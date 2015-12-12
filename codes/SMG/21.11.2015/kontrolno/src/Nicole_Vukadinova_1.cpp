/*час, час, колко време е минало*/
#include <iostream>
using namespace std;

int main ()
{
    int hours[2], mins[2], h, m;
    char clock[2][8];
    cin >> clock[0] >> clock[1];
    hours[0] = 10*(clock[0][0] - '0') + (clock[0][1] - '0');
    mins[0] = 10*(clock[0][3] - '0') + (clock[0][4] - '0');
    hours[1] = 10*(clock[1][0] - '0') + (clock[1][1] - '0');
    mins[1] = 10*(clock[1][3] - '0') + (clock[1][4] - '0');

    m = mins[1] - mins[0];
    if(mins[0] > mins[1])
    {
        m += 60;
        ++hours[0];
    }
    h = hours[1] - hours[0];
    if(h < 0)
        h += 24;
    if(h < 10)
        cout << 0;
    cout << h << ":";
    if(m < 10)
        cout << 0;
    cout << m << endl;
    return 0;
}
