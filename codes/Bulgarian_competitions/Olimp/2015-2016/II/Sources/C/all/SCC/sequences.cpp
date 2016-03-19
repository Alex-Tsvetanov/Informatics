#include <iostream>
#include <string>
#include <vector>

using namespace std;

int p, n, s;
int maxEl;
int res;

vector<string> stari;

void rec(string curr, int mesteno, int granica, int sbor)
{
    bool OK = true;
    for (int i = 0; i < stari.size() and OK; ++i)
    {
        if (stari[i] == curr)
        {
            OK = false;
        }
    }

    if (OK)
    {
        stari.push_back(curr);
        //cout << curr << '\n';
        ++res;
    }

    if (mesteno == granica)
    {
        return;
    }

    //cout << 'a';

    if (curr[mesteno] != curr[mesteno - 1])
    {
        //cout << "swap " << mesteno << "=" << curr[mesteno] << " and " << mesteno - 1 << "=" << curr[mesteno - 1] << "\n";
        swap(curr[mesteno], curr[mesteno - 1]);
        if (mesteno < curr.size() - 2)
            rec(curr, curr.size() - 1, mesteno, sbor);
        rec(curr, mesteno - 1, granica, sbor);
    }

    //cout << 'b';

    while (curr[curr.size() - 1] - '0' + 1 <= maxEl and sbor + 1 < s)
    {
        //cout << "tuk\n";
        ++curr[curr.size() - 1];
        ++sbor;
        //if (curr[curr.size() - 1] - '0' > currMax)
        //    currMax = curr[curr.size() - 1];
        rec(curr, curr.size() - 1, 0, sbor);
    }
    //else
    //{
    //    cout << curr[curr.size() - 1] - '0' + 1 << " ne moje; maxEl = " << maxEl << '\n';
    //}
    //cout << 'c';
    //delete [](&curr);
}

int main ()
{
    cin >> p >> n >> s;

    if (n == 1)
    {
        cout << s << '\n';
        return 0;
    }

    /*vector<int> numbers;

    for (int i = 0, len = min(s, p) - 1; i < len; ++i)
        numbers.push_back(i);*/

    maxEl = min(s, p) - 1;

    string seq = "";

    for (int i = 0; i < n; ++i)
    {
        seq.push_back('0');
    }

    //while (currMax <= maxEl) //seq[seq.size() - 1] - '0' + 1 <= maxEl)
    //{
    //cout << seq << '\n';
    //++seq[seq.size() - 1];
    rec(seq, seq.size() - 1, 0, 0);
    //}

    cout << res << '\n';

    return 0;
}
