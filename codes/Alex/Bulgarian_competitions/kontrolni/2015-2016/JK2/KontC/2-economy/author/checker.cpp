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
        cerr << "Wrong answer" << endl;
        cout << 0 << endl;
    } else {
        sol>>numsol;
        ans>>numans;

        if(numans==0 && numsol==0) {
            cerr << "OK" << endl;
            cout << 1 << endl;
        }
        else if(numans==-1 && numsol==-1) {
            cerr << "OK" << endl;
            cout << 1 << endl;
        } else if ((numsol == -1) && (numans != -1)) {
            cerr << "Wrong answer" << endl;
            cout << 0 << endl;
        } else if ((numsol == 0) && (numans == -1)) {
            cerr << "Wrong answer" << endl;
            cout << 0 << endl;
        }
        else
          {
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
                cerr << "OK" << endl;
                cout << 1 << endl;
            } else {
                cerr << "Wrong answer" << endl;
                cout << 0 << endl;
            }

        }

    }
    inp.close();
    sol.close();
    ans.close();

}

