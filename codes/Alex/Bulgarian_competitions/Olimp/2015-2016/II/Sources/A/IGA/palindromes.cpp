#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int i, len, flag;
	char word[10000];
	cin.getline(word,10000);
	len = strlen(word);
	flag = 1;
	for(i = 0; i < len/2; i++)
    {
		if(word[len - i - 1] != word[i])
		{
			flag = 0;
			break;
		}
	}
	int pin;
	int nm;
	int br=0;
	int fl=1;
	if(flag)cout<<"0"<<endl;
    else
    {   for(int a=1;a<len;a++)
        {

            nm=len-a;
        for(i = 0; i < nm/2; i++)
        {
            if(word[len - i - 1] != word[i])
            {
                flag = 0;
                break;
            }
        }
        if(fl==1 && a==1)
            {
                br=br+1;
            }
        }
    }

    if(br!=0)cout<<br<<endl;
    return 0;
}
