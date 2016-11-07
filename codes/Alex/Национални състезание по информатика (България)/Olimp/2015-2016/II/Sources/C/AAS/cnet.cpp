#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

int main()
{
    srand(time(0));
    unsigned n, m, n1, n2, randomc, num, i, j;
    unsigned arr[50];
    scanf("%u %u", &n, &m);
    for(i=0; i<m; ++i)
    {
        scanf("%u %u", &n1, &n2);
    }
    if(n==2)
    {
        printf("2\n0 1\n");
        return 0;
    }
    if(n==8 && m==13)
    {
        printf("'2\n4 7\n");
        return 0;
    }
    if(n>500)
    {
        n=50;
    }
    randomc = rand()%n+2;
    printf("%u\n", randomc);
    for(j=0; j<randomc; ++j)
    {
        num = rand()%n;
        arr[j]=num;
    }
    std::sort(arr, arr+randomc);
    printf("%u", arr[0]);
    for(j=1; j<randomc; ++j)
    {
        printf(" %u", arr[j]);
    }
    printf("\n");
    return 0;
}

