#include <iostream>
#include <vector>

using namespace std;

int kol[101], size;
pair<int, int> deliteli[200];

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        for (int j = 0; j < m; ++j)
        {
            int input;
            cin >> input;
            a += input;
            kol[j] += input;
        }

        if (i == 0)
        {
            for (int br = 1; br * br <= a; ++br)
            {
                if (a % br == 0)
                {
                    deliteli[size].first = br;
                    deliteli[size].second = 1;
                    //for (int k = size; k > 0 and deliteli[k] < deliteli[k - 1]; --k)
                    //swap(deliteli[k], deliteli[k - 1]);
                    ++size;
                    if (a / br != br)
                    {
                        deliteli[size].first = a / br;
                        deliteli[size].second = 1;
                        //for (int k = size; k > 0 and deliteli[k] < deliteli[k - 1]; --k)
                        //swap(deliteli[k], deliteli[k - 1]);
                        ++size;
                    }
                }
            }
        }
        else
        {
            for (int br = 1; br * br <= a; ++br)
            {
                if (a % br == 0)
                {
                    for (int i = 0; i < size; ++i)
                    {
                        if (deliteli[i].first == br)
                        {
                            ++deliteli[i].second;
                            break;
                        }
                    }
                    if (a / br != br)
                    {
                        for (int i = 0; i < size; ++i)
                        {
                            if (deliteli[i].first == a / br)
                            {
                                ++deliteli[i].second;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int br = 1; br * br <= kol[i]; ++br)
        {
            if (kol[i] % br == 0)
            {
                for (int i = 0; i < size; ++i)
                {
                    if (deliteli[i].first == br)
                    {
                        ++deliteli[i].second;
                        break;
                    }
                }
                if (kol[i] / br != br)
                {
                    for (int i = 0; i < size; ++i)
                    {
                        if (deliteli[i].first == kol[i] / br)
                        {
                            ++deliteli[i].second;
                            break;
                        }
                    }
                }
            }
        }
        kol[i] = 0;
    }


    int res1 = 1;
    for (int i = 0; i < size; ++i)
    {
        if (deliteli[i].second == n + m and deliteli[i].first > res1)
        {
            res1 = deliteli[i].first;
        }
    }

    //cout << res1 << ' ';


    size = 0;

    //vtorata matrica
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        for (int j = 0; j < m; ++j)
        {
            int input;
            cin >> input;
            a += input;
            kol[j] += input;
        }

        if (i == 0)
        {
            for (int br = 1; br * br <= a; ++br)
            {
                if (a % br == 0)
                {
                    deliteli[size].first = br;
                    deliteli[size].second = 1;
                    //for (int k = size; k > 0 and deliteli[k] < deliteli[k - 1]; --k)
                    //swap(deliteli[k], deliteli[k - 1]);
                    ++size;
                    if (a / br != br)
                    {
                        deliteli[size].first = a / br;
                        deliteli[size].second = 1;
                        //for (int k = size; k > 0 and deliteli[k] < deliteli[k - 1]; --k)
                        //swap(deliteli[k], deliteli[k - 1]);
                        ++size;
                    }
                }
            }
        }
        else
        {
            for (int br = 1; br * br <= a; ++br)
            {
                if (a % br == 0)
                {
                    for (int i = 0; i < size; ++i)
                    {
                        if (deliteli[i].first == br)
                        {
                            ++deliteli[i].second;
                            break;
                        }
                    }
                    if (a / br != br)
                    {
                        for (int i = 0; i < size; ++i)
                        {
                            if (deliteli[i].first == a / br)
                            {
                                ++deliteli[i].second;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int br = 1; br * br <= kol[i]; ++br)
        {
            if (kol[i] % br == 0)
            {
                for (int i = 0; i < size; ++i)
                {
                    if (deliteli[i].first == br)
                    {
                        ++deliteli[i].second;
                        break;
                    }
                }
                if (kol[i] / br != br)
                {
                    for (int i = 0; i < size; ++i)
                    {
                        if (deliteli[i].first == kol[i] / br)
                        {
                            ++deliteli[i].second;
                            break;
                        }
                    }
                }
            }
        }
    }

    int res2 = 1;
    for (int i = 0; i < size; ++i)
    {
        if (deliteli[i].second == n + m and deliteli[i].first > res2)
        {
            res2 = deliteli[i].first;
        }
    }

    cout << res1 << ' ' << res2 << '\n';

    if (res1 % res2 == 0 or res2 % res1 == 0)
    {
        cout << "Y\n";
    }
    else
    {
        cout << "N\n";
    }

    return 0;
}
