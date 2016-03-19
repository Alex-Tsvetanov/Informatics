#include <iostream>
using namespace std;
int main()
{
    int n, br=0, testn, check=0;
    cin>>n;
    testn=n;
    while (true){
        if (check==0) {testn=testn-(br+1); check=1;}
        if (check==1) testn=testn-(br+1+br+2);
        if (testn==0) {br++; testn=n; check=0;}
        if (testn<0) break;
    }
    //if (br%2==0) cout<<br/2<<endl;
    cout<<br<<endl;

    return 0;
}
