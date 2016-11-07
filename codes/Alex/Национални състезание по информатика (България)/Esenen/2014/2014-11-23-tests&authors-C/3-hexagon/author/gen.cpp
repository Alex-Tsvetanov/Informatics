#include<iostream>
using namespace std;

int k=5;
// max 199

int wr()
{
 
 //return 63;
 
 int r=rand();
 r = 1+ r%20;
 return r; 
  
    
}

int main()
{
    
  cout << k << endl;
  srand(17);
  int d=3;
  for(int i=1;i<=k;i++)
  {
    cout << wr();
    for(int j=2;j<=d;j++) cout << " " << wr();
    d++; 
    cout << endl;
  }
  
  d=d-2;
  for(int i=1;i<=k-1;i++)
  {
    cout << wr();
    for(int j=2;j<=d;j++) cout << " " << wr();
    d--; 
    cout << endl;
  }
  
  
    
}
