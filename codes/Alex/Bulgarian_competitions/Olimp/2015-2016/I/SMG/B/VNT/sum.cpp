#include <iostream>
using namespace std;
long long n, mem[3048][16];

long long get( long long num, long long st ) {
//    cout << "getting " << num << " " << st << "\n";
    if ( mem[num][st] != -1 ) { return mem[num][st]; }
    long long ret = 0;
    for ( long long i = st ; (1<<i) <= num ; i ++ ) {
        ret += get(num-(1<<i), i);
    }
    return mem[num][st] = ret;
}

int main () {
    cin >> n;
    for ( long long i = 0 ; i < 3048 ; i ++ ) {
        for ( long long j = 0 ; j < 16 ; j ++ ) {
            mem[i][j] = -1;
        }
    }
    for ( long long i = 0 ; i < 16 ; i ++ ){
        mem[0][i] = 1;
    }
    cout << get( n, 0 ) << "\n";
    return 0;
}
