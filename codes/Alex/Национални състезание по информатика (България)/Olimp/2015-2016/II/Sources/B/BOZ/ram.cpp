#include<iostream>
#include<queue>
using namespace std;

int wls (int a, int b){
    return (a+1)*b + (b+1)*a;
}

int left (int a, int b){
    if(a != b)
        return wls(a, b) - (a > b ? b*2 : a*2 - 1);
    else
        return wls(a, b) - (a*2 - 1);
}

int main ()
{
    int lft;
    cin >> lft;

    int a = 1, b = 1;
    int p = 0, br = 0, a1 = a, b1 = b;
    queue <int> a2;
    queue <int> b2;

    while(left(a, b) <= lft){

        if (left(a1, b1) == lft){
            p++;
            a2.push(a1);
            b2.push(b1);
        }

            if(br == 0){
                b1++;

                if(left(a1, b1) > lft){
                    b1= b;
                    br++;
                }
            }else{
                a1++;

                if(left(a1, b1) > lft){
                    a++;
                    b++;
                    a1 = a;
                    b1 = b;
                    br = 0;
                }
            }
    }

    if (!a2.empty()) {

        while(!a2.empty()){
            cout<< b2.front() << " " << a2.front() << '\n';
            b2.pop();
            a2.pop();
        }

    }else cout << 0;

    cout << endl;

    return 0;
}
