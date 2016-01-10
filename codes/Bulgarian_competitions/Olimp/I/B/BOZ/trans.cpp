#include<iostream>
#include<queue>
using namespace std;

int main ()
{
    long int p;
    int m, k;
    cin >> p >> m;

    int n [p];

    for(int i = 0; i < p; i++) n[i] = 0;

    int c;
    for(int i = 0; i < m; i++)
    {
        cin >> c;
        n[c-1]++;

        cin >> c;
        n[c-1]++;
    }
    cin >> k;

    queue <int> ans;
    int br = 0;

    for(int i = 0; i < p; i++)
    {
        if(n[i] >= k){
            br++;
            ans.push(i+1);
        }
    }

    cout<< br << '\n';
        while(!ans.empty()){
            cout<<ans.front() << " ";
            ans.pop();
    }
    cout << endl;



    return 0;
}
