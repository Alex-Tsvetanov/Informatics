#include <iostream>
using namespace std;
int main(){
    long int n, minimalni4u6ki, maximalni4u6ki;
    long int drugar4e2, drugar4e , drugar4e3, drugar4e4;
    long int daftpunkalbum, daftpunkalbum1;
    cin>>n;long int ogromniqtmasivs4y6ki[n];cin >> ogromniqtmasivs4y6ki[0];
    minimalni4u6ki = ogromniqtmasivs4y6ki[0];maximalni4u6ki = ogromniqtmasivs4y6ki[0];
    for (int i = 1; i<n ; i++){
        cin >> ogromniqtmasivs4y6ki[i];
        if(minimalni4u6ki > ogromniqtmasivs4y6ki[i])minimalni4u6ki = ogromniqtmasivs4y6ki[i];
        if(maximalni4u6ki < ogromniqtmasivs4y6ki[i])maximalni4u6ki = ogromniqtmasivs4y6ki[i];
    }
    for (int i = 0; i<n ; i++){
        if(ogromniqtmasivs4y6ki[i] == minimalni4u6ki || ogromniqtmasivs4y6ki[i] == maximalni4u6ki){
            drugar4e = i;
            daftpunkalbum = ogromniqtmasivs4y6ki[i];break;
        }
    }
    if(daftpunkalbum == minimalni4u6ki)daftpunkalbum1 = maximalni4u6ki;
    if(daftpunkalbum == maximalni4u6ki)daftpunkalbum1 = minimalni4u6ki;
    for (int i = 0; i<n ; i++){
        if(ogromniqtmasivs4y6ki[i]==daftpunkalbum1){
            drugar4e3 = i;break;
        }
    }
    for (int i = n; i>= drugar4e ; i--){
        if(ogromniqtmasivs4y6ki[i] == daftpunkalbum1){
            drugar4e2 = i;break;
        }
    }
    for (int i = n; i>= drugar4e ; i--){
        if(ogromniqtmasivs4y6ki[i] == daftpunkalbum){
            drugar4e4 = i;break;
        }
    }
    (drugar4e4 - drugar4e3)>(drugar4e2-drugar4e)? cout << drugar4e3+1 << " " << drugar4e4+1 << endl : cout << drugar4e+1 << " " << drugar4e2+1 << endl;
}
