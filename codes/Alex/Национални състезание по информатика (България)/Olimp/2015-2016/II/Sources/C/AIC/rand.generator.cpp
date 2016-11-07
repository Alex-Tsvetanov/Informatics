#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

ofstream cout ("out.txt");

int main ()
{
    srand(time(NULL));
    int n =   3000;
    int m = 400000;
    cout << n << " " << m << "\n";
    for (int i = 0 ; i < m ; i ++)
    {
        cout << rand () % n << " " << rand () % n << "\n";
    }
}
