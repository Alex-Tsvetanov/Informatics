#include <iostream>
using namespace std;
int p,s,n;
long long br,a[21][31];
void pechat()
{
int i,j;
for (i=1; i<=n; i++){
     cout <<i<<": ";
     for (j=0; j<=s; j++) cout <<a[i][j]<<" ";
     cout << endl;
    }
cout << endl;
}

void rec(int o)
    {
     int i,j;
     for (i=-1; i<=p; i++)
         {
          if (o!=n) if (i==-1) rec(o+1);
                    else{
                         j=0;
                         while(i+j<=s)
                            {
                             //cout<<i<<" "<<j<<" "<< endl;
                             a[o][i+j]+=a[o+1][j];
                             j++;
                            }
                       //  cout <<o<< endl;
                       //  pechat();
                        }
         }
    }

int main()
{
int i,j;
cin>>p>>n>>s;
p--; s--;
for (i=0; i<=p; i++) a[n][i]=1;
rec(1);
for (i=0; i<=s; i++) br+=a[1][i];
cout <<br<< endl;
//pechat();
return 0;
}
