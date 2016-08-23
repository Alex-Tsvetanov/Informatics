(I7
I239
I19
(dp0
Vhare.%l
p1
(Vd.cpp
p2
S'#include <bits/stdc++.h>\n#define endl \'\\n\'\n\n#define int long long\n\nusing namespace std;\nconst int MAXN = (1 << 20);\n\nint A, B, C;\n\nvoid read()\n{\n    cin >> A >> B >> C;\n}\n\nint euclid(int a, int b, int &x, int &y)\n{\n    if(a == 0)\n    {\n        x = 0;\n        y = 1;\n        return b;\n    }\n\n    int new_x, new_y;\n    int ret = euclid(b % a, a, new_x, new_y);\n\n    x = new_y - (b / a) * new_x;\n    y = new_x;\n\n    return ret;\n}\n\nvoid solve()\n{\n    int x, y;\n    int d = euclid(A, B, x, y);\n\n    if(C % d != 0)\n    {\n        cout << "Impossible" << endl;\n        return;\n    }\n\n    int to_inc = C / d;\n\n    x *= to_inc;\n    y *= to_inc;\n\n    cout << abs(x) + abs(y) << endl;\n\n\n}\n\n#undef int\nint main()\n{\n\tios_base::sync_with_stdio(false);\n\tcin.tie(NULL);\n\n    read();\n    solve();\n    return 0;\n}\n'
p3
tp4
stp5
.