#include<iostream>
#include<set>
using namespace std;
typedef long long ulong;

class comp {
public:
    bool operator()(pair<ulong, ulong> first, pair<ulong, ulong> second) {
        return first.first < second.first;
    }
};

int main() {
    for(int n = 0; n < 5; n++) {
        set<pair<ulong, ulong>, comp> b; // moze i sas bool array ili bitset
        int s;
        cin >> s;
        for(int m = 0; m < s; m++) {
            int a;
            cin >> a;
            b.insert(pair<ulong, ulong>(a, m));
        }
        cin >> s;
        int maxIndex = -1;
        int ans = 1;
        for(int m = 0; m < s; m++) {
            int a;
            cin >> a;
            set<pair<ulong, ulong>, comp>::iterator i;
            if((i = b.find(pair<ulong, ulong>(a, 0))) != b.end()) {
                if(maxIndex < (i->second)) {
                    maxIndex = i->second;
                } else {
                    //cout << "debug " << maxIndex << ' ' << i->second << ' ' << (maxIndex < (i->second)) << " debug\n";
                    ans = 0;
                    //break; // otiva izvan samia for?
                }
            }
        }
        cout << ans;
    }
    cout << endl;
    return 0;
}
