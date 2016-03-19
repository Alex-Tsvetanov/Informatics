#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct date{
    long long start;
    long long stop;
}arr[1000000];
long long maxDay;
int cmp(const date a, const date b);
void transport(long long& mTemp, long long& eTemp, long long currentDay);
bool weekednShouldWork(long long currentDay, long long e, long long mt);
int prnt(short int x);

int main(){
    long long m, n, p;
    cin >> n >> m >> p;
    long long e = p/2;

    for(long long i = 0;  i < m;  i++){
        scanf("%d%d", &arr[i].start, &arr[i].stop);
    }
    maxDay = arr[m-1].stop;
    sort(arr, arr+m, cmp);
    bool shouldWork = false;

    long long mTemp = m;
    for(long long currentDay = 1;  currentDay <= maxDay;  currentDay ++){
            //cout << "c=" << currentDay << " mt=" << mTemp << " e=" << e << " rt=" << arr[mTemp].start << " ot=" << arr[mTemp - 1].stop;
        if(arr[mTemp - 1].stop < currentDay){
            return prnt(3);
        }

        long long eTemp = e;
        if(currentDay%7 == 6 && shouldWork == false){//Saturday
            if(weekednShouldWork(currentDay, e, mTemp)){
                shouldWork = true;
                transport(mTemp, eTemp, currentDay);
            }
        } else {//Weekdays
            transport(mTemp, eTemp, currentDay);
        }



        //cout << "\n";
        if(mTemp == 0){
            break;
        }
    }

    if(shouldWork){
        return prnt(2);
    }


    return prnt(1);
}

int cmp(const date a, const date b){
    maxDay = max(maxDay, max(a.stop, b.stop));
    if(a.stop == b.stop){
        return a.start > b.start;
    }
    return a.stop > b.stop;
}

void transport(long long& mTemp, long long& eTemp, long long currentDay){
    while((arr[mTemp-1].start <= currentDay) && eTemp > 0 && mTemp > 0){
            mTemp--;
            eTemp--;
    }
}

bool weekednShouldWork(long long currentDay, long long e, long long mt){
//currentDay == 6 (mod 7)
    long long num = 0;
    for(int i = mt - 1;  arr[i].stop < currentDay + 3;  i--){
        if(arr[i].stop == (currentDay + 1 || currentDay + 2))
            return true;
        num++;
    }
    //cout << "num = " << num << "\n";
    return num <= 3*e;
}

int prnt(short int x){
    char prntstr[10] = "";
    switch(x)
    {
        case 1:
            strcpy(prntstr, "OK");
            break;
        case 2:
            strcpy(prntstr, "Mixed");
            break;
        case 3: default:\
            strcpy(prntstr, "IMPOSSIBLE");
            break;
    }
    printf("\n%s", prntstr);
    return 0;
}
