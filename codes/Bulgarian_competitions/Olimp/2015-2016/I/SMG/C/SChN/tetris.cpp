#include <iostream>
int main()
{
    unsigned x, y, k = 0, output = 0;
    char c;
    std::cin >> y >> x;

    for(unsigned i = 0;i < y;++ i)
    {
        bool line = true;
        for(unsigned j = 0;j < x;++ j)
        {
            std::cin >> c;
            if(c != '*')
                line = false;
        }
        if(!line)
        {
            output += (k*(k+1))/2;
            k = 0;
        }
        else
        {
            k ++;
        }
    }

    output += (k*(k+1))/2;
    std::cout << output << std::endl;
    return 0;
}

