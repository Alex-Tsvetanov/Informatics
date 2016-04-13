#include <cstdio>
#include <string.h>
#include <stack>
using namespace std;

int op(int a, int b){
    if (a==2)return b;
    return !(a&&b);
}

int main(){
    char expr[1024];
    char val[32];
    stack<int> s;
    int n;

    scanf("%s",expr);
    n = strlen(expr);
    while (scanf("%s",val)){
        if (val[0]=='2'){break;}
        s.push(2);
        for (int i=0;i<n;++i){
            if (expr[i]=='('){
                s.push(2);
            }
            else if (expr[i]==')'){
                int a = s.top();
                s.pop();
                s.top() = op(s.top(), a);
            }
            else{
                s.top() = op(s.top(), val[expr[i]-'a']-'0');
            }
        }
        printf("%d",s.top());
        s.pop();
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

*/
