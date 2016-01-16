#include <iostream>
#include <vector>

bool isPrime(unsigned long long number)
{
    for(unsigned long long curr = 2;curr*curr <= number;curr ++)
    {
        if(number % curr == 0)
            return false;
    }
    return true;
}

int main()
{
    std::string input;
    std::cin >> input;

    std::vector<unsigned long long> primes;
    unsigned long long curr = 2, output = 0;

    while(primes.size() <= 3000)
    {
        if(isPrime(curr))
            primes.push_back(curr);
        curr ++;
    }

    for(unsigned i = 0;i < input.size();++ i)
    {
        if(input[i] == '1')
            output += primes[i];
    }
    std::cout << output << std::endl;
    return 0;
}
