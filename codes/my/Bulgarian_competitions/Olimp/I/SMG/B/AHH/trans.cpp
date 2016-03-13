#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int P, M, K, temp = 0, br = 0;// p nomerata M dvojkite chisla; K - vyzel
    cin >> P >> M;
    vector<int> numbers, answer;

    for(int i = 0; i < 2*M ; i++)
    {
        int chislo;

        cin >> chislo;
        numbers.push_back(chislo);
    }

    cin >> K;

    sort(numbers.begin(),numbers.end());

    for(int i = 1; i < 2*M ; i++)
    {
        if(numbers.at(i) == numbers.at(i-1))
        {
            br++;
        }else
        {
            if(br >= K - 1)
            {
                temp+=1;
                int chislo = numbers.at(i - 1);
                answer.push_back(chislo);
            }
            br = 0;
        }
    }

    cout << temp << endl;
    for (int i = 0; i < answer.size(); i++)
        cout << answer.at(i) << " ";

}
