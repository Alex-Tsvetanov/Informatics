#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int P,M,K;
    cin>>P>>M;
    int first[100000];
    int second[100000];
    int used[10001];
    int c=0;
    int answer[10000];
    int br=0;
    int answer_index=0;
    for (int i=0; i<M; i++)
    {
        cin>>first[i];
        cin>>second[i];
    }
    cin>>K;
    for (int i=1; i<=P; i++)
    {
        br=0;
        for (int j=0; j<c; j++)
        {
            used[j]=0;
        }
        c=0;
        for (int j=0; j<M; j++)
        {
            if (first[j]==i)
            {
                if (c==0)
                {
                    used[c]=second[j];
                    br++;
                    c++;
                }
                else
                {
                    for (int k=0; k<c; k++)
                    {
                        if (second[j]==used[k]) break;
                        if (k==c-1 and second[j]!=used[k])
                        {
                            br++;
                            used[c]=second[j];
                            c++;
                        }
                    }

                }
            }
            if (second[j]==i)
            {
                if (c==0)
                {
                    used[c]=first[j];
                    br++;
                    c++;
                }
                else
                {
                    for (int k=0; k<c; k++)
                    {
                        if (first[j]==used[k]) break;
                        if (k==c-1 and first[j]!=used[k])
                        {
                            br++;
                            used[c]=first[j];
                            c++;
                        }
                    }

                }
            }
        }
        if (br>=K)
        {
            answer[answer_index]=i;
            answer_index++;
        }
    }
    cout<<answer_index<<endl;
    sort(answer,answer+answer_index);
    for (int i=0; i<answer_index; i++)
    {
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
