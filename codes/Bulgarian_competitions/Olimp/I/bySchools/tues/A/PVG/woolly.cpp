#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pair {
    string s1, s2;
    string GetSum() {
        string sum;
        int size = max(s1.size(),s2.size());
        int b=0;
        for(int i=0;i<size;i++) {
            int c1 = 0, c2 = 0;
            if(s1.size() >= i+1) c1 = s1[ s1.size()-i-1 ] - '0';
            if(s2.size() >= i+1) c2 = s2[ s2.size()-i-1 ] - '0';
            int rez = c1+c2+b;
            if(rez>1) { b=1; rez-=2; }
            else b=0;
            sum += '0'+rez;
        }
        if(b) sum += '1';
        for(int i=0;i<sum.size()/2;i++) swap(sum[i], sum[sum.size()-i-1]);
        return sum;
    }
    Pair(string S1, string S2) : s1(S1), s2(S2) {}
};

bool increment_bin(bool *b, int bsize) {
    for(int i=bsize-1;i>=0;i--) {
        if(b[i]) { b[i]=0; }
        else {
            b[i]=1;
            return 0;
        }
    }
    return 1;
}

vector<Pair> get_combinations(string s1, string s2) {
    vector<Pair> ret;
    vector<int> ub;
    for(int i=0;i<s1.size();i++) {
        if(s1[i]=='?') ub.push_back(i);
    }
    for(int i=0;i<s2.size();i++) {
        if(s2[i]=='?') ub.push_back(i+s1.size());
    }
    int bsize = ub.size();
    bool b[bsize];
    for(int i=0;i<bsize;i++) b[i]=0;

    do {
        Pair p(s1, s2);
        for(int i=0;i<bsize;i++) {
            if(ub[i]<s1.size()) p.s1[ ub[i] ] = b[i]+'0';
            else p.s2[ ub[i]-s1.size() ] = b[i]+'0';
        }
        ret.push_back(p);
    }while(!increment_bin(b, bsize));


    ///ret.push_back(Pair(s1, s2));
    return ret;
}

string get_result(vector<string> s) {
    int sz = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i].size()>sz) sz=s[i].size();
    }
    char ret[sz+1];
    for(int i=0;i<sz;i++) {
        char c;
        if(s[0].size()>=i+1) c = s[0][ s[0].size()-i-1 ];
        else c = '0';
        ret[sz-i-1] = c;
        for(int j=1;j<s.size();j++) {
            if(s[j][s[j].size()-i-1] != c) { ret[sz-i-1]='?'; break; }
        }
    }
    ret[sz]=0;
    return ret;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<Pair> s;
    s = get_combinations(s1, s2);
    vector<string> sums;
    for(int i=0;i<s.size();i++) {
            string ss = s[i].GetSum();
        sums.push_back(ss);
    }
    cout << get_result(sums) << endl;
    return 0;
}
