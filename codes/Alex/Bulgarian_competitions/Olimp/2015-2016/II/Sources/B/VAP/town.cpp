#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
    short n = 0, a = 0, b = 0;
    cin >> n >> a >> b;

    bool bCinCheck = true;

    for(;;) {
        int p, q;
        cin >> p >> q;

        if(cin.eof() || cin.bad())
            break;
        else if(cin.fail()) {
            cin.clear(); // unset failbit
            break; // skip bad input
        }
    }

    cout << "X" << endl;

    return 0;
}
