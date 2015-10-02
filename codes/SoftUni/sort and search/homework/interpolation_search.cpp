#include <iostream>
using namespace std;
 
void print_ar (int* ar, int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << ar[i] << " ";
  }
    cout << endl;
}
 
int interpolation_search (int* ar, int value, int size)
{
  int low = 0;
  int high = size - 1;
  int mid;
 
  while (ar[low] <= value && ar[high] >= value)
  {
    mid = low + ((value - ar[low]) * (high - low)) / (ar[high] - ar[low]);
    if (ar[mid] < value)
    {
      low = mid + 1;
    }
    else if (ar[mid] > value)
    {
      low = mid - 1;
    }
    else
    {
      return mid;
    }
  }
 
  if (ar[low] == value)
  {
    return low;
  }
  else
  {
    return -1;
  }
}
 
//Driver Function
int main()
{
  int* ar;
  int n;
  cout << "Input size: ";
  cin >> n;
  cout << "Input array: ";
  ar = new int [n];
  for (int i = 0 ; i < n ; i ++)
      cin >> ar [i];
  int value, pos;
 
  cout << "Your Array : ";
  print_ar (ar, n);
 
  cout << "Enter the value to search : ";
  cin >> value;
  pos = interpolation_search (ar, value, n);
  if (pos != -1)
  {
    cout << "Value Found! at position : " << pos + 1 << endl;
  }
  else
  {
    cout << "Sorry, the value you searched for is not present." << endl;
  }
 
  return 0;
}
