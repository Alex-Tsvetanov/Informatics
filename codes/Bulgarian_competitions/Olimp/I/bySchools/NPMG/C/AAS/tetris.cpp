#include <iostream>
#include <string>

using namespace std;
int main()
{
    unsigned short int n, m, poredni=0, score=0;
    bool curres=1;
    string curr, validstr;
    cin >> n >> m;
    for(int i=0; i<m; ++i)
        validstr+="*";
    for(int br=0; br<n; ++br)
    {
        cin >> curr;
        if(curr==validstr) ++poredni;
        else {
            curres=1;
            score+=poredni*(poredni+1)/2;
            poredni=0;
        }
    }
    score+=poredni*(poredni+1)/2;
    cout << score << endl;
    return 0;
}
