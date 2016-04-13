#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int n;
long long a[1000005];

int m = 0;
vector <long long> output;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long max_number = LONG_LONG_MIN;

    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> a[i];

    for(int i = n-1;i>=0;i--)
        if(a[i]>=max_number) {max_number = a[i];output.push_back(a[i]);m++;}

    if(m!=0)
    {
         cout << output[m-1];
         for(int i = m-2;i>=0;i--)
            cout << " " << output[i];
        cout << '\n';
    }

    return 0;
}
/*
7
50 1 40 2 3 4 30
*/
