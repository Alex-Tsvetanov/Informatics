#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int f=0;
    int purwo;
    int wtoro;
    int N;
    int maxx=0;
    cin >> N;
    int a[N];
    int maxxx=0;
    int b[40000];
    int s=0;
    int minn = 2000001;
    int edno, dwe;
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(abs(a[i]-a[j]) > maxx){
                maxx = abs(a[i]-a[j]);
                purwo = a[i];
                wtoro = a[j];
            }
        }
    }
    for(int i=0; i<N; i++){
        if((a[i]==purwo) || (a[i]==wtoro)){
            for(int j=i; j<N; j++){
                if(((a[j] == purwo) || (a[j] == wtoro)) && abs(a[i] - a[j])==maxx){
                    b[s]=i+1;
                    b[s+1]=j+1;
                    if((j-i) > maxxx) maxxx = j-i;
                    s = s + 2;
                }
            }
        }
    }
    int sbor[s];
    for(int i=0; i<s; i = i + 2){
        if((b[i+1] - b[i])== maxxx){
            sbor[f]=b[i+1] + b[i];
            if(sbor[f] < minn){
                minn = sbor[i];
                edno = b[i];
                dwe = b[i+1];
            }
            if(f==0) {purwo = b[i]; wtoro=b[i+1];}
            f++;
        }
    }
    if(f==1){
        cout << purwo << " " << wtoro;
        return 0;
    }
    cout << edno << " " << dwe;
    return 0;
}
