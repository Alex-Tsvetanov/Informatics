#include<bits/stdc++.h>
using namespace std;
long long n, possibles;
long long r, l;
main()
{
	cin >> n;
    for(r=2; r<n; r++)
        for(l=1; l<n; l++)
            if(r*l+(r-1)*(l+1)==n)possibles++;
    cout << possibles/2 << endl;
}
