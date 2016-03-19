#include <iostream>

using namespace std;

int Otg=0;
string a;

void Nai(int Na4,int Kr)
{
    int MaxNa4,MaxKr,MaxLen=0;
    bool IsPalindrom2 = true,Left=false,Right=false,Br,Br2=false;

    for (int i = Na4;i<Kr;i++)
    {
        if (Br2==true)break;
        for (int b= Kr;b>i;b--)
        {
            if (Br2==true)break;
            if (b-i==1 && a[b]==a[i])
            {
                if (MaxLen<2)
                    {
                        MaxLen=2;
                        MaxNa4=i;
                        MaxKr=b;
                    }
            }
            else
            {
                int f=b;
                if ((b-i)%2==0)
                {
                    for (int c = i;c<((b-i)/2)+i;c++,f--)
                    {
                        if (a[c] != a[f])
                        {
                            IsPalindrom2=false;
                            break;
                        }
                        else
                        {
                            IsPalindrom2=true;
                        }
                    }
                }
                else
                {
                    for (int c = i;c<=((b-i)/2)+i;c++,f--)
                    {
                        if (a[c] != a[f])
                        {
                            IsPalindrom2=false;
                            break;
                        }
                        else
                        {
                            IsPalindrom2=true;
                        }
                    }
                }
                if (IsPalindrom2 == true)
                {
                    if (MaxLen<(b-i)+1)
                    {
                        MaxLen=(b-i)+1;
                        MaxNa4=i;
                        MaxKr=b;
                    }

                    if (MaxNa4-Na4!=0)
                    {
                        f=MaxNa4;
                        Br=MaxNa4-Na4-1;
                        for (int j =Na4-1;j<(Br/2)+Na4-1;j++,f--)
                        {
                            if (a[j] != a[f])
                            {
                                Left=false;
                                break;
                            }
                            else
                            {
                                Left = true;
                            }
                        }
                    }

                    if (Kr - MaxKr!=0)
                    {
                        f=Kr;
                        Br=Kr - MaxKr+1;

                        for (int j =MaxKr+1;j<((Kr - MaxKr)/2)+MaxKr+1;j++,f--)
                        {

                            if (a[j] != a[f])
                            {

                                Right=false;
                                break;
                            }
                            else
                            {
                                Right = true;
                            }
                        }
                    }
                    if ((Kr - MaxKr==0 || Right== true)&&(MaxNa4-Na4==0 || Left == true))Br2=true;
                }
            }
            if (Br2==true)break;
        }
        if (Br2==true)break;
    }
    if (MaxLen==0)Otg+=Kr-Na4+1;
    else
    {
        Otg++;
        if (MaxNa4-Na4!=0)
        {
            if (Left == false)Nai(Na4,MaxNa4-1);
            else Otg++;
        }
        if (Kr-MaxKr!=0)
        {
            if (Right == false)Nai(MaxKr+1,Kr);
            else Otg++;
        }

    }
}

int main ()
{
    bool IsPalindrom = true;
    cin>>a;

    if (a.length()==1)Otg = 0;
    else
    {
        for (int i = 0;i<a.length()/2;i++)
        {
            if (a[i] != a[a.length()-i-1])
            {
                IsPalindrom = false;
                break;
            }
        }

        if (IsPalindrom == false)
        {
            Nai(0,a.length()-1);
        }
        else Otg=0;
    }
    if (Otg>0) cout<<Otg-1;
    else cout<<Otg;

    return 0;
}
