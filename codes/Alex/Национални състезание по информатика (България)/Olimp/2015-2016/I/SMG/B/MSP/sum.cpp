#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    int N; cin >> N;
    while (N>3000)
    {
        cout << "Please insert a number no more than 3000." << endl;
        cin >> N;
    }
    while (N<0)
    {
        cout << "Please insert a positive number." << endl;
        cin >> N;
    }
    int broi_nachini = 0;
    int a[N];
    for (int i=0; i<N; i++)
    {
        a[N]=0;
    }
    int i=0, k=0;
    int suma = 0;
    for (int i=0; i<N; i++)
    {
        suma =0;
        while (suma<N)
        {
            a[i]=pow(2, k);
            suma += a[i];
            i++;
        }
        k++;
        if (suma==N)
        {
            broi_nachini ++;
            k++;
        }
    }
    cout << broi_nachini;
}
