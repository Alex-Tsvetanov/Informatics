#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector <string> split;
//vector <vector<string>> graph;
string input;
vector<int> values;
int nextValue = 0;
map<char, int> chars;
map<char, bool> used;
pair<int,int> solve(int index){
    cout<<"starting from  "<<index<<endl;
    int sum=0;
    int i=0;
    while(i<input.size()){
        if(!used[input[i]]){
            used[input[i]]=true;
            chars[input[i]] = values[nextValue];
        }
        if(input[i]=='('){
            pair<int,int> temp = solve(i+1);
            sum = sum xor temp.first;
            i=temp.second;
        }else if(input[i]==')'){
            return make_pair(sum,i);
        }else if(input[i]!=' '){
            if(!used[input[i]]){
                used[input[i]]=true;
                chars[input[i]] = values[nextValue];
            }
            sum = sum xor input[i];
        }
        i++;
    }
    return make_pair(sum,i);
}


int main(){

    getline(cin,input);
    int endSum = 0;
    for(int i=0;i<input.size();i++){
            cout<<(int)input[i] - 96<<endl;
            if(input[i]!='(' && input[i]!=')' && input[i]!=' ')
            values.push_back((int)input[i] - 96);
        }
    do{
        for(int i=0;i<values.size;i++){
            int ka;
            cin>>ka;
            values.push_back(ka);
        }
        endSum = endSum xor solve(0).first;
    }while(input[0]!='2');
    //cout<<input;
    cout<<endSum;
    return 0;
}
