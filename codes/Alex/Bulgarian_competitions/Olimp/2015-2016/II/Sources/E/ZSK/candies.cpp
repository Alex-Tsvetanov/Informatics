#include <iostream>
using namespace std;
int main()
{
    long long brA=0,brB=0,brC=0;
    long long A,B,C;
    cin>>A>>B>>C;
    if(A>0 && B>0 && C>0)
    {
        A--;
        B--;
        C--;
        brA++;
        brB++;
        brC++;
    }
    while(1)
    {
            if(A>0 && B>0 && C>0)
            {
                B--;
                A--;
                brA++;
                brB++;
                if(A>0 && B>0 && C>0)
                {
                    B--;
                    C--;
                    brB++;
                    brC++;
                }
            }
            else
        {
            cout<<brA+brB+brC<<endl;
            return 0;
        }
        }

    /*while(1)
    {
        if(A>0 && B>0 && C>0)
        {
            A--;
        if(A>0)
        {
            brA++;
            B--;
            if(B>0)
            {
                brB++;
                C--;
                if(C>0)
                {
                    brC++;
                    B--;
                    if(B>0)
                    {
                        brB++;
                        A--;
                        if(A>0)
                        {
                            brA++;
                            B--;
                            if(B>0)
                            {
                                brB++;
                                brC++;
                                C--;
                            }
                        }
                    }
                }
            }
        }
        }

        else
        {
            cout<<brA+brB+brC<<endl;
            return 0;
        }
    }*/
    return 0;
}
