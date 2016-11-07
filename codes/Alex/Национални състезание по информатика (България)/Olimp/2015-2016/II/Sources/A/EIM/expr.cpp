#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
using namespace std;

int seq[1111];
bool vals[31];
char s[1111];
int n;
char q[51];

int theend[1111];
int stk[1111];
int sL=0;

int genind;

int Solve(int ending)
{
    int ctr=0;
    int tend;

    //cout<<"Entering at "<<genind<<" with ending expected at "<<ending<<endl;

    while(genind<=ending)
    {
        //cout<<"Examining "<<genind<<endl;
        if (seq[genind]==-1)
        {
            genind++;
            //cout<<"Natural all1 return"<<endl;
            return ctr%2;
        }
        else if (seq[genind]==0)
        {
            tend=theend[genind];
            genind++;

            if (Solve(tend)==1)
            ctr++;
            else
            {
                if (genind!=ending)
                ctr++;

                //cout<<"Special bracketafter return"<<endl;
                genind=ending+1;
                return ctr%2;
            }
        }
        else
        {
            if (vals[ seq[genind] ]==1)
            ctr++;
            else
            {
                if (genind!=ending-1)
                ctr++;

                //cout<<"Midway return"<<endl;

                genind=ending+1;
                return ctr%2;
            }

            genind++;
        }
    }

    return (ctr)%2;
}

int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("ans2.txt","w",stdout);

    int i;
    int L=0;

    scanf("%s",s+1);
    n=strlen(s+1);

    reverse(s+1,s+1+n);

    for (i=1;i<=n;i++)
    {
        if (s[i]=='(')
            s[i]=')';
        else if (s[i]==')')
            s[i]='(';
    }

    for (i=1;i<=n;i++)
    {
        if (s[i]=='(')
        {
            seq[i]=0;
        }
        else if (s[i]==')')
        {
            seq[i]=-1;
        }
        else
        {
            seq[i]=s[i]-'a'+1;
        }
    }

    sL=0;
    for (i=1;i<=n;i++)
    {
        if (seq[i]==0)
        {
            sL++;
            stk[sL]=i;
        }
        else if (seq[i]==-1)
        {
            theend[ stk[sL] ]=i;
            sL--;
        }
    }

    n++;
    seq[n]=-1;

    int total=0;
    int rem;

    while(1)
    {
        scanf("%s",q+1);
        L=strlen(q+1);

        if (q[1]=='2')
        break;

        for (i=1;i<=L;i++)
        {
            vals[i]=q[i]-'0';
        }

        genind=1;

        //rem=clock();
        printf("%d",(int)(Solve(n)));
        //total+=clock()-rem;
    }
    printf("\n");

    //fprintf(stderr,"Total time in ticks : %d\n",total);

    return 0;
}
