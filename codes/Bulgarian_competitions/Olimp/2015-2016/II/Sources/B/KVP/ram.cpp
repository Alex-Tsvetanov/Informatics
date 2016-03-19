#include <iostream>
#include <vector>

using namespace std;

int k, br, help;
vector <vector <int> > a (2);

int main () {
    cin >> k;
    for (int i = 1; i <= (k + 1) / 3; i ++) {
        if ((k + i) / (2 * i + 1) > i and (k + i) % (2 * i + 1) == 0) {
            br ++;
            a [0].push_back (i);
            a [1].push_back ((k + i) / (2 * i + 1));
        } else if ((k - i - 1) % (2 * i - 1) == 0 and (k - i - 1) / (2 * i - 1) <= i) {
            br ++;
            a [0].push_back (i);
            a [1].push_back ((k - i - 1) / (2 * i - 1));
        }
    }
    help = a [0].size ();
    cout << help << endl;
    for (int i = 0; i < help; i ++) {
        cout << a [0] [i] << " " << a [1] [i] << endl;
    }
    return 0;
}
