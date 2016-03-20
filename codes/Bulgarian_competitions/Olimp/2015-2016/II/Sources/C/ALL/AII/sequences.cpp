# include<iostream>
using namespace std;

int a[32];
int used[32];
long long ans=0;
int p,n,s;

void show()
{
   // for(int i=0; i<n; i++) cout<<a[i]<<" ";
  //  cout<<endl;
}

void perm(int u, int br, int sum)
{
    if(sum>=s) return;
    if(br==n) {ans++;return;}
    for(int i=0; i<p; i++)
    {
        a[br]=i;
        perm(i,br+1,sum+i);
    }
}

int main()
{

    cin>>p>>n>>s;
    perm(0,0,0);
    cout<<ans<<endl;
}
