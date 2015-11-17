#include <iostream>
#include <queue>
using namespace std;
int best[200000];
int main()
{
    int ploshtadki = 0, nskoci = 0;
    cin >> ploshtadki >> nskoci;
    ploshtadki ++;
    int koshnici[200000];
    int skoci[200];
    for(int i = 0; i < nskoci; i ++) cin >> skoci[i];
    for(int i = 0; i < ploshtadki; i ++) cin >> koshnici[i];
    queue<int> curr;
    curr.push(0);
    int curr_sum;
    best[0] = koshnici[0];
    while(!curr.empty())
    {
        curr_sum = best[curr.front()];
        best[curr.front()] = max(best[curr.front()],curr_sum);
        for(int i = 0; i < nskoci; i ++)
        {
            if(curr.front()+skoci[i]<ploshtadki)
            {
                curr.push(curr.front()+skoci[i]);
                curr_sum += koshnici[curr.front()+skoci[i]];
                best[curr.front()+skoci[i]] = max(best[curr.front()+skoci[i]],curr_sum);
                curr_sum -= koshnici[curr.front()+skoci[i]];
            }
        }
        curr.pop();
    }
    int maxsum = 0, maxto = 0;
    for(int i = 0; i < ploshtadki; i ++)
    {
        if(best[i] > maxsum)
        {
            maxsum = best[i];
            maxto = i;
        }
    }
    cout << maxsum << " " << maxto << endl;
}

