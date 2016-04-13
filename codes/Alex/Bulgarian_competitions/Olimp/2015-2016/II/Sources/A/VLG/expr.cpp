#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack <int> Q;
int n;

bool f(bool a, bool b) {
    return (a == 0 || b == 0);
}

bool answer(string S) {
    int i, k, p;

    while(!Q.empty()) {
        Q.pop();
    }

    for(i=0; i<n; i++) {

        if(S[i] == ')') {
            k= Q.top();
            Q.pop();
            Q.pop();

            if(!Q.empty()) {
                p= f(Q.top(), k);
                Q.pop();
            }
            else p= k;
            Q.push(p);
        }

        else {
            if(S[i] == '(') Q.push(2);
            else {
                if(!Q.empty() && (Q.top() == 0 || Q.top() == 1)) {
                    k= f(Q.top(), S[i]-'0');
                    Q.pop();
                    Q.push(k);
                }
                else Q.push(S[i]-'0');
            }
        }
    }

    return Q.top();
}

void read() {
    int i;
    string s, st, S;
    char ch;

    cin>>s;
    n= s.size();

    string ans= "";

    while(1) {
        cin.get(ch);
        cin>> st;
        if(st == "2") break;

        S= "";
        for(i=0; i<n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') S+= st[s[i] - 'a'];
            else S+= s[i];
        }

        ans+= char(answer(S) + '0');
    }

    cout<<ans<<endl;
}

int main() {

    read();

    return 0;
}
