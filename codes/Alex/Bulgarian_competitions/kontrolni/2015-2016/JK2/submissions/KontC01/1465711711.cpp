(I7
I239
I20
(dp0
Veconomy.%l
p1
(Va.cpp
p2
S'#include <bits/stdc++.h>\n#define endl \'\\n\'\n\nusing namespace std;\nconst int MAXN = (1 << 12);\nconst int max_value = 4042;\n\nint a, b, c, n;\nint d[MAXN];\n\nvoid read()\n{\n    cin >> a >> b >> c >> n;\n    for(int i = 1; i <= n; i++)\n        cin >> d[i];\n}\n\nint dp[MAXN][MAXN];\nint last[MAXN][MAXN];\n\nvoid solve()\n{\n    if(a > c)\n    {\n        cout << a << endl << 0 << endl;\n        return;\n    }\n\n    if(a + b < c)\n    {\n        cout << a + b << endl;\n        cout << -1 << endl;\n        return;\n    }\n\n    dp[0][0] = 1;\n    for(int i = 1; i <= n; i++)\n        for(int val = max_value; val >= 0; val--)\n            if(val - d[i] >= 0 && dp[i - 1][val - d[i]])\n            {\n                dp[i][val] = 1;\n                last[i][val] = 1;\n            }\n            else if(dp[i - 1][val])\n            {\n                dp[i][val] = 1;\n                last[i][val] = 0;\n            }\n\n    for(int to_add = 1; to_add <= max_value; to_add++)\n        if(dp[n][to_add] && a + to_add > c && a + to_add <= a + b)\n        {\n            int pos = n, sum = to_add;\n            set<int> st;\n\n            while(pos != -1)\n            {\n                if(last[pos][sum])\n                {\n                    st.insert(pos);\n                    sum -= d[pos];\n                }\n\n                pos--;\n            }\n\n            cout << a + to_add << endl;\n            cout << st.size() << endl;\n            for(int v: st)\n                cout << v << " ";\n            cout << endl;\n            return;\n        }\n\n    cout << a + b << endl;\n    cout << -1 << endl;\n    return;\n}\n\nint main()\n{\n\tios_base::sync_with_stdio(false);\n\tcin.tie(NULL);\n\n    read();\n    solve();\n    return 0;\n}\n'
p3
tp4
stp5
.