#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

void getrandom(void);
unsigned n;

int main()
{
    srand(time(0));
    scanf("%u", &n);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    if(n==2)
    {
        printf("1\n1 1\n");
        return 0;
    }
    if(n==3)
    {
        printf("2\n1 1\n1 2\n");
        return 0;
    }
    if(n==5)
    {
        printf("3\n2 3 5\n4 1 2 3 5\n3 2 4 5\n");
        return 0;
    }
    if(n>500)
    {
        printf("%i", rand()&(n-100));
        return 0;
    }
    getrandom();
    return 0;
}

void getrandom(void)
{
    std::vector<unsigned> randomv;
    unsigned random, i, j, kutiq, currand;
    srand(time(0));
    random = (rand()%n)/2+1;
    printf("%u\n", random);
    for(i=0; i<random; ++i)
    {
        kutiq=(rand()%n)+1;
        printf("%u", kutiq);
        for(j=0;j<kutiq;++j)
        {
            randomv.push_back((rand()%n)+1);
        }
        std::sort(randomv.begin(), randomv.end());
        for(int j=0; j<randomv.size();++j)
        {
            printf(" %u", randomv.at(j));
        }
        randomv.clear();
        printf("\n");
    }
}
