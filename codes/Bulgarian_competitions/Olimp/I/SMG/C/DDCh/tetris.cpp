#include <iostream>

using namespace std;

uint32_t n,m, to4ki;
char pole[128][128];
uint32_t kolkoImaVred[128];

void destroyFullLines()
{
    for(uint32_t i = 0; i<n; i++)
    {
        for(uint32_t j = 0; j<m; j++)
        {
            if(pole[i][j]=='*')
            {
                kolkoImaVred[i]++;
            }
        }
    }
    uint32_t cnt = 0;
    for(uint32_t i = 0; i<n; i++)
    {
        if(kolkoImaVred[i]==m)
            cnt++;
        else
        {
            to4ki+=cnt*(cnt+1)/2;
            cnt=0;
        }
    }
    to4ki+=cnt*(cnt+1)/2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(uint32_t i = 0; i<n; i++)
    {
        for(uint32_t j=0; j<m; j++)
        {
            cin>>pole[i][j];
        }
    }
    destroyFullLines();
    cout<<to4ki<<'\n';
    return 0;
}
