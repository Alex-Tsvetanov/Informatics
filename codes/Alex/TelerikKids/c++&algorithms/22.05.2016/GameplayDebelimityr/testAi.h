#include<iostream>
#include<vector>
using namespace std;
vector<int> testAi(vector<int> param){
    vector<int> res;
    int x2,y2,sX,sY;
    cin>>x2>>y2>>sX>>sY;
    res.push_back(x2);
    res.push_back(y2);
    res.push_back(sX);
    res.push_back(sY);
    return res;
}
