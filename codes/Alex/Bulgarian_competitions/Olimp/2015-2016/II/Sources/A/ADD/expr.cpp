#include <iostream>
using namespace std;
string s,si;
bool flag;
int index;
bool someFunc(bool a, bool b){
    if(a == true && b == false){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    cin>>s;
    for(int i = 0; i < s.size(); i++){
        cout<<si<<endl;
        if(flag == true && s[i] == ')'){
            for(int j = index+1; j < i-1; j++){
                si += s[i];
            }
        }
        if(s[i] == '('){
            flag = true;
            index = i;
        }
    }
    return 0;
}
