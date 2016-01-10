#include <stdio.h>
#include <algorithm>
using namespace std;

struct ind{
    int x;
    int y;
    int z;
};
int read();
void readArr(int [], int);
int getMin(int [], int);
int getMax(int [], int);
void getAnswers(int [], int, int&, ind [], int, int);
int getMaxOtg(ind [], int);
void printOtg(int, int);

int main(){
    int lenA = read();
    int a[lenA];
    readArr(a, lenA);
    int mi = getMin(a, lenA);
    int ma = getMax(a, lenA);
    int broiMinMax = 0;
    for(int i = 0;  i < lenA;  i++)
        if(a[i] == ma || a[i] == mi)
            broiMinMax++;
    ind otg[broiMinMax];
    int realLenMinMax = 0;
    getAnswers(a, lenA, realLenMinMax, otg, ma, mi);
    for(int i = 0;  i < realLenMinMax;  i++)
        otg[i].z = otg[i].y - otg[i].x;
    int maxOtg = getMaxOtg(otg, realLenMinMax);
    int broiMax = 0;
    for(int i = 0;  i < realLenMinMax;  i++){
        if(otg[i].z == maxOtg)
            broiMax++;
    }
    ind ok[broiMax];
    int broiOK = 0;
    for(int i = 0;  i < realLenMinMax;  i++){
        if(otg[i].z == maxOtg){
            ok[broiOK] = otg[i];
            broiOK++;
        }
    }
    if(broiMax > 1){
        for(int i = 1;  i < broiOK;  i++){
            if(ok[0].x + ok[0].y > ok[i].x + ok[i].y)
                ok[0] = ok[i];
        }
    }
    printOtg(ok[0].x, ok[0].y);
    return 0;
}
int read(){
    int c;
    scanf("%d", &c);
    return c;
}
void readArr(int a[], int n){
    for(int i = 0;  i < n;  i++)
        a[i] = read();
}
int getMin(int a[], int n){
    int m = a[0];
    for(int i = 1;  i < n;  i++)
        m = min(a[i], m);
    return m;
}
int getMax(int a[], int n){
    int m = a[0];
    for(int i = 1;  i < n;  i++)
        m = max(a[i], m);
    return m;
}
void getAnswers(int a[], int aLen, int& minMaxRealLen, ind otg[], int maX, int miN){
    for(int q = 0;  q < aLen;  q++){
        if(a[q] == miN){
            for(int i = q+1;  i < aLen;  i++){
                if(a[i] == maX){
                    otg[minMaxRealLen].x = q;
                    otg[minMaxRealLen].y = i;
                    minMaxRealLen++;
                }
            }
        }
        if(a[q] == maX){
            for(int i = q+1;  i < aLen;  i++){
                if(a[i] == miN){
                    otg[minMaxRealLen].x = q;
                    otg[minMaxRealLen].y = i;
                    minMaxRealLen++;
                }
            }
        }
    }
}
int getMaxOtg(ind a[], int len){
    int k = a[0].z;
    for(int i = 0;  i < len;  i++)
        k = max(a[i].z, k);
    return k;
}
void printOtg(int a, int b){
    a += 1;
    b += 1;
    printf("\n%d %d", a, b);
}
