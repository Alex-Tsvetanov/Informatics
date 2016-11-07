#include <iostream>
using namespace std;
int main ()
{
    long long N;
    long long A, B, br=0;
    cin>>N;
    for (A=1;A<N;A++)
    for (B=1;B<N;B++)
    if (N==2*(A+B)+(A-1)*B+(B-1)*A) br++;
    cout<<br/2<<endl;

    return 0;
}
