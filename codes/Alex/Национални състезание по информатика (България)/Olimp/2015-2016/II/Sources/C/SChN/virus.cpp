#include <iostream>
#include <cmath>

unsigned boxes[10][2000]; // 250 max, 2000 to be safe
unsigned n;

void addInBoxes(unsigned id)
{
    unsigned box = 0, original = id;
    while(id > 0)
    {
        if(id % 2 == 1)
        {
            boxes[box][0] ++;
            boxes[box][boxes[box][0]] = original;
        }
        id /= 2;
        box ++;
    }
}

int main()
{
    std::cin >> n;

    unsigned long long steps = ((unsigned)log2(n))+1;

    std::cout << steps << std::endl;
    if(n <= 500)
    {
        for(unsigned i = 0;i < n;++ i)
            addInBoxes(i+1);
        for(unsigned i = 0;i < steps;++ i)
        {
            std::cout << boxes[i][0] << ' ';
            for(int j = 0;j < boxes[i][0];++ j)
                std::cout << boxes[i][1+j] << ' ';
            std::cout << '\n';
        }
    }
    return 0;
}
