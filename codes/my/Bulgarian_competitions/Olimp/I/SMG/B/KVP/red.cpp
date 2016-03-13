#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int n, help, maxi, mini = 1000001, maxmax, izha, izhb;
vector <int> maximi, minimi;

int main () {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> help;
        if (maxi < help) {
            maxi = help;
            maxmax = 0;
            maximi.resize (0);
            maximi.push_back (i);
            for (int j = 0; j < minimi.size(); j ++) {
                if (maxmax < abs (minimi [j] - maximi [0])) {
                    maxmax = abs (minimi [j] - maximi [0]);
                    izha = min (minimi [j], maximi [0]);
                    izhb = max (minimi [j], maximi [0]);
                } else {
                    if (maxmax == abs (minimi [j] - maximi [0])) {
                        if (izha + izhb > minimi [j] + maximi [0]) {
                            izha = min (minimi [j], maximi [0]);
                            izhb = max (minimi [j], maximi [0]);
                        }
                    }
                }
            }
        } else {
            if (maxi == help) {
                maximi.push_back (i);
                int help1 = maximi.size () - 1;
                for (int j = 0; j < minimi.size(); j ++) {
                    if (maxmax < abs (minimi [j] - maximi [help1])) {
                        maxmax = abs (minimi [j] - maximi [help1]);
                        izha = min (minimi [j], maximi [help1]);
                        izhb = max (minimi [j], maximi [help1]);
                    } else {
                        if (maxmax == abs (minimi [j] - maximi [help1])) {
                            if (izha + izhb > minimi [j] + maximi [help1]) {
                                izha = min (minimi [j], maximi [help1]);
                                izhb = max (minimi [j], maximi [help1]);
                            }
                        }
                    }
                }
            }
        }
        if (mini > help) {
            mini = help;
            maxmax = 0;
            minimi.resize (0);
            minimi.push_back (i);
            for (int j = 0; j < maximi.size(); j ++) {
                if (maxmax < abs (maximi [j] - minimi [0])) {
                    maxmax = abs (maximi [j] - minimi [0]);
                    izha = min (maximi [j], minimi [0]);
                    izhb = max (maximi [j], minimi [0]);
                } else {
                    if (maxmax == abs (maximi [j] - minimi [0])) {
                        if (izha + izhb > maximi [j] + minimi [0]) {
                            izha = min (maximi [j], minimi [0]);
                            izhb = max (maximi [j], minimi [0]);
                        }
                    }
                }
            }
        } else {
            if (mini == help) {
                minimi.push_back (i);
                int help1 = minimi.size () - 1;
                for (int j = 0; j < maximi.size(); j ++) {
                    if (maxmax < abs (maximi [j] - minimi [help1])) {
                        maxmax = abs (maximi [j] - minimi [help1]);
                        izha = min (maximi [j], minimi [help1]);
                        izhb = max (maximi [j], minimi [help1]);
                    } else {
                        if (maxmax == abs (maximi [j] - minimi [help1])) {
                            if (izha + izhb > maximi [j] + minimi [help1]) {
                                izha = min (maximi [j], minimi [help1]);
                                izhb = max (maximi [j], minimi [help1]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << izha << " " << izhb << endl;
    return 0;
}
