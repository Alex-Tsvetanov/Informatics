#include<iostream>
#include<math.h>
#include<vector>
#include<tuple>
#include<algorithm>
#define ll long long

using namespace std;

struct point{
    ll x, y, number;
};
ll n;
point m;
vector< pair<point, point> > vec;

struct sort_pred{
    bool operator()(const pair<point,point> &left, const pair<point,point> &right) {
        double a1 = sqrt(pow(left.first.x - left.second.x, 2.0) + pow(left.first.y - left.second.y, 2.0));
        double a2 = sqrt(pow(right.first.x - right.second.x, 2.0) + pow(right.first.y - right.second.y, 2.0));
        double b1 = sqrt(pow(left.first.x - m.x, 2.0) + pow(left.first.y - m.y, 2.0));
        double c1 = sqrt(pow(left.second.x - m.x, 2.0) + pow(left.second.y - m.y, 2.0));
        double b2 = sqrt(pow(right.first.x - m.x, 2.0) + pow(right.first.y - m.y, 2.0));
        double c2 = sqrt(pow(right.second.x - m.x, 2.0) + pow(right.second.y - m.y, 2.0));
        double one = (a1*a1 - b1*b1 - c1*c1)/(2.0 * b1 * c1);
        double two = (a2*a2 - b2*b2 - c2*c2)/(2.0 * b2 * c2);
        return one < two;
    }
};

int main(){
    cin >> n >> m.x >> m.y;
    point f;
    cin >> f.x >> f.y;
    f.number = 1;
    for(int i=0;i<n-1;i++){
        point p;cin >> p.x >> p.y; p.number = i + 2;
        pair<point, point> k(f,p);
        vec.push_back(k);f = p;
    }
    sort(vec.begin(), vec.end(), sort_pred());
    for(int i=0;i<n-1;i++) cout << vec[i].first.number << " " << vec[i].second.number << endl;
    return 0;
}
/*
4
0 0
1 0
1 1
0 1
-1 0
*/
