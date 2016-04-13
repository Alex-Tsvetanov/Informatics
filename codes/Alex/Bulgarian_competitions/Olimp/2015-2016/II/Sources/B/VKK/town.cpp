#include <iostream>
#include <bits/stdc++.h>

int findRoute(std::map<int, std::map<int, bool> >& nodes, int start, int a, int b, bool& finished)
{
    typedef std::map<int, bool>::iterator mapit;
    std::map<int, bool>& links = nodes[start];

    mapit finish = links.find(b);
    if (finish != links.end()) {
        finished = true;
        return (finish->second == false ? 1 : 0);
    }

    int min_err = INT_MAX;

    for (mapit it = links.begin(), end = links.end(); it != end; ++it) {
        int dest = it->first;
        int min = 0;

        if (dest != a) {
            std::cout << start << " to " << dest;
            int derr = findRoute(nodes, dest, a, b, finished) + (it->second == false ? 1 : 0);
            if (derr < min_err) {
                min_err = derr;
                min = dest;
            }
            std::cout << ": " << derr << '\n';
        }
    }

    return min_err;
}

int main()
{
    int n;
    int a;
    int b;

    int p;
    int q;

    int errs = 0;

    std::cin >> n >> a >> b;

    std::map<int, std::map<int, bool> > nodes;

    do {
        if(!std::cin.eof()) {
            break;
        }
        std::cin >> p >> q;
        nodes[p][q] = true;
        nodes[q][p] = false; // breaking the law
    } while (!std::cin.eof());

    bool finished = false;
    errs = findRoute(nodes, a, a, b, finished);

    if (!finished) {
        std::cout << 'X';
    } else {
        std::cout << errs;
    }

    std::cout << std::endl;

    return 0;
}
