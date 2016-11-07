#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

char op[2][2] = {'1', '1', '1', '0'};

char pattern[1001];
char charmap[27];
int tracker = 0;

char eval() {
    signed char ans = -1;
    while(true) {
            //cout << tracker << endl;
            //cout << endl << ((signed int)ans) << endl;
            //if(ans == -1) cout << endl << -1 << endl;
            //else cout << endl << ans << endl;
        if(pattern[tracker] >= 'a' && pattern[tracker] <= 'z') {
            if(ans == -1) {
                ans = charmap[pattern[tracker++]-'a'];
            } else {
                ans = op[ans-'0'][charmap[pattern[tracker++]-'a']-'0'];
            }
        } else if(pattern[tracker] == '(') { // a pri posledovatelni otvariashti obli skobki?
                if(ans == -1) {
                    tracker++; // ili vinagi vav nachaloto na izvikvane na funkciata eval da ima? i da zapochne trackera ot -1?
                    ans = eval();
                }
                else {
                    tracker++;
                    ans = op[ans-'0'][eval()-'0'];
                }
        } else if(pattern[tracker] == ')') {
            tracker++;
            return ans;
        } else if(pattern[tracker] == '\0') {
            return ans; // ?!
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << ((signed int)('0')) << endl;
    cin.getline(pattern, 1001, '\n');
    cin.getline(charmap, 27, '\n');
    while(charmap[0] != '2') { // zashto izkarva nakraia 2?
        tracker = 0;
        cout << eval();
        cin.getline(charmap, 27, '\n');
    }
    cout << '\n';
    // da pusna I/O optimizaciite!!!
    return 0;
}
