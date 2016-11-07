#include<iostream>
#include<cstring>
using namespace std;
bool isPalindrome(const string & str, int begin, int end)
{
    for (int i=begin;i<end-(i-begin);++i)
    {
        if (str[i]!=str[end-(i-begin)])
        return false;
    }
    return true;
}
int Split(const string & str)
{
    int length=str.size();
    int * split= new int [length*length];
    for (int i=0;i<length;++i) split[i*length+i]=0;
    for (int i=1;i<length;++i)
    {
        for (int j=length-i;j>0;--j)
        {
        int row=length-i-j;
        int col=row+i;
        if (isPalindrome(str,row,col))
        {
            split[row*length+col]=0;
        }
        else
        {
            int min=0x7FFFFFFF;
            for (int k=row;k<col;++k)
            {
                int temp1=split[row*length+k];
                int temp2=split[(k+1)*length+col];
                if(min>temp1+temp2+1) min=temp1+temp2+1;
            }
            split[row*length+col]=min;
        }
        }
    }
    int minSplit=split[length-1];
    delete[] split;
    return minSplit;
}
int main()
{
    char a[10000];
    cin>>a;
    cout<<Split(a)<<endl;
    return 0;
}