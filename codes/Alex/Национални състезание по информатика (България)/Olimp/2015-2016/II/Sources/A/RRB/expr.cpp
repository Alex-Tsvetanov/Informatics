#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>stoynosti;
int f(int x, int y){
    return 1 - x*y;
}
int f1(string expr, string st){
    int i, j;
    int result = st[expr[0]-'a'] - '0';
    for(i=1; i<expr.size(); i++){
        if(expr[i] >= 'a' && expr[i] <= 'z'){
            result = f(result, st[expr[i]-'a'] - '0');
        }
        else if (expr[i] == '('){
            string e1 = "";
            int brskobi = 1;
            for(j=i+1; brskobi > 0; j++){
                if(expr[j] == '('){
                    brskobi++;
                }
                else if(expr[j] == ')'){
                    brskobi--;
                }
                if(brskobi > 0){
                    e1 += expr[j];
                }
            }
            result = f(result, f1(e1, st));
            i = j+1;
        }
    }
    return result;
}
int main(){
    string s, s1;
    int i;
    cin >> s;
    do{
        cin >> s1;
        if(s1[0] != '2'){
            stoynosti.push_back(s1);
        }
    }while(s1[0] != '2');
    for(i=0; i<stoynosti.size(); i++){
        cout << f1(s, stoynosti[i]);
    }
    cout << '\n';
    return 0;
}
