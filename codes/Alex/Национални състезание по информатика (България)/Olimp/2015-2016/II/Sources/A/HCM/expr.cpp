#include<iostream>
#include<utility>

using namespace std;

int q(int a, int b){
    if(a==1 && b==1) return 0;
    return 1;
}

string f(string s){
    int n = s.size();
    int res = s[0]-48;
    for(int i=1;i<n;i++){
        res = q(res,s[i]-48);
    }
    string kon;
    kon += char(res+48);
    return kon;
}

pair<string,int> rec(string s, int i,int nom){
    string m="";
    int slen = s.size();
    for(int j=i;j<slen;j++){
        if(s[j]=='('){
            ///cout << "BEG " << nom+1 << endl;
            pair<string,int> p = rec(s,j+1,nom+1);
            m+=f(p.first);
            j+=p.second+1;
        }
        else if(s[j]==')'){
            ///cout << "FIN: " << nom  << " --> " << f(m) << " from " << m << endl;
            return make_pair(m,j-i);
        }
        else{
            m+=s[j];
            ///cout << m << endl;
        }
    }
    return make_pair(m,0);
}

int main(){

    string s;
    cin >> s;

    string real = s;
    string k;
    cin >> k;

    while(k[0]!='2'){
        int pn=s.size();
        for(int i=0;i<pn;i++){
            if(s[i]!='(' && s[i]!=')')s[i] = k[s[i]-97];
        }
        cout << f(rec(s,0,0).first);
        s=real;
        cin>>k;
    }

    return 0;
}
/*
a(a)(ab(ca)bb)c
011
100
010
111
001
2

should return 1

ab(cdcc)(ab(bab(dfe(feed)ac)cac)ddeeee(cacab(ca)))eab
001101
2

should return 1

ab(c(a(b)c)a)bd
1011
2

should return 0
*/
