#include <stdio.h>

unsigned long** F;
unsigned char* exist;
unsigned* coins;
unsigned sum = 6;
unsigned n = 5;

void init ()
{
    scanf ("%u", &n);
    coins = new unsigned [n];
    for (unsigned i = 0 ; i < n ; i ++)
        scanf ("%u", &coins [i]);
    scanf ("%u", &sum);

    unsigned i;
    F = new unsigned long* [sum + 1];
    for (i = 0; i <= sum; i++)
        F [i] = new unsigned long [sum + 1];
    exist = new unsigned char [sum + 1];
    for (i = 0; i <= sum; i++)
        exist[i] = 0;
    for (i = 0; i < n; i++)
        exist[coins[i]] = 1;
}
void destroy ()
{
    delete []coins;
    unsigned i;
    for (i = 0; i <= sum; i++)
        delete[] F [i];
    delete[] F;
    delete[] exist;
}
unsigned long count (unsigned sum, unsigned max)
{
    unsigned long i;
    if (sum <= 0)
        return 0;
    if (F[sum][max] > 0)
        return F[sum][max];
    else
    {
        if (sum < max)
            max = sum;
        if (sum == max && exist[sum])
            F[sum][max] = 1;
        for (i = max; i > 0; i--)  
            if (exist[i])
                F[sum][max] += count(sum-i, i);
    }
    return F[sum][max];
}
int main()
{
    init();
    printf("%lu", count(sum, sum));
    destroy ();
}
