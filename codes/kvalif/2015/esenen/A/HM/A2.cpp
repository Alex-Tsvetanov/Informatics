#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int towns, streets;

struct street{
    int from, to, w;
};

vector<street> vec;

int main(){
    cin >> towns >> streets;

    for(int i=0;i<streets;i++){
        street s;
        cin >> s.from >> s.to >> s.w;
        vec.push_back(s);
    }

    cout << 0;

    return 0;
}
