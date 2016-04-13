#include  <iostream>
#include  <cstdlib>
#include  <math.h>
#include  <list>
using  namespace  std;


bool palindrom(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

int split(string s) {

    list<char> symbols;
    int br = 0;
    int br2 = 0;
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (symbols.empty()) {
            symbols.push_back(s[i]);
            br++;
            res += s[i];
        } else {
            if (symbols.back() == s[i]) {
                symbols.pop_back();
                br++;
                res += s[i];
                if (symbols.empty()) {
                    //cout << "rs: " << res << endl;
                    return br;
                }
            } else {
                symbols.push_back(s[i]);
                br++;
                res += s[i];
                if (palindrom(res)) {
                    br2 = br;
                }
            }
        }

    }
    if (!symbols.empty()) return max(1, br2);

    return 1;
}

int split2(string s) {

    list<char> symbols;
    int br = 0;
    for (int i = 0; i < s.size(); i++) {
        if (symbols.empty()) {
            symbols.push_back(s[i]);
        } else {
            if (symbols.back() == s[i]) {
                symbols.pop_back();
                if (symbols.empty()) {
                    br++;
                }
            } else {
                symbols.push_back(s[i]);
            }
        }
    }

    return br;
}

int main() {

    string s;
    cin >> s;

    int split2BR = split2(s);

    if (palindrom(s)) {
        cout << "0" << endl;
        return 0;
    }

    int br = 0;
    while (s.size() > 1) {
        int c = split(s);
        //cout << c << endl;
        s.erase(0, c);
        if (s.size() != 0) br ++;
    }

    cout << br << endl;
    //cout << split2BR;



return 0;
}
