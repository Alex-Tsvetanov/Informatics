#include<iostream>
#include<cmath>
using namespace std;
int nums[1 << 15];
int main(){
    int MAX = -1, MIN = 1 << 20, n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> nums[i];
        MAX = max(nums[i], MAX);
        MIN = min(nums[i], MIN);
    }

    int firstMIN, firstMAX, lastMIN, lastMAX;
    bool keyMAX = false, keyMIN = false;
    for(int i = 0 ; i < n; i ++){
        if(nums[i] == MAX && !keyMAX){
            firstMAX = i;
            keyMAX = true;
        }
        if(nums[i] == MIN && !keyMIN){
            firstMIN = i;
            keyMIN = true;
        }
    }
    keyMAX = false; keyMIN = false;
    for(int i = n-1 ; i > 0; i --){
        if(nums[i] == MAX && !keyMAX){
            lastMAX = i;
            keyMAX = true;
        }
        if(nums[i] == MIN && !keyMIN){
            lastMIN = i;
            keyMIN = true;
        }
    }


    if(abs(firstMIN - lastMAX) >= abs(lastMIN - firstMAX)){
        if(firstMIN > lastMAX)swap(firstMIN, lastMAX);
        cout << firstMIN + 1 << " " <<lastMAX + 1 << "\n";
    }
    else{
        if(lastMIN > firstMAX)swap(firstMAX, lastMIN);
        cout << lastMIN + 1  << " " <<firstMAX + 1 << "\n";
    }
	return 0;
}
