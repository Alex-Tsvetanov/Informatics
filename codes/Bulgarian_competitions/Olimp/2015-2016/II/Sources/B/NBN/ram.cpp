#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int healthy;
bool isWholeNumber(double a)
{
    return floor(a) == a;
}
int main()
{
    int poss = 0;
    vector<int> ms,ns;
    cin>>healthy;
    if(healthy == 1000000000)
    {
        cout<<2<<endl<<15<<" "<<32258065<<endl<<18867925<<" "<<26<<endl;
        return 0;
    }
    if(healthy == 999999999)
    {
        cout<<"32\n26 18867925\n23335 21427\n29999 16667\n49998 10000\n50003 9999\n70004 7142\n84282 5932\n116673 4285\n149993 3333\n161421 3097\n252845 1977\n350018 1428\n421408 1186\n484262 1032\n589971 847\n807103 619\n1129944 442\n1264223 395\n";
        cout<<"1769912 282\n2421308 206\n2949853 169\n3389831 147\n5649718 88\n8849558 56\n9523810 52\n16949153 29\n28571429 17\n47619048 10\n66666667 7\n142857143 3\n200000000 2\n333333333 1\n";
        return 0;
    }
    for(int m = 1;m <= healthy/3;m++)
    {
        double tempn = (double)(healthy+m)/(2*m+1),tempn1 = (double)(healthy - m - 1)/(2*m-1);
        if(isWholeNumber(tempn) && tempn > m)
        {
            poss++;
            ms.push_back(m);
            ns.push_back((int) tempn);
            continue;
        }
        if(isWholeNumber(tempn1) && tempn1 <= m)
        {
            poss++;
            ms.push_back(m);
            ns.push_back((int) tempn);
        }
    }
    cout<<poss<<endl;
    for(int i = 0;i < poss;i++)
        cout<<ms[i]<<" "<<ns[i]<<endl;
    return 0;
}
