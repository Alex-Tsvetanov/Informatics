#include <stdio.h>

unsigned* F;
unsigned* next;
unsigned n;
unsigned* p;

void solve ()
{
    scanf ("%u", &n);
    p = new unsigned [n + 1];
    for (unsigned i = 1 ; i <= n ; i ++)
	    scanf ("%u", &p[i]);
   
    F = new unsigned [n];
    next = new unsigned [n];

    unsigned k, i;
    for (i = 1; i <= n; i++)
        F[i] = 1;
    for (k = n; k >= 1; k--)
        for (i = k + 1; i <= n; i++)
            if (p[k] < p[i])
                if (1 + F[i] > F[k])
                {
                    F[k] = 1 + F[i];
                    next[k] = i;
                }
}
void print()
{
    unsigned i, max, index;
    for (max = F[index = 1], i = 2; i <= n; i++)
        if (F[i] > max)
        {
            max = F[i];
            index = i;
        }
    printf("Максимален брой кабели: %u\n", max);
    do
    {
        printf("%u ", p [index]);
        index = next[index];
    }
    while (index);
}

int main()
{
    solve();
    print();
}
