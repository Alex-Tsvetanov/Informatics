#include <iostream>
using namespace std;

int main()
{
    long long x,y,d;
    cin >> x >> y;
    cin >> d;
    if(x%4==0){
            cout << x/4+d << " " << x/4+y/4+d << endl;
            cout << x/4+d << " " << x/4+y/4-d << endl;
    }
    if(x%4!=0){
            cout << (x-1)/4+d << " " << (y+100)/4+d << endl;
            cout << (x-1)/4+d << " " << (y+100)/4-d << endl;
    }

    return 0;
}
