(I7
I239
I19
(dp0
Vhare.%l
p1
(Vd.cpp
p2
S'#include <bits/stdc++.h>\n#define endl \'\\n\'\n\n#define int long long\n\nusing namespace std;\nconst int MAXN = (1 << 20);\n\nint A, B, C;\n\nvoid read()\n{\n    cin >> A >> B >> C;\n}\n\nint euclid(int a, int b, int &x, int &y)\n{\n    if(a == 0)\n    {\n        x = 0;\n        y = 1;\n        return b;\n    }\n\n    int new_x, new_y;\n    int ret = euclid(b % a, a, new_x, new_y);\n\n    x = new_y - (b / a) * new_x;\n    y = new_x;\n\n    return ret;\n}\n\nmap<int, int> dist;\n\nvoid bfs(int x)\n{\n    dist[x] = 0;\n    queue<int> q;\n    q.push(x);\n\n    while(!q.empty())\n    {\n        int u = q.front();\n        q.pop();\n        if(u == C) return;\n\n        if(!dist.count(u - A))\n            q.push(u - A), dist[u - A] = dist[u] + 1;\n        if(!dist.count(u + A))\n            q.push(u + A), dist[u + A] = dist[u] + 1;\n        if(!dist.count(u + B))\n            q.push(u + B), dist[u + B] = dist[u] + 1;\n        if(!dist.count(u - B))\n            q.push(u - B), dist[u - B] = dist[u] + 1;\n    }\n\n}\n\nvoid solve()\n{\n    int x, y;\n    int d = euclid(A, B, x, y);\n\n    if(C % d != 0)\n    {\n        cout << "Impossible" << endl;\n        return;\n    }\n\n    bfs(0);\n    cout << dist[C] << endl;\n}\n\n#undef int\nint main()\n{\n\tios_base::sync_with_stdio(false);\n\tcin.tie(NULL);\n\n    read();\n    solve();\n    return 0;\n}\n'
p3
tp4
stp5
.