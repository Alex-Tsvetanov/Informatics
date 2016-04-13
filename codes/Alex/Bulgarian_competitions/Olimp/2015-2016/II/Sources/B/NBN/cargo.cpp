#include<iostream>
#include<vector>
using namespace std;
struct poruchka
{
    int nSrok,kSrok;
};
int main()
{
    bool dni[1000001];
    int temp1,temp2;
    poruchka tempPor;
    vector<poruchka> poruchki,intensity;
    int PP,brPoruchki,piloti;
    cin>>PP>>brPoruchki>>piloti;
    piloti/=2;
    for(int i = 0;i < brPoruchki;i++)
    {
        cin>>temp1>>temp2;
        tempPor.nSrok=temp1;
        tempPor.kSrok=temp2;
        poruchki.push_back(tempPor);
    }
    for(int i = 0;i < brPoruchki;i++)
    {
        for(int j = poruchki[i].nSrok;j <= poruchki[i].kSrok;j++)
            dni[j] = 1;
    }
    int vuzmDni=0;
    for(int i = 0;i <= PP;i++)
        vuzmDni+=dni[i];
    if(vuzmDni * piloti < brPoruchki)
        cout<<"IMPOSSIBLE"<<endl;
    else
        cout<<"MIXED"<<endl;
    return 0;
}
