#include <stdio.h>
using namespace std;

int read();
struct way{
    int a;
    int b;
};
void readArr(way a[], int n);

int main(){
    int p = read();
    int m = read();
    way w[m];
    readArr(w, m);
    int k = read();
    int a[p];
    for(int i = 0;  i < p;  i++)
        a[i] = 0;
    for(int i = 0;  i < m;  i++){
        a[w[i].a - 1] += 1;
        a[w[i].b - 1] += 1;
    }
    int broi = 0;
    for(int i = 0;  i < p;  i++)
        if(a[i] >= k)
            broi++;
    printf("\n%d", broi);
    if(broi){
        printf("\n");
        for(int i = 0;  i < p;  i++)
            if(a[i] >= k)
                printf("%d ", i+1);
    }
    return 0;
}
int read(){
    int c;
    scanf("%d", &c);
    return c;
}
void readArr(way a[], int n){
    for(int i = 0;  i < n;  i++){
        a[i].a = read();
        a[i].b = read();
    }
}
