#include<iostream>
#include<vector>
using namespace std;
int main ()
{
    int N, M, P,a ,b;
    cin >> N >> M >> P;
    int timetable[N][M];
    for (int i=0; i< N;i++)
        {for (int j=0; j< M;j++) timetable[j][i] = 0;}

    for(int i=0; i<M; i++){

        cin >> a >> b;
        for(int j=a-1; j<= b-1; j++){
            timetable [j][i] = 1;
        }
    }
    if (M>N*P/2) cout << "IMPOSSIBLE";
    if (5*N*P/14<M<=N*P/2) cout<< "MIXED";
    if (M<=5*N*P/14)
    return 0;
}
