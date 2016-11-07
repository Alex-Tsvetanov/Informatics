#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <stdint.h>

using namespace std;

//#define DEBUG 1
#undef DEBUG

#ifdef DEBUG
#   define DEBUG_PRINTF(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#   define DEBUG_PRINTF(fmt, ...) do {} while(0)
#endif

int main()
{
    string s;
    int palindromes = 0;
    bool inside_run;
    bool do_inner;
    int run_end;
    int k;
    int j;

    cin >> s;

    DEBUG_PRINTF("input: %s\n", s.c_str());

    for(int i = 0; i < s.size(); i++)
    {
        inside_run = false;
        do_inner = true;
        run_end = 0;
        k = s.size()-1;
        j = i;
        DEBUG_PRINTF("palindromes: %i\n", palindromes);
        while(do_inner)
        {
            DEBUG_PRINTF("i:%i, j:%i, k:%i\n", i, j, k);

            if(j >= s.size())
            {
                palindromes++;
                do_inner = false;
                continue;
            }

            if(inside_run)
            {
                if(s[j] != s[k])
                {
                    DEBUG_PRINTF("exited run\n", 0);
                    inside_run = false;
                    j = i;
                }
                else if((k - j == 0) || (k - j == 1))
                {
                    i = run_end;
                    palindromes++;
                    do_inner = false;
                    continue;
                }
                else
                {
                    j++;
                    k--;
                }
            }
            else
            {
                if(k - j <= 0) {
                    palindromes++;
                    do_inner = false;
                    continue;
                }

                if(s[j] == s[k])
                {
                    DEBUG_PRINTF("entered run\n", 0);
                    inside_run = true;
                    run_end = k;
                }
                else
                {
                    k--;
                }
            }
        }
    }

    cout << palindromes << endl;

    return 0;
}
