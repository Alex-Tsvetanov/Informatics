#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool a[3002][3002];

int main () {

    ios_base::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x][y] = 1;
    }

    vector <int> currentQueue;
    int removed[n], queueSize, sum = 0, br = 0, calculated[n][3];

    for (int i = 0; i < n; i++) {
        removed[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum = 0, br = 0;
        for (int j = 0; j < n; j++) {
            removed[j] = -1;
        }
        removed[i] = 1;
        sum += i;
        br++;

        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                currentQueue.push_back(j);
                sum += j;
                br++;
            }
        }

        while (currentQueue.size() != 0) {
            for (int j = 0; j < n; j++) {
                if (a[currentQueue[0]][j] && removed[j] == -1) {
                    removed[j] = 1;
                    sum += j;
                    br++;
                    currentQueue.push_back(j);
                }
            }

            currentQueue.erase(currentQueue.begin() + 0);
        }

        calculated[i][0] = br;
        calculated[i][1] = sum;
        calculated[i][2] = i;
    }

    int minSum = 1000000000;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (calculated[i][0] == n + 2) {
                if (minSum > calculated[i][1]) {
                    minSum = calculated[i][1];
                }
            }
            if (calculated[i][0] < calculated[j][0]) {
                swap(calculated[i][0], calculated[j][0]);
                swap(calculated[i][1], calculated[j][1]);
                swap(calculated[i][2], calculated[j][2]);
            }
        }
    }

    vector <int> finalNumbers;

    for (int i = 0; i < n; i++) {
        if (calculated[i][0] == n + 2) {
            if (calculated[i][1] == minSum) {
                finalNumbers.push_back(calculated[i][2]);
            }
        }
    }

    cout << finalNumbers.size() << "\n";

    sort(finalNumbers.begin(), finalNumbers.begin() + finalNumbers.size());

    for (int i = 0; i < finalNumbers.size(); i++) {
        cout << finalNumbers[i] << " ";
    }

    cout << "\n";

    return 0;
}
