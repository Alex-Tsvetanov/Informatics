#include <bits/stdc++.h>
using namespace std;

string input;
string inputQuery;

vector<pair<int, int> > brackets;
vector<int> processedLetters;

int globalCurrBrackets = 0;



bool bracket_cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second>b.second;
    return a.first<b.first;
}

void processLetters()
{
    vector<bool> used(32);
    map<char, int> assoc;
    int charCount = 0;

    for (int i=0;i<input.size();i++)
        if (input[i]!='(' && input[i]!=')')
        {
            charCount++;
            used[int(input[i]-'a')] = true;
        }
    int pos = 0;
    for (int i=0;i<used.size();i++)
        if (used[i] == true)
        {
            assoc[char('a' + i)] = pos;
            pos++;
        }
    //cout<<assoc['a']<<' '<<assoc['b']<<' '<<assoc['c']<<endl;

    for (int i=0;i<input.size();i++)
        if (input[i]!='(' && input[i]!=')')
            processedLetters.push_back(assoc[input[i]]);

    //cout<<"Outputting letters: "<<endl;
    //for (int i=0;i<processedLetters.size();i++)
    //    cout<<processedLetters[i]<<' ';
    //cout<<endl<<"Letter output finished"<<endl;;
}

void processBrackets()
{
    stack<int> openBracket;
    int charCount = 0;
    for (int i=0;i<input.size();i++)
    {
        if (input[i] == '(')
        {
            openBracket.push(charCount);
        }
        else if (input[i] == ')')
        {
            brackets.push_back(std::make_pair(openBracket.top(), charCount));
            openBracket.pop();
        }
        else
        {
            charCount++;
        }
    }

    brackets.push_back(std::make_pair(0, processedLetters.size()));
    sort(brackets.begin(), brackets.end(), bracket_cmp);

    //cout<<"Outputting brackets:"<<endl;

    //for (int i=0;i<brackets.size();i++)
    //{
    //    cout<<brackets[i].first<<' '<<brackets[i].second<<endl;
    //}
}

void processInput()
{

    processLetters();
    processBrackets();

}

bool calculate(int currBrackets)
{
    bool ans = inputQuery[processedLetters[brackets[currBrackets].first]] == '1';

    //cout<<"hue "<<currBrackets<<' '<<ans<<endl;
    globalCurrBrackets++;
    if (globalCurrBrackets<brackets.size())
    {
        if (brackets[globalCurrBrackets].first == brackets[currBrackets].first)
        {
            ans = calculate(globalCurrBrackets);
        }
    }
    else
    {
        globalCurrBrackets--;
    }

    //cout<<"Currently in brackets number "<<currBrackets<<endl;
    //cout<<"The first element in the brackets is number"<<brackets[currBrackets].first<<" and has a value of "<<inputQuery[processedLetters[brackets[currBrackets].first]]<<endl;

    for (int i=brackets[currBrackets].first+1;i<brackets[currBrackets].second;i++)
    {
        //cout<<i<<endl;
        if (i == brackets[globalCurrBrackets].first && globalCurrBrackets != currBrackets)
        {
            //cout<<"Going to brackets number "<<globalCurrBrackets<<" from "<<currBrackets<<endl;
            i = brackets[globalCurrBrackets].second-1;
            bool hue = calculate(globalCurrBrackets);
            ans = !(ans && hue);
        }
        else
        {
            //cout<<"Adding the element "<<inputQuery[processedLetters[i]]<<" to curr answer "<<ans<<endl;
            ans = !(ans && inputQuery[processedLetters[i]] == '1');
        }

        //cout<<i<<' '<<ans<<endl;
    }

    //cout<<"Returning from brackets number "<<currBrackets<<endl;


    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //ifstream in("zad2test.in");
    //ofstream out("zad1.out");

    cin>>input;

    processInput();


    while (true)
    {
        cin>>inputQuery;
        if (inputQuery == "2")
        {
            break;
        }
        globalCurrBrackets = 0;
        bool ans = calculate(0);
        cout<<ans;
    }
    cout<<endl;


    return 0;
}
