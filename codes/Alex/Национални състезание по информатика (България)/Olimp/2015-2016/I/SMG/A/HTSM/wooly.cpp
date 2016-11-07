#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;
typedef unsigned long long l;

string m1;
string m2;

string rev(string s){
    int len = s.size();
    for(int i=0;i<len/2;i++){
        char p = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = p;
    }
    return s;
}

string toBin(l num){
    string res = "";
    while(num > 0){
        res += (num%2)+48;
        num /=2;
    }
    rev(res);
    return res;
}

l toNum(string s){
    l res = 0;
    int len = s.size();
    int po = 0;
    for(int i=len-1;i>=0;i--){
        if(s[i] == '1'){
            res += pow(2, len-i-1);
        }
    }
    return res;
}

int main(){

    cin >> m1 >> m2;
    int dif = m1.size() - m2.size();

    if(dif > 0){
        m2 = rev(m2);
        for(int i=0;i<dif;i++)m2+='0';
        m2 = rev(m2);
    }else if(dif < 0){
        m1 = rev(m1);
        for(int i=0;i<-1*(dif);i++)m1+='0';
        m1 = rev(m1);
    }

    string res = "";
    char naum = '0';
    for(int i=max(m1.size(),m2.size())-1;i>=0;i--){
        if(m1[i] == '?' && m2[i] == '0'){
            if(naum == '?'){
                res += '?';
                naum = '?';
            }else if(naum == '1'){
                res += '?';
                naum = '?';
            }else{
                res += '?';
                naum = '0';
            }
            continue;
        }
        if(m1[i] == '?' && m2[i] == '1'){
            if(naum == '?'){
                res += '?';
                naum = '?';
            }else if(naum == '1'){
                res += '?';
                naum = '1';
            }else{
                res += '?';
                naum = '?';
            }
            continue;
        }
        if(m1[i] == '?' && m2[i] == '?'){
            res += '?';
            naum = '?';
            continue;
        }
        if(m1[i] == '0' && m2[i] == '0'){
            if(naum == '?'){
                res += '?';
                naum = '0';
            }else if(naum == '1'){
                res += '1';
                naum = '0';
            }else{
                res += '0';
                naum = '0';
            }
            continue;
        }
        if(m1[i] == '0' && m2[i] == '1'){
            if(naum == '?'){
                res += '?';
                naum = '?';
            }else if(naum == '1'){
                res += '0';
                naum = '1';
            }else{
                res += '1';
                naum = '0';
            }
            continue;
        }
        if(m1[i] == '0' && m2[i] == '?'){
            if(naum == '?'){
                res += '?';
                naum = '?';
            }else if(naum == '1'){
                res += '?';
                naum = '?';
            }else{
                res += '?';
                naum = '0';
            }
            continue;
        }
        if(m1[i] == '1' && m2[i] == '0'){
            if(naum == '?'){
                res += '?';
                naum = '?';
            }else if(naum == '1'){
                res += '0';
                naum = '1';
            }else{
                res += '1';
                naum = '0';
            }
            continue;
        }
        if(m1[i] == '1' && m2[i] == '1'){
            if(naum == '?'){
                res += '?';
                naum = '1';
            }else if(naum == '1'){
                res += '1';
                naum = '1';
            }else{
                res += '0';
                naum = '1';
            }
            continue;
        }
        if(m1[i] == '1' && m2[i] == '?'){
            if(naum == '?'){
                res += '?';
                naum = '?';
            }else if(naum == '1'){
                res += '?';
                naum = '1';
            }else{
                res += '?';
                naum = '?';
            }
            continue;
        }
    }

    if(naum == '1')res += '1';
    if(naum == '?')res += '?';
    cout << rev(res);

    return 0;
}
