#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int P;
    cin >> P;
    int roadNum;
    cin >> roadNum;
    int roads[roadNum][2];
    int a;
    int b;
    int k;
    int cities[P];
    
    for (int i = 0; i<roadNum;i++) {
        cin >> a;
        cin >> b;
        roads[i][1] = a;
        roads[i][2] = b;
        cities[a] = 0;
        cities[b] = 0;
    }
    cin>>k;
    int one;
    int two;
    int amount = 0;
    int whichOnes[P];
   
    
    for (int i = 0; i<roadNum; i++) {
        one = roads[i][1];
        two = roads[i][2];
        cities[one] += 1;
        cities[two] += 1;
        if (cities[one]==k) {
            whichOnes[amount] = one;
            amount += 1;
        }
        if (cities[two]==k) {
            whichOnes[amount] = two;
            amount += 1;
        }
    }
    cout << amount <<endl;
    sort(whichOnes,whichOnes + amount);
    for (int i = 0; i < amount;i++) {
        cout<<whichOnes[i] << " ";
    }
    return 0;
}