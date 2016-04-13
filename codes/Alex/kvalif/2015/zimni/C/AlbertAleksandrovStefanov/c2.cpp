#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
    srand(clock());
    int a = rand()%1000+1;
    srand(clock());
    int b = rand()%1000+1;
    char c = (a%b || b%a)?'Y':'N';
    printf("%i %i\n%c\n", a, b ,c);
    return 0;
}
