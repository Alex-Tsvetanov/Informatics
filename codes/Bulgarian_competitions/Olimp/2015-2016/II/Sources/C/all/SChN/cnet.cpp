#include <iostream>
#include <queue>
#include <utility>

const unsigned int maxN = 3001;
const unsigned int maxM = 400001;

int n, m;
std::vector<unsigned long long> graph[maxN];
std::pair<int, int> next[maxM];
unsigned arr[maxN];

unsigned bfs(int start)
{
    int idx = 0;
    next[idx++] = std::pair<int, int>(start, 0);

    bool used[maxN];
    for(int i = 0;i < n;++ i)
        used[i] = false;

    unsigned max = 0;
    while(idx > 0)
    {
        idx --;
        std::pair<int, int> curr = next[idx];

        if(!used[curr.first])
        {
            used[curr.first] = true;
            if(curr.second > max)
                max = curr.second;

            int s = graph[curr.first].size();
            for(int i = 0;i < s;++ i)
            {
                if(!used[graph[curr.first][i]])
                    next[idx++] = std::pair<int, int>(graph[curr.first][i], curr.second+1);
            }
        }
    }
    for(unsigned i = 0;i < n;++ i)
        if(!used[i])
            return 0;
    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    int a, b;
    for(unsigned i = 0;i < m;++ i)
    {
        std::cin >> a >> b;
        graph[a].push_back(b);
    }

    unsigned res = 9999999, arr[maxN], found = 0, c;
    for(int i = 0;i < n;++ i)
    {
        c = bfs(i);
        if(c != 0)
        {
            if(c == res)
                arr[found++] = i;
            else if(c < res)
            {
                found = 1;
                res = c;
                arr[0] = i;
            }
        }
    }

    std::cout << found << std::endl;
    if(found > 0)
    {
        for(int i = 0;i < found;++ i)
            std::cout << arr[i] << ' ';
        std::cout << std::endl;
    }
    return 0;
}
