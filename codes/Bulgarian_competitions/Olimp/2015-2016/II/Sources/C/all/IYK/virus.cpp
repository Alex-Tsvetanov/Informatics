#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, current_power = 1, power, next_combination;
vector<long long> combinations[505], boxes[505];

void generate_combinations(long long cnt, long long from)
{
    long long current_combination[15] = {0}, max_number[15] = {from - cnt};
    for(long long i = 1; i < cnt; i++)
    {
        current_combination[i] = current_combination[i - 1] + 1;
        max_number[i] = max_number[i - 1] + 1;
    }

    for(long long i = 0; i < cnt; i++)
    {
        combinations[next_combination].push_back(current_combination[i]);
    }
    next_combination++;

    while(1)
    {
        if(current_combination[0] == max_number[0]) break;

        for(long long i = cnt - 1; i >= 0; i--)
        {
            if(current_combination[i] != max_number[i])
            {
                current_combination[i]++;
                for(long long j = i + 1; j < cnt; j++)
                {
                    current_combination[j] = current_combination[j - 1] + 1;
                }
                break;
            }
        }

        for(long long i = 0; i < cnt; i++)
        {
            combinations[next_combination].push_back(current_combination[i]);
        }
        next_combination++;

        if(next_combination > n) break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    while(current_power < n)
    {
        current_power *= 2;
        power++;
    }

    cout<<power<<endl;
    if(n > 500) return 0;

    for(long long i = 1; i <= power; i++)
    {
        generate_combinations(i, power);
        if(next_combination > n) break;
    }

    for(long long i = 0; i < n; i++)
    {
        for(long long j = 0; j < combinations[i].size(); j++)
        {
            boxes[combinations[i][j]].push_back(i + 1);
        }
    }

    for(long long i = 0; i < power; i++)
    {
        cout<<boxes[i].size();
        for(long long j = 0; j < boxes[i].size(); j++)
        {
            cout<<" "<<boxes[i][j];
        }
        cout<<endl;
    }

    return 0;
}
