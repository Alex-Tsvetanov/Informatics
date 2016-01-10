#include<iostream>
#include<set>
#include<vector>
using namespace std;


bool find_lowest_number(vector<int> a1, vector<int>::iterator iter)
{
    int min_value;
    min_value = *a1.begin();
    for(auto iter2 = a1.begin(); iter2 <= iter -1; iter2++)
    {
        if(*iter2 >= *(iter2 + 1))
            min_value = *(iter2+1);
    }
    if(min_value == 0)
        return false;
    else
        return true;
}

bool Is_mergable(vector <int> a1, vector <int> a2)
{
    for(auto iter = a1.begin(); iter < a1.end(); ++iter)
    {
        for(auto iter2 = a2.begin(); iter2 < a2.end(); ++iter2)
        {
            if(*iter == *iter2)
            {
                int f1 = find_lowest_number(a1,iter);
                int f2 = find_lowest_number(a2,iter2);
                if((f1 == 0 && f2 == 0) || (f1 == 1 && f2 == 1))
                {
                    *iter = 0;
                    *iter2 = 0;
                }
                else
                {
                    return false;
                    break;
                }
            }
        }
    }
    return true;
}
 bool solution()
 {
    vector<int> a1;
    vector<int> a2;
    bool possible_merge1;
    int n1, n2;
    cin>>n1;
    for(int i = 0; i < n1; ++i)
    {
        int number;
        cin>>number;
        a1.push_back(number);
    }
    cin>>n2;
    for(int i = 0; i < n2; ++i)
    {
        int number;
        cin>>number;
        a2.push_back(number);
    }
    possible_merge1 = Is_mergable(a1,a2);
    return possible_merge1;
 }

int main()
{
    bool one = solution();
     bool two = solution();
      bool three = solution();
       bool four = solution();
        bool five = solution();
        cout<<one<<two<<three<<four<<five;
    return 0;
}
