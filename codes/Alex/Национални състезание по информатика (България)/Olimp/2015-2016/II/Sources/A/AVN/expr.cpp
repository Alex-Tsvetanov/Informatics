#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

string s;
int br;
bool matrix[200009][30];
pair <char, bool> alph[30];

bool sortAlph(pair <char, bool> a, pair <char, bool> b)
{
    if (!a.second) return false;
    if (!b.second) return true;
    return a.first < b.first;
}

vector < pair <string, int> > subsrt;

int depth;

bool sortSubStr (pair <string, int> a, pair <string, int> b)
{
    return a.second > b.second;
}

void createStr()
{
    bool x = false;
    string k;
    //if (s[0] != '(' and s[0] != ')') {x=true;}
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            if (k.size()) {subsrt.push_back(make_pair(k,depth));}
            depth++;
            k = "";
        }
        else if (s[i] == ')' and k != "")
        {
            int q = depth;
            if (k.size() == 1)
            {
                q--;
                k = subsrt[subsrt.size() - 1].first + k;
                subsrt.pop_back();
            }
            subsrt.push_back(make_pair(k,q));
            depth--;
            k = "";
        }
        else k += s[i];
    }

    if (k != "") subsrt.push_back(make_pair(k,depth));
    //sort(subsrt.begin(), subsrt.end(), sortSubStr);
}

int indx[30];

bool calc()
{
    //cout<<subsrt[0].first<<endl;
    bool result = alph[indx[int(subsrt[0].first[0] - 'a')]].second;
    for (int j = 1; j < subsrt[0].first.size(); ++j)
            result = !(result & alph[indx[int(subsrt[0].first[j] - 'a')]].second);
    //cout<<result<<endl;
    for (int i = 1; i < subsrt.size(); ++i)
    {
        //cout<<subsrt[i].first<<endl;
        bool curR = alph[indx[int(subsrt[i].first[0] - 'a')]].second;
        for (int j = 1; j < subsrt[i].first.size(); ++j)
            curR = !(curR & alph[indx[int(subsrt[i].first[j] - 'a')]].second);
        //cout<<curR<<endl;
        result = !(result & curR);
    }

    return result;
}

int main()
{
    cin>>s;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] >= 'a' and s[i] <= 'z' and !alph[s[i]-'0'].second)
        {
            alph[int(s[i] - 'a')].second = true;
            alph[int(s[i] - 'a')].first = s[i];
            br++;
        }
    sort(alph, alph + 26, sortAlph);

    int b = 0;
    while (b < 26 and alph[b].second)
    {
        indx[int(alph[b].first - 'a')] = b;
        b++;
    }

    string t;
    createStr();
    cin>>t;
    while (t != "2")
    {
        for(int i = 0; i < br; ++i)
            alph[i].second = int(t[i] - '0');
        cout<<calc();
        cin>>t;
    }
    printf("\n");
}
