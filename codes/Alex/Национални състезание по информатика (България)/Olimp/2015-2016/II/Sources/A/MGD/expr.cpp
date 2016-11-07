#include  <iostream>
#include  <cstdlib>
#include  <stack>
using  namespace  std;

string values;
string izraz;

void normalize(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 'a';
    }
}

int AND_GATE(int x, int y) {
    if (x == 1 && y == 1) return 0;
    else return 1;
}

int calculate(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        //if (!st.empty()) cout << st.top() << endl;
        if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25) {
            if (!st.empty() && (st.top() == 0 || st.top() == 1)) {
                int val = AND_GATE((int)(values[s[i] - 'a'] - '0'), st.top());
                st.pop();
                st.push(val);
            } else {
                int val = (int)(values[s[i] - 'a'] - '0');
                st.push(val);
            }
        } else if (s[i] == '(') {
            st.push(-1);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != -1) {
                int v1, v2;
                v1 = st.top();
                st.pop();
                v2 = st.top();
                st.pop();
                if (v2 == -1) {
                    st.push(v1);
                    break;
                }
                else st.push(AND_GATE(v1,v2));
            }
        }
    }

    return st.top();
}


int main() {
    cin >> izraz;

    cin >> values;
    string result = "";
    while (values != "2") {
        result += calculate(izraz);
        cin >> values;
    }

    cout << result << endl;

return 0;
}
