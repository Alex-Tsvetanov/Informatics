#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace std;

const int ML=10002;

int main (int argc, char** argv)
{
    if (argc < 4) return 0;
    ifstream inS(argv[1]), solS(argv[2]), contS(argv[3]);
    /// input; correct output; contestant's output
    
    char solCS[ML];
    solS.get(solCS,ML,'\n');
    string sol(solCS); // correct output

   


    char contCS[ML];
    contS.get(contCS,ML,'\n');
    string cont(contCS);
/*
    cout << sol << endl;
    cout << cont << endl;
    cout << endl;
*/


/*
    if (cont.size()!=sol.size())
    {
        cout << 0 << endl;
        cerr << "Wrong size of output" << endl;
        return 0;
    }
*/

    if (cont == sol) // correct output is the same as contestant's output
    {
        cout << 1 << endl;
        cerr << "Correct" << endl;
        return 0;
    }

///
    double eps=0.0002;
///

    istringstream svc(cont);
    istringstream svs(sol);


/*    
    cout << svs << endl;
    cout << svc << endl;
    cout << endl;
*/


    double vc1, vc2, vs1, vs2;

    svc >> vc1 >> vc2;
    svs >> vs1 >> vs2;

//    cout << setprecision(10) << vs1 << " " << vs2 << " " << vc1 << " " << vc2 << endl;



    if((fabs(vc1-vs1)<eps)&&(fabs(vc2-vs2)<eps))
    {
        cout << 1 << endl;
        cerr << "Correct" << endl;
        return 0;
    }


    cout << 0 << endl;
    cerr << "Wrong" << endl;

    return 0;
}
