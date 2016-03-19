#include<iostream>
using namespace std;
int main(){
    int n, m, q, i, j, k, cx[10000], cy[10000], r[10000], mx[10], my[10], s[10000], tekrezultat = 0, result = 0;
    cin >> n >> m >> q;
    for(i=0; i<n; i++){
        cin >> cx[i] >> cy[i] >> r[i];
    }
    for(i=0; i<m; i++){
        cin >> mx[i] >> my[i];
    }
    for(i=0; i<q; i++){
        cin >> s[i];
    }
    for(i=0; i<q; i++){
        int s1 = s[i];
        if(i>0 && tekrezultat % 2 == 0){
            s1 *= 2;
        }
        tekrezultat = 0;
        for(j=0; j<m; j++){
            for(k=0; k<n; k++){
                if(s1 > r[k] && (mx[j]-cx[k])*(mx[j]-cx[k]) + (my[j]-cy[k])*(my[j]-cy[k]) < (s1-r[k])*(s1-r[k])){
                    tekrezultat++;
                }
            }
        }
        result += tekrezultat;
    }
    cout << result << '\n';
    return 0;
}
