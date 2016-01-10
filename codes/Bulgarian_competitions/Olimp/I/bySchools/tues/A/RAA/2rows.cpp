#include <iostream>

using namespace std;
bool is_mergeable(int a[], int b[], int a_length, int b_length);
bool is_mergeable2(int a[], int b[], int a_length, int b_length, int checked[]);

int main()
{
    int result[5];
    int a_length;
    int b_length;
    for (int j = 0; j < 5; j++)
    {
        cin >> a_length;
        int a[a_length];

        for(int i = 0; i < a_length; i++)
        {
            cin >> a[i];
        }

        cin >> b_length;
        int b[b_length];

        for (int i = 0; i < b_length; i++)
        {
            cin >> b[i];
        }

        if (a_length > b_length)
        {
            int check_length[a_length];
            for (int j = 0; j < a_length; j ++)
            {
                check_length[j] = 0;
            }

            //cout << is_mergeable(a, b, a_length, b_length) << endl;
            cout << is_mergeable2(a, b, a_length, b_length, check_length) << endl;
        }
        else
        {
            int check_length[b_length];
            for (int j = 0; j < b_length; j ++)
            {
                check_length[j] = 0;
            }
            //cout << is_mergeable(b, a, b_length, a_length) << endl;
            cout << is_mergeable2(b, a, b_length, a_length, check_length) << endl;
        }


    }
}

/*bool is_mergeable(int a[], int b[], int a_length, int b_length)
{
    bool straight = true;
    if(a_length > b_length)
    {
        int first_number_index_b = 0;
        int first_ex_index_a = 0;
        bool first_found = false;
        for (int i = 0; i < b_length; i++)
        {
            for(int j = 0; j < a_length; j++)
            {
                if(b[i] == a [j])
                {
                    first_ex_index_a = j;
                    first_number_index_b = i;
                    first_found = true;
                    break;
                }
            }

            if(first_found)
            {
                break;
            }
        }

        int last_number_index_a = 0;
        int last_number_index_b = 0;
        bool last_found = false;
        for (int i = b_length - 1; i >= 0; i--)
        {
            for(int j = a_length; j > 0; j--)
            {
                if(b[i] == a [j])
                {
                    last_number_index_a = j;
                    last_number_index_b = i;
                    last_found = true;
                    break;
                }
            }

            if(last_found)
            {
                break;
            }
        }

        if(first_number_index_b - last_number_index_b == 0)
        {
            return true;
        }

        bool number_found = false;
        int b_current_index = 1;
        int last_number_index = 0;
        int a_cur_index = first_ex_index_a;


        return true;
    }
    else
    {

    }
}*/

bool is_mergeable2(int a[], int b[], int a_length, int b_length, int checked[])
{
    bool sequential = true;
    //a_length > b_length
    int a_cur_index = 0;
    bool last_matched_index = -130;

    int i = 0;
    while(i < b_length)
    {
        if(b[i] == a[a_cur_index] && checked[a_cur_index] == 0)
        {
            if(last_matched_index < a_cur_index)
            {
                return false;
            }
            else
            {
                last_matched_index = a_cur_index;
                checked[a_cur_index] = 1;
                i++;
            }
        }
        else
        {
            if ((a_cur_index == (last_matched_index -1)) &&
                 (last_matched_index != -1))
            {
                a_cur_index = last_matched_index;
                i++;
            }
            else if(a_cur_index >= a_length - 1)
            {
                i++;
            }
        }

        a_cur_index++;
        if (a_cur_index >= a_length)
        {
            a_cur_index = 0;
        }
    }

    return true;
}
