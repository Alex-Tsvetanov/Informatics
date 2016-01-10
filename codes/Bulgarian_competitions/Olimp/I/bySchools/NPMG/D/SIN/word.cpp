#include <iostream>
#include <algorithm>
using namespace std;
int main( )
{
    int bukvi[28],br,k;
    char a;
    for(br=0;a!='#';++br){
        cin >> a;
        if('A'<=a<='Z'){
            k=a-'A';
            a='a';
            a+=k;
        }
        if('a'<=a<='z')
        ++bukvi[a-'a'];
    }
    for(br=0;br<6;++br)
        cout << bukvi[br];
    return 0;
}
//There is a bug.I cannot to compile normally.
