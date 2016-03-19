#include<bits/stdc++.h>
using namespace std;
bool kvadrat[101][101]={0},flag;
int L,h,n,x,y,a,b,i,j,s,maxs,begin,end,r,c;
int main ()
{
    cin >> L >> h;
    cin >> n;
    for ( i=0; i<n; i++ )
    {
        cin >> x >> y >> a >> b;
        for ( j=y; j<y+b; j++ )
        {
            for ( int q=x; q<x+a; q++ )
            {
                kvadrat[j][q]=1;
            }
        }
    }
    maxs=-1;
    for ( i=0; i<h; i++ )
    {
        begin=0;
        for ( j=0; j<L; j++ )
        {
            if ( kvadrat[i][j]==0 && j<L-1 ) { s++; if ( s>maxs ) maxs=s; }
            else if ( kvadrat[i][j]==1 )
            {
                end=j-1;
                flag=true;
                for ( r=i+1; r<h; r++ )
                {
                    for ( c=begin; c<=end; c++ )
                    {
                        if ( kvadrat[r][c]==0 ) s++;
                        else { flag=false; s=s-(c-1); break; }
                    }
                    if ( flag==false ) break;
                }
                if ( s>maxs ) maxs=s;
                s=0;
                while(kvadrat[i][j]==1) j++;
                begin=j;
                j--;
            }
            else if ( kvadrat[i][j]==0 && j==L-1 )
            {
                s++;
                end=j;
                for ( r=i+1; r<h; r++ )
                {
                    for ( c=begin; c<=end; c++ )
                    {
                        if ( kvadrat[r][c]==0 ) s++;
                        else { flag=false; s=s-(c-1); break; }
                    }
                    if ( flag==false ) break;
                }
                if ( s>maxs ) maxs=s;
                s=0;
            }
        }
    }
    cout << maxs << endl;
    return 0;
}
/**
12 8
2
2 0 3 3
6 1 5 4
*/
