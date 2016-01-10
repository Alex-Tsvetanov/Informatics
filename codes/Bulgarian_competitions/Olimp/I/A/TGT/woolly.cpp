#include<iostream>
#include<vector>
using namespace std;
vector<string> firstVar,secondVar,sums;
vector<int> sumLens;
int maxLen,start,l;

void findFirstVars(string str,string var,int len,int index=0)
{
    if(index==len)
    {
        firstVar.push_back(var);
        return;
    }
    if(str[index] == '?')
    {
        var.push_back('0');
        findFirstVars(str,var,len,index+1);
        var[index] = '1';
        findFirstVars(str,var,len,index+1);
    }
    else
    {
        var.push_back(str[index]);
        findFirstVars(str,var,len,index+1);
    }
}

void findSecondVars(string str,string var,int len,int index=0)
{
    if(index==len)
    {
        secondVar.push_back(var);
        return;
    }
    if(str[index] == '?')
    {
        var.push_back('0');
        findSecondVars(str,var,len,index+1);
        var[index] = '1';
        findSecondVars(str,var,len,index+1);
    }
    else
    {
        var.push_back(str[index]);
        findSecondVars(str,var,len,index+1);
    }
}

string reverseString(string str,int len=0)
{
    string ans;
    if(len==0)
    {
        len = str.size();
    }
    for(int i = len-1;i>=0;i--)
    {
        ans.push_back(str[i]);
    }
    return ans;
}

string findSum(string first,string second,int f,int s)
{
    string sum;
    bool flag;
    int i = 0,over = 0;
    while(i<f && i<s)
    {
        flag = false;
        int bit = (first[i]-'0')+(second[i]-'0')+over;
        if(bit>1)
        {
            flag = true;
            bit = 0 + bit%2;
        }
        sum.push_back((char)((bit)+'0'));
        if(flag) over = 1;
        else over = 0;
        i++;
    }
    while(i<f)
    {
        flag = false;
        int bit = (first[i]-'0')+over;
        if(bit>1)
        {
            flag = true;
            bit = 0;
        }
        sum.push_back((char)((bit)+'0'));
        if(flag) over = 1;
        else over = 0;
        i++;
    }
    while(i<s)
    {
        flag = false;
        int bit = (second[i]-'0')+over;
        if(bit>1)
        {
            flag = true;
            bit = 0;
        }
        sum.push_back((char)((bit)+'0'));
        if(flag) over = 1;
        else over = 0;
        i++;
    }
    if(over>0)
    {
        sum.push_back((char)(over+'0'));
        i++;
    }
    l=i;
    return sum;
}

void findAllSums()
{
    int f = firstVar.size();
    int s = secondVar.size();
    for(int i = 0;i<f;i++)
    {
        int siz = firstVar[i].size();
        for(int j = 0;j<s;j++)
        {
            string temp = findSum(firstVar[i],secondVar[j],siz,secondVar[j].size());
            int len = l;
            if(len>maxLen)
            {
                maxLen = len;
                start = i*f+j;
            }
            sums.push_back(temp);
            sumLens.push_back(len);
        }
    }
}

string findUnclearSum()
{
    string sum;
    int len = sums.size();
    for(int i = 0;i<maxLen;i++)
    {
        bool flag = true;
        for(int j = 0;j<len;j++)
        {
            if(start!=j)
            {
                if((sums[start][i] !=sums[j][i]) || (sumLens[j]<=i))
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            sum.push_back(sums[0][i]);
        }
        else
        {
            sum.push_back('?');
        }
    }
    return sum;
}
int main()
{
    string first,second,unclearSum,var;
    int firstLen,secondLen;
    cin>>first>>second;
    firstLen = first.size();
    secondLen = second.size();
    first = reverseString(first,firstLen);
    second = reverseString(second,secondLen);
    findFirstVars(first,var,firstLen);
    var.clear();
    findSecondVars(second,var,secondLen);
    findAllSums();
    unclearSum = reverseString(findUnclearSum());
    cout<<unclearSum<<endl;
    return 0;
}

/*
101??001
1?01101
*/
