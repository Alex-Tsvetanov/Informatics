#include <iostream>
#include <vector>

using namespace std;

void input(vector<int>& row1, vector<int>& row2)
{
    int c;
    cin >> c;
    for(int i = 0; i < c; i++)
    {
        int numb;
        cin >> numb;
        row1.push_back(numb);
    }
    cin >> c;
    for(int i = 0; i < c; i++)
    {
        int numb;
        cin >> numb;
        row2.push_back(numb);
    }
}

int contains(vector<int>& v, int n)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == n)
        {
            return i;
        }
    }

    return -1;
}

bool has_higher(vector<int>& v, int n)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] > n)
        {
            return true;
        }
    }

    return false;
}



int b_exists(vector<int>& row1,vector<int>& row2)
{
    vector<int>::iterator it1,it2;
    vector<int>occur;

    for(it1 = row1.begin(); it1 != row1.end(); it1++)
    {
        int c = contains(row2, *it1);
        if(c >= 0)
        {
            if(has_higher(occur, c))
            {
                return 0;
            }

            occur.push_back(c);
        }
    }

    return 1;
}

int main()
{
    vector<int> output;

    for(int i=0; i<5; i++)
    {
        vector<int> row1;
        vector<int> row2;

        input(row1,row2);
        output.push_back(b_exists(row1,row2));
    }

    for(int i=0; i<output.size(); i++)
    {
        cout << output[i];
    }

    return 0;
}
