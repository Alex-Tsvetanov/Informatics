#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

const int MAXN = 1024;
char s[MAXN], st[32];
int N;
int BOOLEVI_STOINOSTI[32];

bool Fun (char x, char y){
    if (x == '1' && y == '1') return 0;

    return 1;
}

bool Funint (int x, int y){
    if (x && y) return 0;
    return 1;
}

bool solve (int left, int right){

    vector<int> vec;
    stack<int> st;

    for (int i=left; i<=right; i++){
        if (s[i] >= 'a' && s[i] <= 'z' && st.empty()) vec.push_back (BOOLEVI_STOINOSTI[s[i] - 'a']);

        if (s[i] == '(') st.push (i);
        if (s[i] == ')') {
        //    cout << " ot " << left << " " << right << " ------> " << st.top()+1 << " " << i-1 << endl;

            if (st.size() == 1) vec.push_back (solve (st.top()+1, i-1));
            st.pop ();
        }
    }

//cout << "left = " << left << "  right = " <<  right << endl;

//cout << vec[0] << " " ;
    int last = vec[0];
    for (int i=1; i<vec.size(); i++){
    last = Funint (last, vec[i]);
  //  cout << vec[i] << " " ;
    }
  //  cout << endl;

//cout << "last = " << last << endl;

    return last;
}

int main (){

    scanf ("%s",s);

    N = strlen (s);

    while (1){
        scanf ("%s",st);

        if (st[0] == '2') break;

        for (int i=0; i<strlen(st); i++)
            BOOLEVI_STOINOSTI[i] = st[i] - '0';

        printf ("%d",solve (0, N-1));
    }

    printf ("\n");
    return 0;
}
