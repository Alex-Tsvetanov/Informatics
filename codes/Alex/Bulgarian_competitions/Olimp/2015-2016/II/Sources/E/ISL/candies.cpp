#include <bits/stdc++.h>
using namespace std;
int bowls[3];
long long pos, pred_pos, candies;
main()
{
	cin >> bowls[0] >> bowls[1] >> bowls[2];
	for( ; ; )
	{
	    if(bowls[pos]==0)break;
	    bowls[pos]--; candies++;
	    if(pos==0){pos=1; pred_pos=0;}
        else if(pos==1 && pred_pos==0){pos=2; pred_pos=1;}
        else if(pos==1 && pred_pos==2){pos=0; pred_pos=1;}
        else if(pos==2){pos=1; pred_pos=2;}
    }
	cout << candies << endl;
}
