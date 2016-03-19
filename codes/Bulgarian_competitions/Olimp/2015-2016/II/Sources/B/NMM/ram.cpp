#include <iostream>
using namespace std;
long int a[1024][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i;
    cin>>i;

    int countOf = 0;
    for(long int m = 1; m <= 999999999; m++)
    {
        if(m>(i/2))
            break;
        for(long int n = 1; n <= 999999999; n++)
        {
            if(m>=n && 2*m*n + m - n + 1 == i)
            {
                a[countOf][0] = m;
                a[countOf][1] = n;
                countOf++;

            }
            else if(m<n && 2*m*n + n - m == i)
            {
                a[countOf][0] = m;
                a[countOf][1] = n;
                countOf++;
            }
            if(2*m*n + m - n + 1 > i && 2*m*n + n - m > i)
                break;
        }

    }
    cout<<countOf<<endl;
    for(int p =0; p<countOf; p++){
        cout<<a[p][0]<<" "<<a[p][1]<<endl;
    }
    return 0;

}

