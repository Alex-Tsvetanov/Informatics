#include <iostream>
using namespace std;
int n, m;
bool a [200] [200];
void numbering (int i, int j){
    if (i >= 0 && i < n && j >= 0 && j < m ){
        if (a [i] [j] == 0){
            a [i] [j] = 1;
            numbering (i - 1, j);
            numbering (i, j - 1);
            numbering (i, j + 1);
            numbering (i + 1, j);
        }
    }
}
int main (){

    ios_base :: sync_with_stdio (false);

    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> a [i] [j];
        }
    }
    int br = 0;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if (a [i] [j] == 0){
                br ++;
                numbering (i, j);
            }
        }
    }
    cout << br << endl;

    return 0;
}
