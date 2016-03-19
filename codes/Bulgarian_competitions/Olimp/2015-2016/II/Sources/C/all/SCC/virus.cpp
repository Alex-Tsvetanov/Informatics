#include <iostream>
#include <vector>

using namespace std;

long long n;
long long nujni, tek;
vector<vector<long long> > kutii;

void rec(long long duljina, vector<long long> predishni, long long kude)
{
    //cout << duljina << ' ' << kude << endl;
    if (duljina == 1)
    {
        //cout << "slojih " << tek << endl;
        for (int i = 0; i < predishni.size(); ++i)
        {
            kutii[predishni[i]].push_back(tek);
        }
        ++tek;
        return;
    }
    //cout << "predi " << (kude + 1) << ' ' << (nujni - duljina + 2) << endl;
    for (int i = kude + 1; i < nujni - duljina + 2 and tek < n; ++i)
    {
        //cout << "asd " << i << ' ' << (nujni - duljina + 2) << endl;
        predishni.push_back(i);
        rec(duljina - 1, predishni, i);
        predishni.pop_back();
    }
}

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    /*if (n == 2)
    {
        cout << "2\n"
        cout << "1 1\n";
        cout << "1 2\n";
        return 0;
    }

    if (n == 3)
    {
        cout << "2\n";
        cout << "2 1 2\n";
        cout << "2 1 3\n";
        return 0;
    }

    if (n == 4)
    {
        cout << "3\n";
        cout << "3 1 2 3\n";
        cout << "2 1 4\n";
        cout << "1 2\n";
        return 0;
    }

    if (n == 5)
    {
        cout << "3\n";
        cout << "2 3 5\n";
        cout << "4 1 2 3 5\n";
        cout << "3 2 4 5\n"'
        return 0;
    }

    if (n == 6)
    {
        cout << "3\n";
        cout << "3 3 5 6\n";
        cout << "4 1 2 3 5\n";
        cout << "3 2 4 5\n";
        return 0;
    }*/

    /*long long vzeti = 0, res = 0;

    for (long long i = 1; true; ++i)
    {
        cout << i << ":\n";
        long long tek = 1, kolko = 1;
        for (long long j = 2; j < i; ++j)
        {
            tek *= i - j;
            kolko += j;
        }
        cout << tek << " * ";
        long long sum = 1;
        for (long long j = i - kolko; j > 1; --j)
        {
            sum += j;
        }
        cout << sum << " = " << tek << '\n';
        tek *= sum;

        if (tek >= n)
        {
            res = i;
            break;
        }
    }*/

    long long vzeti = 0;

    for (nujni = 1; vzeti < n; ++nujni)
    {
        vzeti = 0;
        for (long long i = 1; i <= nujni; ++i)
        {
            long long curr1 = 1, curr2 = 1;
            for (long long br = 0; br < i; ++br)
            {
                curr1 *= nujni - br;
            }
            for (long long br = 0; br < i; ++br)
            {
                curr2 *= i - br;
            }
            //cout << "kutii " << nujni << "grupi ot po " << i << " " << curr1 << ' ' << curr2 << endl;
            vzeti += curr1 / curr2;
        }
    }
    --nujni;

    cout << nujni << '\n';

    if (n > 500)
    {
        return 0;
    }


    for (long long brKutii = 0; brKutii < nujni; ++brKutii)
    {
        //cout << 'a';
        vector<long long> v;
        //cout << 'b';
        kutii.push_back(v);
        //cout << 'c';
        kutii[brKutii].push_back(tek);
        //cout << 'd';
        ++tek;
    }

    for (long long br = 2; tek < n; ++br)
    {
        //cout << "slagam po " << br << endl;
        //cout << 'a';
       // cout << br << ' ' << (nujni - br + 1) << ' ' << tek << '\n';
        //int a;
        //cin >> a;
        vector<long long> p;
        for (int i = 0; i < nujni - br + 1 and tek < n; ++i)
        {
            //cout << 'b';
            p.push_back(i);
            rec(br, p, i);
            p.pop_back();
        }
    }

    //cout << 'c';

    /*for (long long i = 0; i < kutii.size() - brKutii + 1 and tek <= n; ++i)
    {
        for (long long j = i; j < i + brKutii; ++j)
        {
            kutii[i].push_back(tek);
        }
        ++tek;
    }*/

    for (long long i = 0, size = kutii.size(); i < size; ++i)
    {
        long long len = kutii[i].size();
        cout << len << ' ';
        for (long long j = 0; j < len; ++j)
        {
            cout << kutii[i][j] + 1;
            if (j + 1 < len)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

//    cout << res << '\n';

    return 0;
}
