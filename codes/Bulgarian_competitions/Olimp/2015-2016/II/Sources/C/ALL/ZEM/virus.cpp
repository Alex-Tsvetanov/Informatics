#include <iostream>
#include <vector>
using namespace std;
vector <long long> v,vn[502];

int main ()
{
long long n,i,k=0,tk=1,br=1,j;
cin >>n;
//n-=1;
while (tk<=n)
    {
     tk=tk<<1;
     k++;
    }
//cout <<k<<" "<<tk<< endl;
cout <<k<< endl;
v.push_back(1);
if (n<=500)
    {
     while (br<=n)
         {
          for(i=0; i<v.size(); i++) vn[v[i]].push_back(br);  //cout <<v[i]<<" ";
          //cout << endl;
          if (br!=n){
          if (v.back()<k) v.push_back(v[v.size()-1]+1);
          else {v.pop_back(); v.back()++;}}
          br++;
         }
     for(i=1; i<=k; i++)
        {
         cout <<vn[i].size()<<" ";
         for (j=0; j<vn[i].size()-1; j++)
         {
          cout <<vn[i][j]<<" ";
         }
         cout <<vn[i][j];
         cout << endl;
        }
    }
return 0;
}
