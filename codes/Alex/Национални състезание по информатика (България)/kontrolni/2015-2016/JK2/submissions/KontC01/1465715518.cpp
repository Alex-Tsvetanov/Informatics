(I7
I239
I21
(dp0
Vproject.%l
p1
(Vb.cpp
p2
S'#include <bits/stdc++.h>\n#define endl \'\\n\'\n\n#define int long long\n\nusing namespace std;\nconst int MAXN = (1 << 20);\nconst int inf = (int)1e16 + 42;\n\nint n, m;\nint inpu[MAXN], inpv[MAXN], inpw[MAXN];\nvector<pair<int, int> > par[MAXN], G[MAXN];\n\nvoid read()\n{\n    cin >> m >> n;\n    for(int i = 0; i < m; i++)\n    {\n        int u, v, w;\n        cin >> u >> v >> w;\n        G[u].push_back({v, w});\n\n        inpu[i] = u;\n        inpv[i] = v;\n        inpw[i] = w;\n    }\n}\n\nbool visited[MAXN];\nvector<int> st;\n\nvoid dfs_topsort(int u)\n{\n    visited[u] = true;\n    for(auto it: G[u])\n        if(!visited[it.first])\n            dfs_topsort(it.first);\n\n    st.push_back(u);\n}\n\nint root, dp[MAXN], answer;\n\nint rec(int u)\n{\n    int &memo = dp[u];\n    if(memo != -1)\n        return memo;\n\n    memo = 0;\n    for(auto it: G[u])\n        memo = max(memo, it.second + rec(it.first));\n\n    return memo;\n}\n\nint fr[MAXN], bk[MAXN];\n\nint dfs_front_mn(int u)\n{\n    int &memo = fr[u];\n    if(memo != -1)\n        return memo;\n\n    if(u == root)\n        return memo = 0;\n\n    memo = inf;\n    for(auto it: par[u])\n        memo = min(memo, it.second + dfs_front_mn(it.first));\n\n    return memo;\n}\n\nvoid solve()\n{\n    for(int i = 0; i < n; i++)\n        if(!visited[i])\n            dfs_topsort(i);\n\n    root = st.back();\n    memset(dp, -1, sizeof(dp));\n    memset(bk, -1, sizeof(bk));\n    memset(fr, -1, sizeof(fr));\n    answer = rec(root);\n\n    cout << answer << endl;\n\n    for(int i = 0; i < n; i++)\n        for(auto e: G[i])\n            par[e.first].push_back({i, e.second});\n\n    for(int v: st)\n        if(fr[v] == -1)\n            dfs_front_mn(v);\n\n    for(int i = 0; i < m; i++)\n        cout << fr[inpu[i]] << " " << answer - (dp[inpv[i]] + inpw[i]) << endl;\n}\n\n#undef int\nint main()\n{\n\tios_base::sync_with_stdio(false);\n\tcin.tie(NULL);\n\n    read();\n    solve();\n    return 0;\n}\n'
p3
tp4
stp5
.