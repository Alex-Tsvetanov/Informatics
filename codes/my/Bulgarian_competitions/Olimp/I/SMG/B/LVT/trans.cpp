#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long p, m, k;
    int promenlivakatomennqmarabotasusteb = 0, kutiqpulnastaini = 0;
    cin >> p >> m;
    vector<long int> chislatabeibe, gerinikol;
    for(int i = 0; i < 2*m ; i++){
        long int chislo;
        cin >> chislo;
        chislatabeibe.push_back(chislo);
    }
    cin >> k;
    sort(chislatabeibe.begin(),chislatabeibe.end());
    for(int i = 1; i < 2*m ; i++){
        if(chislatabeibe.at(i) == chislatabeibe.at(i-1)){
            kutiqpulnastaini++;
        }else{
            if(kutiqpulnastaini >= k - 1){
                promenlivakatomennqmarabotasusteb+=1;
                int chislo = chislatabeibe.at(i - 1);
                gerinikol.push_back(chislo);
            }
            kutiqpulnastaini = 0;
        }
    }
    cout << promenlivakatomennqmarabotasusteb << endl;
    for (int i = 0; i < gerinikol.size(); i++)cout << gerinikol.at(i) << " ";
}
