#include<iostream>
using namespace std;
int main()
{
    long long metri,santimetri,pogolem;
    cin>>metri>>santimetri>>pogolem;
    metri=metri/2;
    if(metri%2!=0){
        santimetri=santimetri+50;
        metri--;
    }
     metri=metri/2;
    if(metri%2!=0){
        santimetri=santimetri+50;
        metri--;
    }
    cout<<metri<<" "<<santimetri<<endl;
    cout<<metri<<" "<<santimetri-pogolem<<endl;
    if(santimetri<0){
        santimetri=santimetri+100;
        metri--;
    return 0;
}
