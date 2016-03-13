#include <iostream>

using namespace std;

int main()
{
    int number;
    cin>>number;
    if(number%2 != 0)
        number = number - 1;
        int a = number/4;
        int b = number/a;
        int c = a/4;
        if(c%2 != 0)
            c = a - (a/4);
        int d = b + (b/4);
        int e = (c+d)*2 - 2;
        while (c*d != number)
            c = c + 1;
      cout<<e<<endl;
    return 0;
}
