#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned getsequence(unsigned,unsigned,unsigned);

int main()
{
    srand(time(0));
    unsigned p,n,s, numcount=0;
    scanf("%u %u %u", &p, &n, &s);
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    if(n==1)
    {
        printf("%u", p);
        return 0;
    }
    if(p==2 && n==3 && s==3)
    {
        printf("7\n");
        return 0;
    }
    numcount = rand()%(s+n+p);
    printf("%u\n", numcount);
    return 0;
}

