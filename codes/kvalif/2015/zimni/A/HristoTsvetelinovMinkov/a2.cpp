#include<iostream>
#include<vector>
#define MAXM 100000000
#define MAXN 100000

using namespace std;
typedef unsigned long long ll;

bool used[MAXM];
bool starts[MAXM];
vector<vector<ll> > v;
ll n, m;

void bfs(ll start){
    used[start] = 1;
    for(ll i=0;i<m-1;i++){
        if(v[start][i] == 1){
            bfs(i);
        }
    }
}

int main(){
    cin >> m >> n;

    ll res = 0;

    v.reserve(m);
    for(ll i=0;i<m;i++){
        vector<ll> k;
        k.reserve(m);
        for(ll j=0;j<m;j++){
            k.push_back(0);
        }
        v.push_back(k);
    }

    ll from, to;
    for(ll i=0;i<n;i++){
        cin >> from >> to;
        v[from][to] = 1;
        for(ll h = from+1;h<=to;h++){
            v[from][h] = 1;
        }
        starts[from] = true;
    }

    for(ll i=0;i<m;i++){
        if(used[i] == false && starts[i] == true){
            bfs(i);
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
