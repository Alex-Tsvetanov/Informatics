#include <iostream>
using namespace std;
int main()
{
    int a, b, c, kupa=2, check=1, bon=0;
    cin>>a>>b>>c;
    a++;
    b++;
    c++;
    while (true){
        if (check==2) check=0;
        if (check==3) check=1;
        if (kupa==1 and check==0) {kupa=2; check=2;}
        if (kupa==2 and check==0) {kupa=3; check=3;}
        //------------------------------------------
        if (kupa==3 and check==1) {kupa=2; check=3;}
        if (kupa==2 and check==1) {kupa=1; check=0;}
        //------------------------------------------
        if (kupa==1) {a--; bon++;}
        if (kupa==2) {b--; bon++;}
        if (kupa==3) {c--; bon++;}
        cout<<kupa<<"  "<<a-1<<" "<<b-1<<" "<<c-1<<endl;
        if (a==0 or b==0 or c==0) break;
    }
    cout<<bon-1<<endl;

    return 0;
}
