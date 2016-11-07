#include <iostream>
#include <vector>
using namespace std;
struct Res
{
    int n,m;
    Res(int x, int y): n(x), m(y) {}
};
vector<Res> a;
bool check(int m, int n, int k)
{
    int c;
    if(m<n) c=2*m;
    else c=2*n-1;
    int all=m*(n+1)+n*(m+1);
    return all-c==k;
}
int main ()
{
    int k;
    cin >> k;
    for(int i=1; i<=5000; i++)
        for(int j=1; j<=5000; j++)
            if(check(i,j,k)) a.push_back(Res(i,j));
    cout << a.size() << endl;
    for(vector<Res>::iterator it=a.begin(); it!=a.end(); ++it) cout << it->n << ' ' << it->m << endl;
    return 0;
}
