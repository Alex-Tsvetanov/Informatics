#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int result[5];
    for(int times = 0; times < 5; times++)
    {
        int res = 1;
        int len;
        cin >> len;
        int numbers[len];
        for(int i = 0; i < len; i++)
        {
            cin >> numbers[i];
            for(int j = 0; j < i; j++)
            {
                if(numbers[i] == numbers[j])
                {
                    res = 0;
                }
            }
        }
        int len_1;
        cin >> len_1;
        int numbers_1[len_1];
        for(int i = 0; i < len_1; i++)
        {
            cin >> numbers_1[i];
            for(int j = 0; j < i; j++)
            {
                if(numbers_1[i] == numbers_1[j])
                {
                    res = 0;
                }
            }
        }
        if(res == 1){
            if(len <=len_1){
                res = 0;
            }
        }


        result[times] = res;

    }
    for(int i = 0; i < 5; i++){
        cout << result[i];
    }
    return 0;
}
