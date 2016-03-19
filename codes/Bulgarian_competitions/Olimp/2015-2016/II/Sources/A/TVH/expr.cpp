#include <iostream>
#include <string>
using namespace std;

int Compare(int a, int b)
{
     if(a == 49 && b==49)
     {
          return 0;
     }
     
     return 1;
}

int Solve(char expr[])
{
    int inputLength = strlen(expr) - 1;
    char inParenthesis[1000] = "";
    int inParenthesisIndex = 0;
    
    int clearedExpr[1000];
    for(int q = 0; q < 1000; q++)
    {
      clearedExpr[q] = 0;
    }
    clearedExpr[0] = -1;
    int clearedExprIndex = 0;
    
    for(int i = 1; i < inputLength; i++)
    {
      // Exception if there is ) in the end of expression because it sets i to j+1 (check if i < inputLength)
      if(expr[0] == '(')
      {
        int leftBraces = 1;
        int rightBraces = 0;
        int j = i + 1;
        
        while(leftBraces != rightBraces)
        {
           if(expr[j] == ')' )
           {
             rightBraces++;
             
             if(leftBraces == rightBraces)
             {
               i = j+1;
               cout << expr << " -> " << inParenthesis << endl;
               Solve(inParenthesis);
               
               for(int k = 0; k < 1000; k++)
               {
                 inParenthesis[k] = '\0';
               }
               
               inParenthesisIndex = 0;
             }
           }
           else if(expr[j] == '(' )
           {
             leftBraces++;
           }
           
           if(leftBraces == rightBraces)
           {
             break;
           }
           
           inParenthesis[inParenthesisIndex] = expr[j];
           j++;
           inParenthesisIndex++;
        }
      }
      else
      {
          if(expr[i] != '(')
          {
             if(clearedExpr[0] == -1)
             {
               int compared = Compare(expr[0], expr[i]);
               clearedExpr[0] = compared + 48;
             }
             else
             {
               int compared = Compare(clearedExpr[0], expr[i]);
               clearedExpr[0] = compared + 48;
             }
          }
          else
          {
                int leftBraces = 1;
                int rightBraces = 0;
                int j = i + 1;
                
                while(leftBraces != rightBraces)
                {
                   if(expr[j] == ')' )
                   {
                     rightBraces++;
                     
                     if(leftBraces == rightBraces)
                     {
                       i = j+1;
                       clearedExpr[0] = Compare(clearedExpr[0], Solve(inParenthesis)) + 48;
                       
                       for(int k = 0; k < 1000; k++)
                       {
                         inParenthesis[k] = '\0';
                       }
                       
                       inParenthesisIndex = 0;
                     }
                   }
                   else if(expr[j] == '(' )
                   {
                     leftBraces++;
                   }
                   
                   if(leftBraces == rightBraces)
                   {
                     break;
                   }
                   
                   inParenthesis[inParenthesisIndex] = expr[j];
                   j++;
                   inParenthesisIndex++;
                }
          }
      }
    }
    return clearedExpr[0] - 48;
}

int main()
{
   char input[1000] = "";
   int result[202000];
   int resultIndex = 0;
   
   char valuesOfLetters[200];
   int values[200];
   
   
   cin >> input;
   int inputLength = strlen(input);
   
   while(true)
   {
     cin >> valuesOfLetters;
     
     if(valuesOfLetters[0] == '2')
     {
       break;
     }
     
     char numInput[1000] = "";
     
     int valuesOfLettersLength = strlen(valuesOfLetters);
     
     // Assign char to int values
     for(int l = 0; l < valuesOfLettersLength; l++)
     {
       values[l + 97] = valuesOfLetters[l]; 
     }
     
     for(int m = 0; m <= inputLength; m++)
     {
         if(input[m] != '(' && input[m] != ')')
         {
           numInput[m] = values[(int)input[m]];
         }
         else
         {
           numInput[m] = input[m];
         }
     }
     
     int curResult = Solve(numInput);
     result[resultIndex] = curResult;
     resultIndex++;
     
     // Clear arrays
     for(int k = 0; k < 200; k++)
     {
       valuesOfLetters[k] = '\0';
     }
   }
   
   for(int p = 0; p < resultIndex; p++)
   {
      cout<<result[p];
   }
   
   system("pause");
   return 0;
}

