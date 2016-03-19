#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
    for (int i = 2 ; i < 1000000000 ; i ++)
    {
        stringstream ss;
        ss << i;
        string b = "echo " + ss.str () + " > a";
        string a = "stepen.exe < a > b";
        system(b.c_str ());
        time_t timer, timer2;
        time(&timer);
        system(a.c_str ());
        time(&timer2);
        double seconds = difftime(timer,timer2);

        if (seconds > 0.500)
        {
            cout << i << '\n';
            cout << seconds << "\n";
            cout << "-----------------------------------" << endl;
        }

        //system("pause");
        //system("cls");
    }
}
