#include <iostream>
#define MAXN 10000
#include <vector>
#include <string>
using namespace std;
string s;
vector<vector<string> > dp;
bool isPalindrom(string s){
    int j = s.size()-1, i = 0;
    for(; i < s.size()/2; i++, j--){
        if(s[i] != s[j]){
            return 0;
        }
    }
    return 1;
}

int main(){
cin>>s;
dp.resize(s.size()+1);
for(int i = 0; i < s.size(); i++){
    dp[i].resize(1);
    dp[i][0] += s[i];
}
for(int i = 0; i < s.size(); i++){
    cout<<dp[i][0]<<endl;
}
for(int i = 0; i < s.size(); i++){
    for(int j = 1; j < s.size()-i; j++){
        dp[i].push_back(dp[i][j-1]+dp[i+j][0]);
    }
}

for(int i = 0; i < s.size(); i++){
    for(int j = dp[i].size()-1; j >= 0; j--){
        isPalindrom(dp[i][j]);
    }
}

/*for(int i = 0; i < s.size(); i++){
    for(int j = 0; j < dp[i].size(); j++){
       cout<<dp[i][j]<<" ";
    }cout<<endl;
}*/
return 0;
}

