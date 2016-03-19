#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<pair<int, int> >kraishta;
int main(){
    string s;
    int i, j, minbrrazdeliteli[10001];
    cin >> s;
    for(i=0; i<s.size(); i++){
        for(j=0; i-j>=0 && i+j < s.size() && s[i-j] == s[i+j]; j++){
            kraishta.push_back(make_pair(i-j, i+j));
        }
        for(j=0; i-j>=0 && i+j+1<s.size() && s[i-j] == s[i+j+1]; j++){
            kraishta.push_back(make_pair(i-j, i+j+1));
        }
    }
    sort(kraishta.begin(), kraishta.end());
    minbrrazdeliteli[0] = 0;
    for(i=1; i<=s.size(); i++){
        minbrrazdeliteli[i] = 100000;
    }
    for(i=0; i<kraishta.size(); i++){
        minbrrazdeliteli[kraishta[i].second+1] = min(minbrrazdeliteli[kraishta[i].second+1], minbrrazdeliteli[kraishta[i].first]+1);
    }
    minbrrazdeliteli[s.size()]--;
    cout << minbrrazdeliteli[s.size()] << '\n';
    return 0;
}
