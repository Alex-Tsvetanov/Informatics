#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    int b=0, e=s.size()-1;
    while(b<e) {
        if(s[b++] != s[e--]) return 0;
    }
    return 1;
}

int getAnswer(const string& s) {
    int c = -1;
    for(unsigned int b=0;b<s.size();) {
        for(unsigned int e=s.size();e>b;e--) {
            string ss(s.begin()+b, s.begin()+e);
            if(isPalindrome(ss)) {
                b = e;
                c++;
                break;
            }
        }
    }
    return c;
}

int main() {
    string s;
    cin >> s;
    int c = getAnswer(s);
    cout << c;
    return 0;
}
