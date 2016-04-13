#include <iostream>

int p, n, s;
unsigned long long memo[30][30];
bool saved[30][30];

unsigned long long solve(int leftSum, int leftNumbers, int indent)
{
    if(leftNumbers == 1)
    {
      //  for(int j = 0;j < indent;++ j)
      //      std::cout << ' ';
       // std::cout << "Returning " << std::min(leftSum, p) << "\n";
        if(leftSum > p)
            return p;
        else
            return leftSum;
    }
    if(saved[leftSum][leftNumbers])
        return memo[leftSum][leftNumbers];

    unsigned long long ans = 0;
    for(int i = 0;i < p and leftSum-i >= 0;++ i)
    {
        //for(int j = 0;j < indent;++ j)
       //     std::cout << ' ';
       // std::cout << "Calling solve(" << leftSum-i << ',' << leftNumbers-1 << ")\n";
        ans += solve(leftSum-i, leftNumbers - 1, indent + 1);
    }

    saved[leftSum][leftNumbers] = true;
    memo[leftSum][leftNumbers] = ans;
    return ans;
}

int main()
{
    std::cin >> p >> n >> s;

    std::cout << solve(s, n, 0) << std::endl;
    return 0;
}
