#include <iostream>
using namespace std;
int ac(int a)
{
    if(a < 0) return -a;
    return a;
}
int main()
{
    int r = 0, c = 0, days = 0;
    cin >> r >> c >> days;
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    int a = 0;
    while(cin >> a)
    {
        a--;
        if(x1 < 0) x1 = a;
        else if(y1 < 0) y1 = a;
        else if(x2 < 0) x2 = a;
        else y2 = a;
    }
    if(x2 < 0) x2 = 5000;
    if(y2 < 0) y2 = 5000;
    int healthy = r*c;
    for(int i = 0; i < r; i ++)
    {
        for(int j = 0; j < c; j ++)
        {
            healthy -= ((ac(i-x1)+ac(j-y1))<=days||(ac(i-x2)+ac(j-y2))<=days);
        }
    }
    cout << healthy << endl;
}
