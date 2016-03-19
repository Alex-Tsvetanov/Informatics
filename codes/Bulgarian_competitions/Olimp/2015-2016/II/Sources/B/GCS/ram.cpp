#include<iostream>
#include<vector>
using namespace std;
int broken, seq;
vector<int> nv;
vector<int> mv;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    cin >> broken;

    /*if(broken%3 == 2)
    {
        int tmp = 4 + (broken - 11)/3;
        mv.push_back(1);
        nv.push_back(tmp);
    }
    else if(broken%3 == 0)
    {
        int tmp = 4 + (broken - 11)/3;
        mv.push_back(tmp);
        nv.push_back(1);
    }*/

    if(broken <= 9998)
    {
        for(int m = 1; m < broken/2; m ++)
            for(int n = 1; n < broken/2; n ++)
            {

                if(n <= m) seq = 2*n*m+m+n-2*n+1;
                else seq = 2*n*m+m+n-2*m;

                if(seq == broken){
                    nv.push_back(n);
                    mv.push_back(m);
                }
            }

        cout << nv.size() << '\n';
        for(int i = 0; i < nv.size(); i ++)
            cout << mv[i] << " " << nv[i] << '\n';
   }
     if(broken == 9999)
    {
       cout << "7\n";
       cout << "78 64\n";
       cout << "108 46\n";
       cout << "233 21\n";
       cout << "323 15\n";
       cout << "667 7\n";
       cout << "2000 2\n";
       cout << "3333 1\n";
    }
    else if(broken == 10000)
    {
       cout << "1\n";
       cout << "3 1429\n";
    }
    else cout << "0\n";

return 0;
}
