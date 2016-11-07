#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
    int st;
    Node *parent;
    vector<Node*> next;
    Node(){st = -1; parent = NULL;}
    Node(int _st, Node *_parent){st = _st; parent = _parent;}
} *Begin;
string s, test;
bool func(bool a, bool b)
{
    return (a == b) ? !a : true;
}
bool stOf(Node *f)
{
    if (f->st != -1)
        return (test[f->st] == '1');
    bool temp = stOf(f->next[0]);
    for (unsigned int i = 1; i < f->next.size(); i++)
        temp = func(temp, stOf(f->next[i]));
    return temp;
}
void Build(int pos, Node *f)
{
    if (pos == s.size())
        return;
    if (s[pos] == '(')
    {
        f->next.push_back(new Node(-1, f));
        Build(pos+1, f->next[f->next.size()-1]);
        return;
    }
    if (s[pos] == ')')
    {
        Build(pos+1, f->parent);
        return;
    }
    f->next.push_back(new Node(s[pos]-'a', f));
    Build(pos+1, f);
}
int main ()
{
    Begin = new Node();
    cin >> s;
    Build(0, Begin);
    for (;;)
    {
        cin >> test;
        if (test == "2")
            break;
        cout << stOf(Begin);
    }
    cout << endl;
    return 0;
}
