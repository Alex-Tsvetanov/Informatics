#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

int stepN (int st)
{
    int n = 0, pl = 1;
    for(int i = 0; i <= st; i++){
        n += pl;
        pl *= 2;
    }
    return 1+n-st*2;
}

int main ()
{
    int n, br = 0;
    double p = 12;
    cin >> n;

    queue <double> po;

    do{
        p--;
        while(n - pow(2.0, p) >= 0){
                n -= pow(2.0, p);
                po.push(p);
        }
    }while(n>=1);

    while(!po.empty())
    {
        br += stepN(po.front());
        po.pop();
    }

    cout << br << endl;

    return 0;
}
