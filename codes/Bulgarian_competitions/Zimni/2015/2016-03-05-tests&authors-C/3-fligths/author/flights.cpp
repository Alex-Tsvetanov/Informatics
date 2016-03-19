#include <stdio.h>
#include <list>
#define MAX_VALUE 1000000
#define MAX 20000

using namespace std;

struct Arc {
    int x;
    int d;
};

list<Arc> B[MAX];

int dist[MAX];
int visit[MAX];

int posHeap[MAX];
int heap[MAX];
int hsize;

int visitCount;
int n,m,k;
int minP;
int maxH,minH;

void read() {
    int i,j, x,y,d;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        Arc arc1, arc2;
        arc1.x = y; arc1.d = d;
        arc2.x = x; arc2.d = d;
        B[x].push_back(arc1);
        B[y].push_back(arc2);
    }
}

void hswap(int i, int j) {
    posHeap[heap[i]] = j;
    posHeap[heap[j]] = i;
    int k = heap[i];
    heap[i] = heap[j];
    heap[j] = k;
}

void moveDown(int x) {
    while (x< (hsize>>1)) {
        int child = 2*x +1;
        if (child + 1 < hsize && dist[heap[child + 1]] > dist[heap[child]]) {
            child++;
        }
        if (dist[heap[x]] > dist[heap[child]]) {
            break;
        }
        hswap(x, child);
        x = child;
    }
}

void moveUp(int x) {
    while (x>0) {
        int parent = (x-1)>>1;
        if (dist[heap[x]] < dist[heap[parent]]) break;
        hswap(x, parent);
        x = parent;
    }
}

int removeMin() {
    int res = heap[0];
    if (hsize <= 0) return -1;
    else {
        int last = heap[--hsize];
        if (hsize<minH) minH = hsize;

        if (hsize > 0) {
            heap[0] = last;
            moveDown(0);
        }
        return res;
    }
}

void add(int x) {
    posHeap[x] = hsize;
    heap[hsize++] = x;
    moveUp(hsize-1);
}

int mini(int x, int y) {
    return (x<y)? x : y;
}

void dijkstra() {

    dist[0] = MAX_VALUE;
    hsize = 0;
    add(0);

    int i;
    int min, k;
    bool flag = true;
    while (flag) {
        k = removeMin();
        if (k == -1) flag = false;
        else {
            visit[k] = 0;
            visitCount++;
            for(list<Arc>::iterator it=B[k].begin(); it !=B[k].end(); it++) {
                if(visit[it->x] && dist[it->x]<mini(dist[k],it->d)) {
                    dist[it->x] = mini(dist[k], it->d);
                    if (posHeap[it->x]>=0) moveUp(posHeap[it->x]);
                    else add(it->x);
                }
            }
        }
    }
}


int main() {
    read();
    int i,j;
    for(i=0; i<n; i++) {
        visit[i] = 1;
        dist[i] = 0;
        posHeap[i] = -1;
    }
    visitCount = 0;
    dist[0] = MAX;
    dijkstra();

    for(int i=1; i<n; i++)
        printf("%d ", dist[i]);
    printf("\n");

	return 0;
}
