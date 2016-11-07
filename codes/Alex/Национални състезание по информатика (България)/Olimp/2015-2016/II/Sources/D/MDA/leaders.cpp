#include<iostream>
#define endl '\n'
using namespace std;
int nums[1000001],ls[1000001];

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,l,i,j=0;

    cin >> n;

    for( i = 0 ; i < n ; i ++ ) cin >> nums[i];

    l = nums[n-1];
    ls[j] = l;
    j = 1;

    for( i = n-1 ; i > -1 ; i -- )
    {
        if( l >= nums[i] ) continue;
        else if( l < nums[i] )
        {
            l = nums[i];
            ls[j] = l;
            j ++;
        }
    }
    cout << ls[j-1];

    for( i = j-2 ; i > -1 ; i -- ) cout << " " << ls[i];

    cout << endl;
}
