#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool possible1 = true,possible2 = true;
    int n,a,b,p,q;
    cin >> n >> a >> b;

    vector<int> V_P;
    vector<int> V_Q;

    while(cin >> p >> q)
    {
        if(p == a || q == a)
            possible1 = false;
        if(p == b || q == b)
            possible2 = false;
        V_P.push_back(p);
        V_Q.push_back(q);
    }
    if(possible1 || possible2)
        cout << "X" << endl;
    else{
        cout << 0;
    }
}
