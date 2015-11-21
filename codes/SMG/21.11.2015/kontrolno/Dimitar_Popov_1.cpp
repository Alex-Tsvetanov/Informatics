#include <iostream>
using namespace std;
int main ()
{
    int chasove[3],minuti[3];
    cin>>chasove[0]>>minuti[0];
    cin>>chasove[1]>>minuti[1];
    if(chasove[0]>chasove[1]){
    chasove[2]=chasove[0]-chasove[1];
    }
    if (chasove[0]<chasove[1]){
    chasove[2]=chasove[1]-chasove[0];
    }
    if(minuti[0]<minuti[1]){
    minuti[2]=minuti[1]-minuti[2];
    }else{
    minuti[2]=60-minuti[0]+minuti[1];
    }
    return 0;
}
