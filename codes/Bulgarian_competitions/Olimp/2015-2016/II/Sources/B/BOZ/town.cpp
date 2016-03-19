#include<iostream>
#include<stack>
using namespace std;

struct cn {
    int id, val;
};

struct cr {
    stack <cn> c;
    bool check = false;
};

int main ()
{
    int n, s, f;
    cin >> n >> s >> f;
    cr crs [n];
    s -= 1;
    f -= 1;

    int id;
    cn c1, c2;
    while(cin >> id >> c1.id){

        id -= 1;
        c1.id -=1;
        c1.val = id - c1.id > 0 ? 1 : 0;
        crs[id].c.push(c1);
        c2.id = id;
        c2.val = c1.val;
        crs[c1.id].c.push(c2);
    }

    cout << "X" << endl;



    return 0;
}
