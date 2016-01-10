#include<iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    int red[n], l = 0, s = 1000000, idl[2], ids[2];
    for(int i = 0; i < n; i++){
        cin >> red[i];

        if(red[i] > l){
            l = red[i];
            idl[0] = i+1;
            idl[1] = i+1;
        }else
            if(red[i] == l && idl[0] < i+1)
                idl[0] = i+1;

        if(red[i] < s){
            s = red[i];
            ids[0] = i+1;
            ids[1] = i+1;
        }else
            if(red[i] == s && ids[1] < i+1)
                ids[1] = i+1;
    }

    if(idl[0] - ids[0] > idl[1] - ids[1] or (idl[0] == idl[1] && ids[0] == ids[1]))
        cout << ids[0] << " " << idl[0] << endl;
    else{
        if(idl[0] - ids[0] < idl[1] - ids[1])
            cout << idl[1] << " " << ids[1] << endl;
        else{
            if(idl[0] - ids[0] == idl[1] - ids[1]){
                if(idl[0] + ids[0] < idl[1] - ids[1])
                    cout << ids[0] << " " << idl[0] << endl;
                else
                    cout << idl[1] << " " << ids[1] << endl;
            }
        }
    }

    return 0;
}
