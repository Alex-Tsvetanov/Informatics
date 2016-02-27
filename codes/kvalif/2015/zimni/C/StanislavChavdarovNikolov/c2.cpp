#include <iostream>

unsigned long long A[101][101];
unsigned long long B[101][101];
int x, y;
int s[101];

unsigned long long NOD(unsigned long long a, unsigned long long b)
{
    int r = -1;
    while(r != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    // A
    std::cin >> y >> x;
    for(unsigned i = 0; i < y; ++ i)
        for(unsigned j = 0; j < x; ++ j)
            std::cin >> A[j][i];

    for(unsigned i = 0; i < x; ++ i)
    {
        s[i] = 0;
        for(unsigned j = 0; j < y; ++ j)
            s[i] += A[i][j];
    }

    unsigned long long nod = s[0];
    for(unsigned i = 1; i < x; ++ i)
        nod = NOD(nod, s[i]);

    for(unsigned i = 0; i < y; ++ i)
    {
        s[i] = 0;
        for(unsigned j = 0; j < x; ++ j)
            s[i] += A[j][i];
    }
    for(unsigned i = 0; i < y; ++ i)
        nod = NOD(nod, s[i]);

    // B
    std::cin >> y >> x;
    for(unsigned i = 0; i < y; ++ i)
        for(unsigned j = 0; j < x; ++ j)
            std::cin >> A[j][i];

    for(unsigned i = 0; i < x; ++ i)
    {
        s[i] = 0;
        for(unsigned j = 0; j < y; ++ j)
            s[i] += A[i][j];
    }

    unsigned long long nod2 = s[0];
    for(unsigned i = 1; i < x; ++ i)
        nod2 = NOD(nod2, s[i]);

    for(unsigned i = 0; i < y; ++ i)
    {
        s[i] = 0;
        for(unsigned j = 0; j < x; ++ j)
            s[i] += A[j][i];
    }
    for(unsigned i = 0; i < y; ++ i)
        nod2 = NOD(nod2, s[i]);
    std::cout << nod << " " << nod2 << std::endl;
    if(nod % nod2 == 0 or nod2 % nod == 0)
        std::cout << 'Y';
    else
        std::cout << 'N';
    std::cout << std::endl;
    return 0;
}
