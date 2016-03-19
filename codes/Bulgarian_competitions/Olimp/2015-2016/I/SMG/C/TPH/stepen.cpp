#include <iostream>
#include <math.h>
using namespace std;
int main ( ) {
    int sum;
    cin >> sum;
    int delitel [1000],brdel = 0,broj[1000];
    int k = 0,kletki[1000],minimum,izhod;
    if (sum % 2 == 0){
        delitel[brdel] = 2;
        while (sum % 2 == 0){
            sum /= 2;
            k++;
        }
        broj[brdel] = k;
        brdel++;
    }

    if (sum % 3 == 0){
        delitel[brdel] = 3;
        k = 0;
        while (sum % 3 == 0){
            sum /= 3;
            k++;
        }
        broj[brdel] = k;
        brdel++;
    }
    for (int prime = 5; prime <= sqrt(sum); prime++){
        bool xe = 0;
        for(int delitel = 2; delitel < sqrt(prime) + 1;delitel++){
            if (prime % delitel == 0){
                xe = 1;
                break;
            }
        }
        if (xe == 0){

            if (sum % prime == 0){
                delitel[brdel] = prime;
                k = 0;
                while (sum % prime == 0){
                    sum /= prime;
                    k++;
                }
                broj[brdel] = k;
                brdel++;
            }
        }
    }
    if (brdel == 0){
        cout << "0";
        return 0;
    } else {
        int chetnost = 0;
//        int  t = broj[0];
//        int chetnost = 0;
//        while (t > 1){
//            if (t%2 == 1){
//                cout << "0";
//                return 0;
//            }
//            chetnost++;
//            t /= 2;
//        }
//        kletki[0] = chetnost;
//        minimum = chetnost;

        minimum = broj[0];
        if (brdel > 1){
            for (int i = 1; i < brdel;i++){
    //            t = broj[i];
    //            chetnost = 0;
    //            while (t > 0){
    //                if (t%2 == 1){
    //                    cout << "0";
    //                    return 0;
    //                }
    //                chetnost++;
    //                t /= 2;
    //            }
                //kletki[i] = chetnost;
                chetnost = broj[i];
                if (minimum > chetnost){
                    if ((minimum / chetnost) % 2 == 1){
                        chetnost = 2;
                    }
                    for (int j = 0; minimum != chetnost; j++){
                        delitel[j] *= delitel[j];
                        minimum /= 2;
                    }
                }
            }
            int saveminimum = minimum;
            for (izhod = 0; saveminimum > 1; izhod++){
                saveminimum /= 2;
            }
            cout << izhod << endl;
            long suma = 1;
            for (int i = 0; i < brdel; i++){
                suma *= delitel[i];
            }

            for (int i = 0; i < izhod - 1; i ++){
                suma *= suma;
            }

            for (int i = 0; i < izhod; i++){
                cout << suma << " " << minimum << endl;
                suma = sqrt(suma);
                minimum *=2;
            }
        } else {
            int saveminimum = minimum;
            for (izhod = 0; saveminimum > 1; izhod++){
                saveminimum /= 2;
            }
            cout << izhod << endl;
            long suma = 1;
            for (int i = 0; i < brdel; i++){
                suma *= delitel[i];
            }

            for (int i = 0; i < izhod - 1; i ++){
                suma *= suma;
            }
            for (int i = 0; i < izhod; i++){
                cout << suma << " " << minimum << endl;
                suma = sqrt(suma);
                minimum *=2;
            }
        }
    }
    return 0;
}
