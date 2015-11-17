#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int gosho[100];
    gosho[0]=1;
    int i;
    int br;
    double maxlice;
    int koordinati[100];
    double strani[100];
    double lica[100];
    double poluperimetri[100];
    poluperimetri[0]=0;
    lica[0]=1;
    for(br=0; gosho[br]!=0;)
    {
        br++;
        cin>>gosho[br];
        for(int i=0; i<gosho[br]*2; i++)
        {
            cin>>koordinati[i];
        }
        for(i=0; i<=(gosho[br]*2)-4; i++)
        {
            strani[i]=sqrt((koordinati[i]-koordinati[i+2])*(koordinati[i]-koordinati[i+2])+(koordinati[i+1]+koordinati[i+3])*(koordinati[i+1]+koordinati[i+3]));
        }
        strani[i+1]=sqrt((koordinati[0]-koordinati[i+1])*(koordinati[0]-koordinati[i+1])+(koordinati[1]+koordinati[i+2])*(koordinati[1]+koordinati[i+2]));
        for(int j=0; j<i; j++)
        {
        }
        for(int j=0; j<i-1; j++)
        {
            poluperimetri[br]=poluperimetri[br]+strani[j];
        }
        poluperimetri[br]=poluperimetri[br]/2;
        for(int j=0; j<i-1; j++)
        {
            lica[br]=lica[br]*(poluperimetri[br]-strani[j]);
        }
        if(gosho[br]>3){
        lica[br]=sqrt(lica[br]);
        }
    }
    maxlice=1;
    for(int a=0;a<br;a++){
        if(lica[a+1]>lica[a]){
            maxlice=a+1;
        }
    }
    cout<<maxlice<<endl;
    return 0;
}
