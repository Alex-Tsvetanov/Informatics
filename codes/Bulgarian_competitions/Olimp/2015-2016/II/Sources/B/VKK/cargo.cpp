#include <iostream>
#include <vector>
#include <map>

struct Transport
{
    Transport(int S, int E) :
        S(S), E(E)
    {
    }

    int S; // nachalo
    int E; // kraj
};

enum Result
{
    OK = 1, MIXED = 2, IMPOSSIBLE = 0
};

int schedule(Transport& t, std::map<int, Transport*>& sched)
{
    Transport* s = 0;

    for (int j = t.S; j <= t.E; ++j) {
        std::map<int, Transport*>::iterator it = sched.find(j - 1);
        if (it != sched.end()) {
            s = it->second;
            if (s == &t) {
                continue;
            }
            if (s->E == s->S) {
                continue;
            } else {
                int result = schedule(*s, sched);
                if (result == OK || result == MIXED) {
                    sched[j - 1] = &t;
                    return result;
                } else {
                    continue;
                }
            }
        } else {
            sched[j - 1] = &t;
            if (j % 5 > 0) {
                return MIXED;
            } else {
                return OK;
            }
        }
    }

    return IMPOSSIBLE;
}

int main()
{

    int N; // broj dni za planirane
    int M; // broj na zaqavkte
    int P; // broj na pilotite

    std::cin >> N >> M >> P;

    std::vector<Transport> trans;
    std::map<int, Transport*> sched;
    int status = OK;

    for (int i = 0; i < M; ++i)
    {
        int S;
        int E;

        std::cin >> S >> E;

        trans.push_back(Transport(S, E));
    }

    for (int i = 0; i < M; ++i)
    {
        int result = schedule(trans[i], sched);

        if (result == IMPOSSIBLE) {
            status = result;
            break;
        } else {
            status = result;
        }

    }

    switch (status) {
    case OK:
        std::cout << "OK";
        break;
    case MIXED:
        std::cout << "MIXED";
        break;
    case IMPOSSIBLE:
        std::cout << "IMPOSSIBLE";
        break;
    }

    std::cout << std::endl;

    return 0;
}
