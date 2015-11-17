#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

long long maximal[1 << 18];
long long basket[1 << 18];
int jumps[256];
queue<int> pos;
long long maxValue = -1;
int maxIndex = -1;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ;  i < m;  i ++){
        cin >> jumps[i];
    }
    sort(jumps, jumps + m);
    for(int i = 0; i <= n; i ++){
        cin >> basket[i];
    }

    maximal[0] = basket[0];
    pos.push(0);

    while(!pos.empty()){

        int index = pos.front();
        pos.pop();

        for(int i = 0 ; i < m; i ++){
            if(index +  jumps[i] <= n){
                if((maximal[index] + basket[index + jumps[i]] > maximal[index + jumps[i]]) || maximal[index] == 0){
                    maximal[index + jumps[i]] = maximal[index] + basket[index + jumps[i]];
                    pos.push(index + jumps[i]);
                }
            }
            else{
                if(maxValue < maximal[index]){
                    maxValue = maximal[index];
                    maxIndex = index;
                }
                break;
            }
        }

    }

    cout << maxValue << ' ' << maxIndex << '\n';
    return 0;
}

