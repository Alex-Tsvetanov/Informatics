#include <vector>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXS = 6 * 50 + 10;

const int MAXC = 26 + 10;

int out[MAXS];

int f[MAXS];
int g[MAXS][MAXC];
int buildMatchingMachine(const vector<string> &words, char lowestChar = 'a', char highestChar = 'z') {
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    
    int states = 1;
        
    for (int i = 0; i < (int)words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for (int j = 0; j < (int)keyword.size(); ++j) {
            int c = keyword[j] - lowestChar;
            if (g[currentState][c] == -1) {
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState] |= (1 << i);
    }
    
    for (int c = 0; c < MAXC; ++c) {
        if (g[0][c] == -1) {
            g[0][c] = 0;
        }
    }

    queue<int> q;
    for (int c = 0; c <= highestChar - lowestChar; ++c) {
        if (g[0][c] != -1 and g[0][c] != 0) {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= highestChar - lowestChar; ++c) {
            if (g[state][c] != -1) {
                int failure = f[state];
                while (g[failure][c] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure];
                q.push(g[state][c]);
            }
        }
    }

    return states;
}

int findNextState(int currentState, char nextInput, char lowestChar = 'a') {
    int answer = currentState;
    int c = nextInput - lowestChar;
    while (g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}

int main(){
    int n;
    cin >> n;
    vector<string> keywords;
    for (int i = 0 ; i < n ; i ++)
    {
       string a;
       cin >> a;
       keywords.push_back (a);
    }
    string text;
    cin >> text;
    string h = text;
    
    buildMatchingMachine(keywords, min (min ('a', 'A'),'0'), max(max('z','Z'), '9'));
    int currentState = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
       currentState = findNextState(currentState, text[i], min (min ('a', 'A'),'0'));
       if (out[currentState] == 0) continue;
       for (int j = 0; j < (int)keywords.size(); ++j) {
           if (out[currentState] & (1 << j)) {
               if ( (i-keywords [j].size())%2 ==0 and i % 2 == 0)
                  for (int k = i - keywords [j].size() + 1; k <= i ; k ++)
                     h [k] = '@';
           }
       }
   }
   
   return 0;
   
}
