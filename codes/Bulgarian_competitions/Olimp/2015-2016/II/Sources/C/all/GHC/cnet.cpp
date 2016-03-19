#include <iostream>

using namespace std;

main()
{
    int N, M, C, max = 0;
    cin >> N >> M;
    C = M;
    while(C > 0)
    {
        cin >> M;
        if(M > max)max = M;
        C--;
    }
    cout << max <<endl;
}
