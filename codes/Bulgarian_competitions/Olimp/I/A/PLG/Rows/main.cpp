#include <iostream>
#include <stdio.h>

using namespace std;

bool contains(int a[], int num, int length);
int main()
{
    // ----------------------
    // Take Input
    int a, b;
    scanf("%d", &a);
    int row_a[a];
    for (int i = 0; i < a; i++) {
        int num;
        scanf("%d", &num);
        row_a[i] = num;
    }

    scanf("%d", &b);
    int row_b[b];
    for (int i = 0; i < b; i++) {
        int num;
        scanf("%d", &num);
        row_b[i] = num;
    }
    // Take Input
    // ----------------------

    // ----------------------
    // Generate row from all numbers by removing the copies
    int row[a+b];
    int rowIterator = 0;

    for (int i = 0; i < a; i++) {
        row[rowIterator] = row_a[i];
        rowIterator++;
    }
    for (int i = 0; i < b; i++) {
        if (contains(row, row_b[i], a)) {
            continue;
        }
        else {
            row[rowIterator] = row_b[i];
            rowIterator++;
        }
    }
    // Generate row from all numbers by removing the copies
    // ----------------------

    return 0;
}
bool contains(int a[], int num, int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] == num) {
            return true;
        }
    }
    return false;
}
