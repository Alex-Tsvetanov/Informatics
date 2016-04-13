#include <iostream>
#include <vector>
using namespace std;

unsigned del(unsigned ch);

int main()
{
    vector<unsigned> brdel;
    unsigned n, ch;
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> ch;
        brdel.push_back(del(ch));
    }
    for(int i=0; i<n-1; ++i)
        cout << brdel.at(i) << " ";
    cout << brdel.at(n-1) << endl;
    return 0;
}

unsigned del(unsigned ch)
{
    unsigned br=1;
    for(int del=1; del<ch; ++del)
    {
        if(!(ch%del)) ++br;
    }
    return br;
}
