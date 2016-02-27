#include<iostream>
#include<queue>

using namespace std;

struct apple{
    int x, y, t;
    apple(int x = 0, int y = 0, int t = 0){
        this -> x = x;
        this -> y = y;
        this -> t = t;
    }
};

queue<apple> q;
bool table[1024][1024];

int main(){
    int n, m, t;
    cin >> n >> m >> t;
    for(int i , j; cin >> i >> j; ){
        q.push(apple(n-i, j-1));
    }
    int num = 0;
    while(!q.empty()){
        apple tmp = q.front();
        q.pop();
        if(table[tmp.x][tmp.y] == 0){
            num++;
            table[tmp.x][tmp.y] = 1;
            if(tmp.t < t){
                if(tmp.x - 1 > 0 && !table[tmp.x - 1][tmp.y]){
                        q.push(apple(tmp.x - 1, tmp.y, tmp.t + 1));
                }
                if(tmp.x + 1 < n && !table[tmp.x + 1][tmp.y]){
                        q.push(apple(tmp.x + 1, tmp.y, tmp.t + 1));
                }
                if(tmp.y - 1 > 0 && !table[tmp.x][tmp.y - 1]){
                        q.push(apple(tmp.x, tmp.y - 1, tmp.t + 1));
                }
                if(tmp.y + 1 < m && !table[tmp.x][tmp.y + 1]){
                        q.push(apple(tmp.x, tmp.y + 1, tmp.t + 1));
                }
            }
        }
    }
    cout << (n * m - num) << '\n';
    return 0;
}
