#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(int argc, char *argv[]) {

    //cout<<argv[1]<<' '<<argv[2]<<' '<<argv[3]<<endl;
    ifstream inp(argv[1]);// input

    ifstream  sol(argv[2]);//correct output

    ifstream ans(argv[3]);//contestant's output
    long long costsol,costans, numsol,numans;
    int d[1024], da, a, b, c, n, i, sumans=0, sumsol=0;
    sol>>costsol;
    ans>>costans;
    if(costsol<costans) {
        cout << 0 << endl;
        cerr << "Wrong answer" << endl;
    } else {
        sol>>numsol;
        ans>>numans;

        if(numans==0 && numsol==0) {
            cout << 1 << endl;
            cerr << "OK" << endl;
        } else if(numans==-1 && numsol==-1) {
            cout << 1 << endl;
            cerr << "OK" << endl;
        } else {
            inp>>a>>b>>c>>n;
            for(i=0; i<n; i++)
                inp>>d[i];
            for(i=0; i<numans; i++) {
                ans>>da;
                sumans+=d[da-1];
            }
            for(i=0; i<numsol; i++) {
                sol>>da;
                sumsol+=d[da-1];
            }

            if(sumans==sumsol) {
                cout << 1 << endl;
                cerr << "OK" << endl;
            } else {
                cout << 0 << endl;
                cerr << "Wrong answer" << endl;
            }

        }

    }
    inp.close();
    sol.close();
    ans.close();

}

