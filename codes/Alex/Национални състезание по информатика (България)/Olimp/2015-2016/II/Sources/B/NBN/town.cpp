#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    clock_t endTime = clock()+300;
    do
    {
    }while(clock()<endTime);
    cout<<"X";
    return 0;
}
