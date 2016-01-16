#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

std::vector<std::pair<unsigned, unsigned> > output;
unsigned answer(unsigned curr, unsigned input)
{
    unsigned ret = 0;
    while(input > 1)
    {
        if(input % curr != 0)
            return 0;
        input /= curr;
        ret ++;
    }
    return ret;
}

int main()
{
    unsigned input;
    std::cin >> input;

    for(unsigned curr = sqrt(input);curr >= 2;-- curr)
    {
        if(input % curr == 0)
        {
            unsigned ans = answer(curr, input);
            if(ans > 0)
                output.push_back(std::pair<unsigned, unsigned>(curr, ans));
        }
    }

    std::cout << output.size() << std::endl;
    for(unsigned i = 0;i < output.size();++ i)
        std::cout << output[i].first << " " << output[i].second << std::endl;

    return 0;
}

