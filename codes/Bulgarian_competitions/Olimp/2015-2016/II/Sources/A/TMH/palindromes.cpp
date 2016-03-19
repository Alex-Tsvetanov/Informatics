#include <stdio.h> ///Todor Milenov Hristov

char string[10002];
int size;

int arr[10002];

int answer[10002];

int Check(int begin, int end)
{
    int flag=1;

    while(begin!=end)
    {
        if(begin>end) break;
        if(string[begin]!=string[end])
        {
            flag=0;
            break;
        }
        begin++;
        end--;
    }
    if(flag) return 1;
    return 0;
}

int main()
{
    int a,b;

    scanf("%s",&string);
    for(a=0;a<10002;a++)
    {
        if(string[a]==0)
        {
            size=a;
            break;
        }
    }

    int flag;
    for(a=0;a<size;a++)
    {
        flag=a;
        for(b=a+1;b<size;b++)
        {
            if(Check(a,b)) flag=b;
        }
        arr[a]=flag+1;
    }

    answer[0]=1;
    if(arr[0]!=1) answer[arr[0]]=answer[0]+1;
    for(a=1;a<=size;a++)
    {
        if(answer[a]==0) answer[a]=answer[a-1]+1;
        else
        {
            if(answer[a]<answer[a-1]+1);
            else answer[a]=answer[a-1]+1;
        }
        if(arr[a]!=a+1) answer[arr[a]]=answer[a]+1;
    }

    if(answer[size]==1) printf("0\n");
    else printf("%d\n", answer[size]-2);

    /*for(a=0;a<=size;a++)
    {
        printf("%d ",answer[a]);
    }*/

    return 0;
    /// Posleslow: Nqmam si predstawa zashto tazi zadacha raboti za primerniq whod
}
