#include <iostream>
#include <string>

using namespace std;

bool palindromeCheck(string a)
{
    bool result = true;
    for (int i=0; i < a.length()/2; i++)
        if (a[i] != a[a.length()-1-i]) result = false;
    return result;
}

int main()
{
    bool answerFound = false;

    int answer = 0;

	string input, splittedInput;
	cin >> input;
	splittedInput = input;

    if (palindromeCheck(input))
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        for (int j=0; j < input.length() - 1; j++)
        {
            splittedInput = input;
            for (int h=0; h <= j; h++)
            {
                for (int i=0; i < splittedInput.length(); i++)
                {
                    if (palindromeCheck(splittedInput.substr(0, splittedInput.length() - i - 1)))
                    {
                        splittedInput = splittedInput.substr(splittedInput.length() - i - 1);
                        answer = j + 1;
                        break;
                    }
                }
            }
            if (splittedInput != "" && splittedInput != " " )
            {
                if (palindromeCheck(splittedInput))
                    break;
            }
        }
        cout << answer << endl;
    }

	return 0;
}
