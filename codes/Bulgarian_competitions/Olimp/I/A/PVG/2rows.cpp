#include <iostream>
#include <vector>
using namespace std;

vector<int> common(int* a1, int a1size, int* a2, int a2size) {
    vector<int> res;
    for(int i=0;i<a1size;i++) {
        int n = a1[i];
        for(int i=0;i<a2size;i++) {
            if(a2[i] == n) { res.push_back(n); break; }
        }
    }
    return res;
}

bool mergable(int* a1, int a1size, int* a2, int a2size) {
    vector<int> c1 = common(a1,a1size,a2,a2size);
    vector<int> c2 = common(a2,a2size,a1,a1size);
    for(int i=0;i<c1.size();i++) {
        if(c1[i]!=c2[i]) return 0;
    }
    return 1;
}

bool mergable() {
    int n1, n2;
    cin >> n1;
    int a1[n1];
    for(int i=0;i<n1;i++) cin >> a1[i];
    cin >> n2;
    int a2[n2];
    for(int i=0;i<n2;i++) cin >> a2[i];
    return mergable(a1, n1, a2, n2);
}

int main()
{
    bool b[5];
    for(int i=0;i<5;i++) b[i] = mergable();
    for(int i=0;i<5;i++) cout << b[i];
    return 0;
}
