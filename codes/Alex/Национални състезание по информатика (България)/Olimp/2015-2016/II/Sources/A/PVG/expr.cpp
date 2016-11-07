#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool calcExpr(const string& in, const bool* data) {
    stack<bool> st;
    for(unsigned int i=0; i<in.size(); i++) {
        if(in[i] == '^') {
            bool a1 = st.top(); st.pop();
            bool a2 = st.top(); st.pop();
            st.push(!(a1&&a2));
        } else {
            st.push(data[(int)in[i]]);
        }
    }
    return st.top();
}

string getExpr(int& variables) {
    string s;
    string in;
    getline(cin, in);
    variables = 0;
    vector<int> st;
    st.push_back(0);
    for(unsigned int i=0;i<in.size();i++) {
        char& c = in[i];
        if(c >= 'a' && c <= 'z') {
            c -= 'a';
        } else if(c == '(') {
            st.push_back(0);
            continue;
        } else if(c == ')') {
            st.pop_back();
            if(st.empty()) continue;
            if(st[st.size()-1]>0) {
                s += '^';
            }
            continue;
        }
        if(variables <= c) variables = c;
        s += c;
        if(st[st.size()-1]>0) {
            s += '^';
        }
        st[st.size()-1]++;
    }
    return s;
}

bool getVars(bool* data) {
    string s;
    getline(cin, s);
    if(s[0] == '2') {
        return 0;
    }
    for(unsigned int i=0;i<s.size();i++) {
        data[i] = s[i] - '0';
    }
    return 1;
}

int main() {
    int vars;
    string expr = getExpr(vars);
    bool data[vars];
    vector<bool> results;
    while(getVars(data)) {
        results.push_back(calcExpr(expr, data));
    }
    for(unsigned int i=0;i<results.size();i++) {
        cout << results[i];
    }
    return 0;
}
