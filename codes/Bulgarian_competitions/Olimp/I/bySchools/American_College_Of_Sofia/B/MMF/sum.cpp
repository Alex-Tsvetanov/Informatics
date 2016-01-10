#include<iostream>
#include<cmath>
//#include<vector>
using namespace std;
int number;
//vector<int> a;
int main()
{   //int g = 0;
    cin>>number;
   /* for(int i=0; i<number;i++)
    {
        a.push_back(0);
    }
    for(int i=0; i<number; i++)
    {
        if(a[i]== a[i-1]) {
        g++;
        a[i-1]++; a.pop_back();
    } 
    
    } cout<<g; */
   for(int i=0; i<12; i++)
    {
        if(pow(2,i) == number)
        {
            cout<<number<<'\n';
            return 0;
        }
        
    }
   
   if(number%2 == 0) { cout<<number<<'\n';}
   if(number%2 != 0) {cout<<number-1<<'\n';}
    
    
    return 0;
}