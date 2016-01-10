#include <iostream>

using namespace std;

typedef unsigned long long int u64;

u64 parse_bits(string s)
{
    u64 r = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') {
            r <<= 1;
            r += 1;
        }
        else if((s[i] == '?') || (s[i] == '0')) {
            r <<= 1;
        }
    }

    return r;
}

u64 parse_mask(string s)
{
    u64 r = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '?') {
            r <<= 1;
            r += 1;
        }
        else if((s[i] == '1') || (s[i] == '0')) {
            r <<= 1;
        }
    }

    return r;
}

void print_masked_bits(u64 bits, u64 mask)
{
    bool b = 0;
    bool m = 0;
    bool leading_zeros = 1;

    for(int i = 63; i >= 0; i--)
    {
        b = (bits >> i) & 0x1;
        m = (mask >> i) & 0x1;

        if (m) {
            leading_zeros = 0;
            cout << '?';
        }
        else if(b) {
            leading_zeros = 0;
            cout << '1';
        }
        else {
            if(leading_zeros) {
                continue;
            }
            else {
                cout << '0';
            }
        }
    }

    cout << endl;
}

void find_uncertain_bits(string a, string b)
{
    u64 a_bits = parse_bits(a);
    u64 b_bits = parse_bits(b);

    u64 a_mask = parse_mask(a);
    u64 b_mask = parse_mask(b);

    u64 mask = a_mask | b_mask;

    u64 a_full = a_bits | a_mask;
    u64 b_full = b_bits | b_mask;

    u64 a_plus_b = a_bits + b_bits;

    u64 a_plus_b_full = a_full + b_full;

    mask |= a_plus_b ^ a_plus_b_full;

    print_masked_bits(a_plus_b, mask);
}


int main()
{
    string a;
    cin >> a;

    string b;
    cin >> b;

    find_uncertain_bits(a, b);

    return 0;
}
