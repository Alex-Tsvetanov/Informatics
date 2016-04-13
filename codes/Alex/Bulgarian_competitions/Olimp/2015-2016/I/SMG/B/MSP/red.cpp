#include <iostream>
using namespace std;
int main ()
{
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++)
    {
        cin >>a[i];
    }
    int max_razlika = a[0]-a[1];
    if (max_razlika<0)
    {
        max_razlika = max_razlika * (-1);
    }
    int nachalo_max_red = 0, krai_max_red = 1;
    for (int i=0; i<N-1; i++)
    {
        for (int j=i; j<N; j++)
        {
            int razlika = a[i]-a[j];
            if (razlika<0)
            {
                razlika = razlika*(-1);
            }
            if (razlika > max_razlika)
            {
                max_razlika = razlika;
            }
        }
    }
    for (int i=0; i<N; i++)
    {
        for (int j=N-1; j>i; j--)
        {
            int razlika = a[i]-a[j];
            if (razlika < 0)
            {
                razlika = razlika *(-1);
            }
            if (razlika == max_razlika)
            {
                nachalo_max_red = i;
                krai_max_red = j;
                i=N-1;
            }
        }
    }
    cout << nachalo_max_red+1 << " " << krai_max_red+1;




}
