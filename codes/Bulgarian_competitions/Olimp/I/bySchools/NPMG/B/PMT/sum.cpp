#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int a[10] = {0, 1, 2, 2, 4, 4, 6, 6, 9, 9};
int read();

int main(){
    printf("\n%d", f(read()));
    return 0;
}
int read(){
    int c;
    scanf("%d", &c);
    return c;
}
