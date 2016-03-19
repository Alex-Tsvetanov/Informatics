#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 3000

using namespace std;

int n,m;
vector<int> A[MAX];
int Visit[MAX];

int bfs(int k) {
    int V[MAX];
    for(int i=0; i<n; i++) V[i] = MAX;
    V[k] = 0;

    queue<int> q;
    vector<int> vec;
    q.push(k);
    vec.push_back(k);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for(vector<int>::iterator it=A[p].begin(); it!=A[p].end(); it++) {
            if (V[*it]==MAX) {
                V[*it]=V[p]+1;
                q.push(*it);
                vec.push_back(*it);
            }
        }
    }

    int max=0;
    for(int i=0; i<n; i++)
        if (V[i]>max) max = V[i];

    if (max == MAX) {
        for(vector<int>::iterator it=vec.begin(); it!=vec.end(); it++) {
            Visit[*it] = 1;
        }
    }

    return max;
}

int main() {
    scanf("%d %d", &n, &m);
    int x,y;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        A[x].push_back(y);
    }

    int D[MAX];

    for(int i=0; i<n; i++) {
        Visit[i] = 0;
        D[i] = MAX;
    }

    for (int i=0; i<n; i++) {
        if (Visit[i] == 0) {
            D[i] = bfs(i);
            Visit[i] = 1;
        }
    }
    int min = MAX;
    for(int i=0; i<n; i++)
        if (min>D[i]) min = D[i];

    if(min == MAX) printf("0");
    else {
        int k = 0;
        for(int i=0; i<n; i++) if (D[i]==min) k++;
        printf("%d\n", k);
        for(int i=0; i<n; i++)
            if (D[i]==min) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
