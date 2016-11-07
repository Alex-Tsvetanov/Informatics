#include<iostream>
#include<stack>
using namespace std;

struct order {
    int s, e;
};

struct day {
    stack <int> orders;
    bool we = false;
};

bool check (order a, order b){
    if(a.s > b.s)
            return true;
        else
            if(a.s == b.s and a.e > b.e)
                    return true;

        return false;
}

bool checkp (order a, order b){
    if(a.s < b.s)
            return true;
        else
            if(a.s == b.s and a.e < b.e)
                    return true;

        return false;
        }

int main ()
{
    int d, n, p;
    cin >> d >> n >> p;
    order o [n];
    p/=2;

    cin >> o[0].s >> o[0].e;

    for(int i = 1; i < n; i++){
        cin >> o[i].s >> o[i].e;

        if( checkp (o[i], o[i-1]) )
            swap(o[i], o[i-1]);
    }

    int br = 0;

    for(int i = 0; i < n; i++){
        if( check (o[i], o[i+1]) ){
            swap(o[i], o[i+1]);

            while(br == 0){

                if( checkp (o[i], o[i-1] ) and i != 0){
                    swap(o[i], o[i-1]);

                    i-=1;
                }else
                    br++;
            }

            br = 0;
        }
    }

    cout << "MIXED" << endl;


    return 0;
}

