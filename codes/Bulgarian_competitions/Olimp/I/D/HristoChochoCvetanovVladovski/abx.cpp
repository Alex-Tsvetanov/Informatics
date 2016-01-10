#include<iostream>
using namespace std;
int main ()
{
    int A,B;
    char X,znak1,znak2;
    A>=0;
    B>=0;
    X='X';
    znak1='='||'-'||'+';
    znak2='='||'-'||'+';
    if (A>=0)
    {
        cin >> A >> znak1 >> B >> znak2 >> X or cin >> X >> znak1 >> B >> znak2 >> A or cin >> X >> znak1 >> A >> znak2 >> B or cin >> A >> znak1 >> X >> znak2 >> B or cin >> B >> znak1 >> X >> znak2 >> A or cin >> B >> znak1 >> A >> znak2 >> X;
        if ((znak1=='-') or (znak1=='+'))
        {
            znak2='=';
        }
        if ((znak2=='-') or (znak2=='+'))
        {
            znak1='=';
        }
        if (A>B)
        {
            if (znak1=='+'||znak2=='+')
            {
                cout << A+B << endl;
            }
            else
            {
                if (znak1=='+'&&znak2=='=')
                {
                    cout << A+B << endl;
                }
                if (znak1=='='&&znak2=='-')
                {
                    cout << A-B << endl;
                }
                if (znak1=='='&&znak2=='+')
                {
                    cout << A+B << endl;
                }
                if (znak1=='-'&&znak2=='=')
                {
                    cout << A-B << endl;
                }
                if (znak1=='-'||znak2=='-')
                {
                    cout << A-B << endl;
                }
            }
        }
        if (A<B)
        {
            if (znak1=='+'||znak2=='+')
            {
                cout << A+B << endl;
            }
            else
            {
                if (znak1=='+'&&znak2=='=')
                {
                    cout << A+B << endl;
                }
                if (znak1=='='&&znak2=='-')
                {
                    cout << A-B << endl;
                }
                if (znak1=='='&&znak2=='+')
                {
                    cout << A+B << endl;
                }
                if (znak1=='+'&&znak2=='=')
                {
                    cout << A-B << endl;
                }
                if (znak1=='-'||znak2=='-')
                {
                    cout << A-B << endl;
                }
            }
        }
        if (A==B)
        {
            if (znak1=='+'||znak2=='+')
            {
                cout << A+B << endl;
            }
            else
            {
                if (znak1=='+'&&znak2=='=')
                {
                    cout << A+B << endl;
                }
                if (znak1=='='&&znak2=='-')
                {
                    cout << A-B << endl;
                }
                if (znak1=='='&&znak2=='+')
                {
                    cout << A+B << endl;
                }
                if (znak1=='-'&&znak2=='=')
                {
                    cout << A-B << endl;
                }
                if (znak1=='-'||znak2=='-')
                {
                    cout << A-B << endl;
                }
            }
        }
    }
    return 0;
}
