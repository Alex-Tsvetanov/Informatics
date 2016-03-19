#include <iostream>
#include <cstdlib>
#include <vector>
#include <tr1/unordered_map>
#include <cstring>
#include <queue>

const int maxn = 200100;
const int inf = (1 << 30) + (1 << 29) + (1 << 28);
int d[maxn], vis[maxn] = {0};
int n;

std::tr1::unordered_map<int, int> m[maxn];

void init() {
    for (int i = 0; i < n; i++)
        d[i] = inf;
    std::memset(vis, 0, sizeof(vis));
}

struct el {
   int name;
   int serial;
   int val;

   el() {}
   el (int n, int s, int v) {name = n; serial = s; val = v;}
};

bool operator < (const el& u, const el& v) {
    return u.val > v.val;
}

struct ModPQ {
    int ids[maxn];

    std::priority_queue<el> pq;

    ModPQ() {
        std::memset(ids, 0, sizeof(ids));
    }

    void push(int x, int val) {
        pq.push(el(x, ++ids[x], val));
    }

    el top() {
        el top = pq.top();
        while (!pq.empty() && top.serial != ids[top.name]) {
            pq.pop();
            top = pq.top();
        }

        return top;
    }

    void pop() {
        el top = pq.top();
        while (!pq.empty() && top.serial != ids[top.name]) {
            pq.pop();
            top = pq.top();
        }
        if (pq.size())
            pq.pop();
    }
    int size() {
      el top = pq.top();
        while (!pq.empty() && top.serial != ids[top.name]) {
            pq.pop();
            top = pq.top();
        }

        return pq.size();
    }
};

int price(int x, int y) {
    if (m[x].find(y) != m[x].end())
        return 0;
    else
        return 1;
}

int dijkstra (int s, int v) {
    ModPQ pq;
    d[s] = 0;
    pq.push(s, d[s]);

    while (pq.size()) {
        el top = pq.top();
        pq.pop();

        int b = top.name;
      //  std::cout << "visit " << b + 1 << " " << d[b] << std::endl;
        std::tr1::unordered_map<int, int>::iterator it = m[b].begin();
        while (it != m[b].end()) {
        //    std::cout << "    neigh " << it->first + 1 << std::endl;
            int e = it->first;
            int price = it->second;
        //    std::cout << "    " << d[b] << " " << price << " " << d[e] << std::endl;
            if (d[b] + price < d[e]) {
                d[e] = d[b] + price;
                pq.push(e, d[e]);
            }

            ++it;
        }
    }

    return d[v];
}

int main(){
    std::ios::sync_with_stdio(false);
    int a, b;
    std::cin >> n >> a >> b;
    init();

    int x, y;

    while(std::cin >> x >> y) {
            --x, --y;
        std::tr1::unordered_map<int, int>::iterator it = m[y].find(x);
        m[x][y] = 0;

        if (it == m[y].end())
            m[y][x] = 1;
    }

    x = dijkstra(a - 1, b - 1);

    if (x == inf) {
        std::cout << "X" << std::endl;
    } else {
        std::cout << x << std::endl;
    }
    return 0;
}
/*
4 1 4
4 3
3 2
1 2
4 2
*/
