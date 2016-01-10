#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr1[60];
    vector<int> arr2[60];
    vector<int> sum[120];
    int c = 0, j = 0;
    std::cin >> arr1;
    std::cin >> arr2;
    if(arr1.size > arr2.size){
        int sise = arr1.size - arr2.size;
        int i = 0;
        for(i = 0; i< sise; i++){
            for(j = 0;j < arr2.size; j++){
                arr2[arr2.size + 1] = arr2[arr2.size];
            }
        }
        for(i = 0; i < arr.size ; i++){
   sum[i] = ((a[i] ^ b[i]) ^ c); // c is carry
   c = ((a[i] & b[i]) | (a[i] & c)) | (b[i] & c);
    }
    }else if (arr1.size < arr2.size){
        int sise = arr2.size - arr1.size;
        int i = 0;
        for(i = 0; i< sise; i++){
            for(j = 0;j < arr1.size; j++){
                arr1[arr1.size + 1] = arr1[arr1.size];
            }
        }
            for(i = 0; i < arr2.size ; i++){
   sum[i] = ((arr1[i] ^ arr2[i]) ^ c); // c is carry
   c = ((arr1[i] & arr2[i]) | (arr1[i] & c)) | (arr2[i] & c);
    }
    }else{}
    for(i = 0; i < arr1.size ; i++){
   sum[i] = ((a[i] ^ b[i]) ^ c); // c is carry
   c = ((a[i] & b[i]) | (a[i] & c)) | (b[i] & c);
    }
}

    return 0;
}
