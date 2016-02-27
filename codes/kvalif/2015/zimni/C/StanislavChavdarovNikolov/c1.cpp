#include <iostream>
#include <vector>

unsigned long long d(unsigned long long n)
{
    unsigned long long type = -1;
    unsigned long long idx = -1;
    std::vector<unsigned long long> count;
    for(unsigned long long i = 2;n != 0 and i <= n;++ i)
    {
        if(n % i == 0)
        {
            if(i != type)
            {
                count.push_back(1);
                idx ++;
                type = i;
            }
            else
                count[idx] ++;
            n /= i;
            i = 1;
        }
    }
    unsigned long long result = 1;
    for(unsigned long long i = 0;i < count.size();++ i)
        result *= (count[i]+1);
    return result;
}

int main()
{
    unsigned long long n, m;
    std::cin >> n;
    for(unsigned i = 0;i < n;++ i)
    {
        std::cin >> m;
        std::cout << d(m) << ' ';
    }
    std::cout << std::endl;
}
