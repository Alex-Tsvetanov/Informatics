#include <iostream>

using namespace std;
int main()
{
    int P, M, K, s, p, br=0;
    cin >> P >> M;
    P++;
    int gradowe[P], gradPrqk[P];
    for(int i=0; i<P; i++){
        gradowe[i]=0;
    }
    for(int i=0; i<M; i++){
        cin >> s;
        gradowe[s]++;
        cin >> p;
        gradowe[p]++;
    }
    cin >> K;
    for(int i=0; i<P; i++){
        if(K<=gradowe[i]){
            gradPrqk[br]=i;
            br++;
        }
    }
    cout << br << endl;
    for(int i=0; i<br; i++){
        cout << gradPrqk[i] << " ";
    }
    return 0;
}
