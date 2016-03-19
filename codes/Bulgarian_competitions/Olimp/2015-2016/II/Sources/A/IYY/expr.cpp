#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<set>
using namespace std;
set <char> let;
set <char>::iterator it;
int code[1001];
char b[27];
stack <char> cur;
int revp[1001],c[1001];
const char res[2][2]={{1,1},
                      {1,0}};
int main () {
    string a;
    int n,cur1=2,len=0,num1,num2,i;
    cin >> a ;
    n=a.size();
    for (i=0; i<n; i++) {
        if ((a[i]!='(')&&(a[i]!=')')) let.insert(a[i]);
        }
    for (it=let.begin(); it!=let.end(); it++) {
        code[(*it)]=cur1++;
        }
    for (i=0; i<n; i++) {
        if (a[i]=='(') {
           if ((i!=0)&&(a[i-1]!='(')) {
              for (;;) {
                  if (cur.empty()==1) break;
                  if (cur.top()==-2) break;
                  revp[len++]=cur.top();
                  cur.pop();
                  }
              cur.push(-1);
              }
           cur.push(-2);
           }
        else if (a[i]==')') {
                for (;;) {
                    if (cur.top()==-2) {
                       cur.pop();
                       break;
                       }
                    revp[len++]=cur.top();
                    cur.pop();
                    }
                }
        else { if ((i!=0)&&(a[i-1]!='(')) {
                  for (;;) {
                      if (cur.empty()==1) break;
                      if (cur.top()==-2) break;
                      revp[len++]=cur.top();
                      cur.pop();
                      }
                  cur.push(-1);
                  }
               revp[len++]=code[a[i]]; }
        }
    for (;;) {
        if (cur.empty()==1) break;
        revp[len++]=cur.top();
        cur.pop();
        }
    for (;;) {
        scanf("%s",&b);
        n=strlen(b);
        for (i=2; i<n+2; i++) {
            c[i]=b[i-2]-'0';
            }
        c[0]=0; c[1]=1;
        if (b[0]=='2') break;
        for (i=0; i<len; i++) {
            if (revp[i]>=0) cur.push(revp[i]);
            else { num1=cur.top(); cur.pop();
                   num2=cur.top(); cur.pop();
                   cur.push(res[c[num1]][c[num2]]); }
            }
        printf("%d",cur.top());
        cur.pop();
        }
    cout << endl ;
    return 0;
}
