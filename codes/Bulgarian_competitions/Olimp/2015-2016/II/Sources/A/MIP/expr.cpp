#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input = "(";
    string in;
    cin>>in;
    input+=in;
    input+= ")";
    int inputLength = 0;
    string result[200005];
    int resultIndex = 0;
    int end = 0;
    int inputL = input.length();
    
    for(int i = 1; i < inputL; i++)
    {
        if((int)input[i] - (int)'a' > inputLength)
        {
            inputLength = (int)input[i] - (int)'a';
        }
    }
    inputLength++;
    int inputNums[inputLength];
    while(true)
    {
    end++;
    for(int ll = 0; ll < inputLength; ll++)
    {
        cin>>inputNums[ll];
        if(inputNums[ll] == 2)
        {
            for(int j = 0; j < end; j++)
            {
                cout<<result[j];
            }
            return 0;
        }
    }
    string inputCopy = input;
    //Input2
    for(int i = 0; i < inputL; i++)
    {
           
        if((int)inputCopy[i] >= (int)'a' )//if inputCopy is not brackets
        {
            if(inputNums[(inputCopy[i] - (int)'a')] == 0)
            {
                inputCopy[i] = '0';
            }else
            {
                inputCopy[i] = '1';
            }
            
        }
    }
    int bracketLevel = 0;
    int maxBracketsLevel = 0;
    do
    {
        bracketLevel = 0;
        int bracketsStart;
        int bracketsEnd;
        maxBracketsLevel = 0;
        int maxCount = 0;
        for(int i = 0; i < inputCopy.length(); i++)
        {
            if(inputCopy[i] == '(')
            {
                bracketLevel ++;
                if(bracketLevel > maxBracketsLevel)
                {
                    maxBracketsLevel = bracketLevel;
                    maxCount = 0;
                    bracketsStart = i;
                }
            }
            else if(inputCopy[i] == ')')
            {
                if(bracketLevel == maxBracketsLevel && maxCount == 0)
                {
                  bracketsEnd = i;
                  maxCount++;
                }
                bracketLevel--;
            }
        }
        for(int j = bracketsStart+1; j < bracketsEnd; j++)
        {
            if(bracketsEnd - j > 1)
            {
                if(inputCopy[j] == '0' && inputCopy[j + 1] == '0' ||
                   inputCopy[j] == '0' && inputCopy[j + 1] == '1' ||
                   inputCopy[j] == '1' && inputCopy[j + 1] == '0')
                   {
                        inputCopy[j] = '1';
                        inputCopy[j+1] = '-';
                   }else if(inputCopy[j] == '1' && inputCopy[j + 1] == '1')
                   {
                        inputCopy[j] = '0';
                        inputCopy[j+1] = '-';
                   }
                   j++;
            }
        }
        int countOfDig = 0;
        for(int z = bracketsStart + 1; z < bracketsEnd; z++)
        {
            if(inputCopy[z] == '1' || inputCopy[z] == '0')
            {
                countOfDig++;
            }
        }
        if(countOfDig == 1)
        {
            inputCopy[bracketsStart] = '-';
            inputCopy[bracketsEnd] = '-';
        }
        string copycopy = "";
        for(int z = 0; z < inputCopy.length(); z++)
        {
            if(inputCopy[z] != '-')
            {
                copycopy+=inputCopy[z];
            }
        }
        inputCopy = copycopy;
        
    }while(maxBracketsLevel > 0);
    result[resultIndex] = inputCopy;
    resultIndex++;
    }
    
    return 0;
}