#include <iostream>
#define MAX 1002
using namespace std;
int main ()
{
    int M , N , m , n ;
    short int a[MAX][MAX] ;
    int sum = 0, last_sum = 0 ;
    cin >> M >> N >> m >> n ;
    for ( int i = 0 ; i < M ; i ++ )
    {
        for ( int j = 0 ; j < N ; j ++ )
        {
            cin>>a[i][j];
        }
    }
    for ( int i = 0 ; i < M - m + 1 ; i ++ )
    {
        for ( int j = 0 ; j < N - n + 1 ; j ++ )
        {
            if ( sum > last_sum ) last_sum = sum ;
            sum = 0 ;
            for ( int k = i ; k < m + i ; k ++ )
            {
                for ( int l = j ; l < n + j ; l ++ )
                {
                    sum += a[k][l] ;
                }
            }
        }
    }
    if ( sum > last_sum ) last_sum = sum ;
    cout << last_sum << endl ;
    return 0 ;
}
