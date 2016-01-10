#include <iostream>
#include <string>
#include <vector>

using namespace std;

string trim(string to_trim)
{
    int f1 = to_trim.find("1");

    if(f1 < 0)
    {
        return "0";
    }
    else
    {
        return to_trim.substr(f1,to_trim.length() - f1);
    }
}

string binary_plus(string numb1, string numb2)
{
    string result;
    int minimum = min(numb1.length(), numb2.length());
    string bigger;
    if(minimum == numb1.length())
    {
        bigger = numb2;
    }
    else{
        bigger = numb1;
    }
    int carry = 0;

    for(int i = 0; i < minimum; i++)
    {
        int sum = (numb1[(numb1.length() - i) - 1] - '0') + (numb2[(numb2.length() - i) - 1] - '0') + carry;
        if(sum < 2)
        {
            if(sum == 0)
            {
                result.append("0");
            }
            else
            {
                result.append("1");
            }
            carry = 0;
        }
        else
        {
            if(sum == 2)
            {
                result.append("0");
            }
            else
            {
                result.append("1");
            }
            carry = 1;
        }
    }

    for(int i = 0; i < bigger.length() - minimum; i++)
    {
        int curr = (bigger.length() - 1) - (minimum + i);
        if(carry)
        {
            if(bigger[curr]=='0')
            {
                result.append("1");
                carry = 0;
            }
            else{
                result.append("0");
                carry = 1;
            }
        }
        else
        {
            const char c = bigger[curr];
            result.append(&c,1);
        }
    }

    if(carry)
    {
        result.append("1");
    }

    string reversed;

    for(int i = 0; i < result.length(); i++)
    {
        const char c = result[(result.length() - i) - 1];
        reversed.append(&c,1);
    }

    return trim(reversed);
}

void get_result(string numb1, string numb2, vector<string>& result)
{
    int q1 = numb1.find("?");
    int q2 = numb2.find("?");

    if(q1 >= 0)
    {
        numb1 = numb1.replace(q1,1,"0");
        get_result(numb1,numb2, result);
        numb1 = numb1.replace(q1,1,"1");
        get_result(numb1,numb2, result);
    }
    else if(q2 >= 0)
    {
        numb2.replace(q2,1,"0");
        get_result(numb1,numb2, result);
        numb2.replace(q2,1,"1");
        get_result(numb1,numb2, result);
    }
    else
    {
        result.push_back(binary_plus(numb1,numb2));
    }
}

int main()
{
    string numb1,numb2;
    vector<string> result;
    cin >> numb1 >> numb2;

    get_result(numb1,numb2,result);

    vector<string>::iterator it;
    string res;
    string minimum = "                                                             ";
    int mx = 0;

    for(it = result.begin(); it != result.end(); it++)
    {
        if(it->length() > mx)
        {
            mx = it->length();
        }

        if(it->length() < minimum.length())
        {
            minimum = *it;
        }
    }

    for(int i = 0; i < mx - minimum.length(); i++)
    {
        res.append("?");
    }

    res += result[0];

    for(it = result.begin(); it != result.end(); it++)
    {
        int b = it->length() - 1;

        for(int i = res.length() - 1; i >= 0; i--)
        {
            if(res[i] != '?')
            {
                if(res[i] != (*it)[b])
                {
                    res[i] = '?';
                }
            }
            b--;
            if(b < 0)
            {
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}
