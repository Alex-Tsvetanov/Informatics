#include <iostream>
using namespace std;
bool table[102][102];
int brr,brk,n,x,y,d,sh;
int main()
{
    cin>>brr>>brk>>n;
    for ( int i=0 ; i<n ; i++ )
    {
        cin>>x>>y>>d>>sh;
        for(int r=x ; r<r+sh-1 ; r++ )
        {
            for (int k=y ; k<k+d-1 ; k++ )table[r][k]=true;
        }
    }
    for ( int i=0 ; i<brr ; i++ )
    {
        for ( int j=0 ; j<brk ; j++ )cout<<table[i][j];
        cout<<endl;
    }
	return 0;
}
