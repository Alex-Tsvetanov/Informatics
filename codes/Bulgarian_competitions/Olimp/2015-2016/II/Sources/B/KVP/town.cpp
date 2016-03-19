#include <iostream>
#include <vector>

using namespace std;

int n, a, b, p, q, cur, help, last, br, mini = 999999999;
vector <vector <int> > m (2);
bool used [200001];

void srch (int x) {
    if (x == b) {
        if (mini > br) mini = br;
        return;
    }
    for (int i = 0; i < help; i ++) {
        if (m [0] [i] == x and !used [m [1] [i]]) {
            used [m [1] [i]] = true;
            srch (m [1] [i]);
            used [m [1] [i]] = false;
        }
    }
    for (int i = 0; i < help; i ++) {
        if (m [1] [i] == x and !used [m [0] [i]]) {
            used [m [0] [i]] = true;
            br ++;
            srch (m [0] [i]);
            used [m [0] [i]] = false;
            br --;
        }
    }
}

int main () {
    cin >> n >> a >> b;
    used [a] = true;
    while (cin) {
        cin >> p >> q;
        m [0].push_back (p);
        m [1].push_back (q);
    }
    help = m [0].size ();
    srch (a);
    if (mini != 999999999) cout << mini << endl;
    else cout << "X\n";
    return 0;
}
