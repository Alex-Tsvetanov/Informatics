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

int values[26];


int char_to_index(char a)
{
    if (a >= 'a' && a <= 'z')
    {
        return (int)a - (int)'a';
    }
    else if (a >= 'A' && a <= 'Z')
    {
        return (int)a - (int)'A';
    }
    else
    {
        DEBUG_PRINTF("tried to get index of unrecognised char: %c\n", a);
        return 0;
    }
}


int& get_value(char a)
{
    int i = char_to_index(a);
    return values[i];
}


bool nand(bool a, bool b)
{
    return (!(a && b));
}


string& find_and_replace(string &str, char from, char to)
{
    size_t len = str.length();
    size_t pos = 0;

    DEBUG_PRINTF("replacing in \"%s\" '%c' -> '%c'\n", str.c_str(), from, to);

    while(pos < len)
    {
        size_t i = str.find(from, pos);
        if(i > len) break;
        else
        {
            str[i] = to;
            pos = i;
        }
    }
    return str;
}


// This function actually works, don't touch it!
string& preprocess(string &expr)
{
    size_t i;
    int found_chars[26] = {0};
    int relocate_chars[26];

    for(i = 0; i < 26; i++) {
        relocate_chars[i] = -1;
    }

    // Find which characters actually appear in the expr
    for(i = 0; i < expr.size(); i++)
    {
        char c = expr[i];
        if(isalpha(c)) {
            found_chars[char_to_index(c)] = 1;
        }
    }

    // Condense the characters by relocating them
    for(i = 0; i < 26; i++)
    {
        if(found_chars[i] == 0) {
            for(int j = i+1; j < 26; j++)
            {
                if(found_chars[j] == 1) {
                    relocate_chars[j] = i;
                    found_chars[i] = 1;
                    found_chars[j] = 0;
                    break;
                }
            }
        }
    }

    // Perform the relocation
    for(i = 0; i < 26; i++)
    {
        if(relocate_chars[i] == -1) {
                continue;
        } else {
            find_and_replace(expr, ('a'+(char)i), ('a'+(char)relocate_chars[i]));
        }
    }

    return expr;
}


int calculate_expr(string expr)
{
    size_t i;
    int value = -1;
    for(i = 0; i < expr.size(); i++)
    {
        char c = expr[i];
        if(isalpha(c))
        {
            if(value == -1) {
                value = get_value(c);
            } else {
                value = nand(value, get_value(c));
            }
        }
        else if(c == '(')
        {
            size_t j;
            int depth = 1;
            for(j = i + 1; j < expr.size(); j++)
            {
                if(expr[j] == '(') {
                    depth++;
                } else if(expr[j] == ')') {
                    depth--;
                }

                if(depth < 1) {
                    break;
                }
            }
            value = nand(value, calculate_expr(expr.substr(i+1, j-i-1)));
            i = j;
        }
    }
    DEBUG_PRINTF("calculating \"%s\" = %i\n", expr.c_str(), value);
    return value;
}

int main()
{
    int i;
    string expr;
    string vals;
    string result;

    for(i = 0; i < 30; i++)
    {
        values[i] = -1;
    }
    cin >> expr;
    expr = preprocess(expr);

    while(true)
    {
        cin >> vals;
        if(vals == "2") {
            cout << result << endl;
            return 0;
        }
        else
        {
            for(i = 0; i < vals.size(); i++) {
                if(vals[i] == '1') {
                    values[i] = 1;
                } else if(vals[i] == '0') {
                    values[i] = 0;
                }
            }
        }
        int calc = calculate_expr(expr);
        if(calc == 1) {
            result.push_back('1');
        } else if(calc == 0) {
            result.push_back('0');
        } else {
            DEBUG_PRINTF("Something happened:\n\tSomething happened\n", 0);
            return 1;
        }
    }

    return 0;
}

