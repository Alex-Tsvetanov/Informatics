#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int kmp[12000];

string str;

int calcCuts(int s, int e) {
    kmp[s] = kmp[s - 1] = s - 1;
    int p = s + 1;
    int x = s - 1;
    int pal = 0;
    while(p != e + 1) {
        if(p - s > 1) {
            if((s + p - 2) % 2 == 0) {
                int eql = (str[kmp[p - 1] + 1] == str[kmp[p - 1] + 2]);
                if(kmp[p - 1] * 2 + eql * 2 == (s + p - 2)) {
                    // Palindrome
                    pal = p - 1;
                }
            } else {
                if(kmp[p - 1] * 2 + 1 == (s + p - 2)) {
                    pal = p - 1;
                }
            }
        }
        if(str[s] != str[p]) {
            kmp[p] = s - 1;
            p++;
            x = p - 2;
            continue;
        }
        if(str[x + 1] == str[p]) {
            kmp[p] = kmp[p - 1] + 1;
            p++;
            x++;
        } else {
            if((s - x) != 1) {
                x = kmp[kmp[p - 1]];
            } else {
                kmp[p] = s - 1;
                p++;
            }
        }
    }

    if((s + p - 2) % 2 == 0) {
        int eql = (str[kmp[p - 1] + 1] == str[kmp[p - 1] + 2]);
        if(kmp[p - 1] * 2 + eql * 2 == (s + p - 2)) {
            // Palindrome
            return 0;
        }
    } else {
        if(kmp[p - 1] * 2 + 1 == (s + p - 2)) {
            return 0;
        }
    }

   if(pal == 0) {
        str[s] = '#';
        if(s + 1 == e) {
            return 1;
        }
        return calcCuts(s + 1, e) + 1;
    }

    if(e - pal == 1) {
        return calcCuts(s, e - 1) + 1;
    }

    return calcCuts(pal + 1, e) + 1;
}

int main()
{

    cin >> str;
    str = '#' + str;
    int ans = calcCuts(1, str.size() - 1);
    printf("%d\n", ans);

}
