#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

char * findChar(char str[], char * c){
    char * i = c;
    for(i = c; *i != 'c'; i++){
    }
    return i;
}
int findValue(int a, int b){
    if(a == 1 && b == 1){
        return 0;
    }
    return 1;
}

struct S{
    char str[26];
};

int main(){

    char str[1000];
    cin>>str;

    char * last = strrchr(str, '(');
    char * next = last + 3;
    vector < S > v;
    S n;
    cin>>n.str;
    v.push_back(n);
    while(strcmp(n.str, "2") != 0){
            cin>>n.str;
            if(strcmp(n.str, "2") != 0){
                v.push_back(n);
            }
    }
    char subStr[1000];
    int p, k, u;
    bool flag = false;
    if(last == NULL){
        flag = true;
        p = str[0];
        k = str[1];
    }
    else{
        p = (int) *last++;
        k = (int) *last;
    }
    //p = (int) *last++;
    //k = (int) *last;
    u = findValue(p, k);
    for(int i = 0; i < v.size(); i++){
        u = findValue(0, 1);
        cout<<u;
    }
    cout<<endl;
    return 0;
}
