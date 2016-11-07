#include <iostream>
using namespace std;
int main()
{
    int n, br=0, i, j;
    cin >> n;
    for (i=1; ; i++)
    {
        for (j=1; ; j++)
        {
            if ((((i+j)*2)+((j-1)*i))==n) {break;}
            else if ((((i+j)*2)+((j-1)*i))>n) {break;}
        }
        if (i<=j && (((i+j)*2)+((j-1)*i))==n) br++;
        else break;
    }
    cout << br << endl;
}
