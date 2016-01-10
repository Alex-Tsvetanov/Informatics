#include <iostream>
using namespace std;

int a;

void rec(int n)
{
    if(n == 1)
        {
        a=1;
        return;
    }
    else if(n == 2)
        {
        a=2;
        return;
    }
    else if(n == 3)
        {
        a=2;
        return;
    }
    else if(n == 4)
        {
        a=4;
        return;
    }
    else if(n == 5)
        {
        a=4;
        return;
    }
    else if(n == 6)
        {
        a=6;
        return;
    }
    else if(n == 7)
        {
        a=6;
        return;
    }
    else if(n == 8)
        {
        a=9;
        return;
    }
    else if(n == 9)
        {
        a=9;
        return;
    }
    else if(n == 10 || n == 11)
    {
        a=14;
        return;
    }
    else if(n == 1)
    {
        a+=1;
        return;
    }
    else if(n>1) rec(n-1);
    if(n == 2)
    {
        a+=1;
        return;
    }
    else if(n>2) rec(n-2);
    if(n == 4)
    {
        a+=1;
        return;
    }
    else if(n>4) rec(n-4);
    if(n == 8)
    {
        a+=1;
        return;
    }
    else if(n>8) rec(n-8);
    if(n == 16)
    {
        a+=1;
        return;
    }
    else if(n>16) rec(n-16);
    if(n == 32)
    {
        a+=1;
        return;
    }
    else if(n>32) rec(n-32);
    if(n == 64)
    {
        a+=1;
        return;
    }
    else if(n>64) rec(n-64);
    if(n == 128)
    {
        a+=1;
        return;
    }
    else if(n>128) rec(n-128);
    if(n == 256)
    {
        a+=1;
        return;
    }
    else if(n>256) rec(n-256);
    if(n == 512)
    {
        a+=1;
        return;
    }
    else if(n>512) rec(n-512);
    if(n == 1024)
    {
        a+=1;
        return;
    }
    else if(n>1024) rec(n-1024);
    if(n == 2048)
    {
        a+=1;
        return;
    }
    else if(n>2048) rec(n-2048);
}

int main()
{
    int n;
    cin >> n;
    rec(n);
    cout << a << endl;
}
