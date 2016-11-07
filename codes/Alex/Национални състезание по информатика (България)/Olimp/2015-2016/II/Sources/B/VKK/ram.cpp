#include <iostream>
#include <vector>

struct Pair
{
    Pair(int x, int y) :
        x(x), y(y)
    {
    }

    int x;
    int y;
};

enum
{
    Yes = 1,
    No = 0,
    Impossible = 2
};

int isResult(int m, int n, int K)
{
    int broken;

    if (m > n) {
        broken = 2 * n - 1;
    } else {
        broken = 2 * m;
    }

    int total = 2 * m * n + m + n;
    int left = total - broken;

    if (left == K) {
        return Yes;
    } else if (left > K) {
        return Impossible;
    } else {
        return No;
    }

}

int main()
{
    int K;
    std::cin >> K;

    std::vector<Pair> pos;

    int m = 1;
    int n = 1;

    int ksq = K * K;

    for (int m = 1; m < K; ++m)
    {
        for(int n = m; n < K; ++n)
        {
            int res;

            res = isResult(m, n, K);
            if (res == Yes) {
                pos.push_back(Pair(m, n));
            } else if (res == Impossible) {
                break;
            }

            res = isResult(n, m, K);
            if (res == Yes) {
                pos.push_back(Pair(n, m));
            } else if (res == Impossible) {
                break;
            }

        }
    }

exit_loop:

    std::cout << pos.size() << '\n';

    for (int i = 0, len = pos.size(); i < len; ++i)
    {
        Pair p = pos[i];
        std::cout << p.x << ' ' << p.y << '\n';
    }

    std::cout << std::endl;

    return 0;
}
