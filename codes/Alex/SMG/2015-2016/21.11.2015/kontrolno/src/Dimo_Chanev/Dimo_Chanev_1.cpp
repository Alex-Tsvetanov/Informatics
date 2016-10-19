#include <iostream>

using namespace std;

struct chas
{
    int hour, minutes;
};

int main()
{
    string boza;
    chas chas1;
    cin>>boza;
    int a = (boza[0]-'0')*10 + boza[1]-'0';
    int b = (boza[3]-'0')*10 + boza[4]-'0';
    chas1.hour=a;
    chas1.minutes=b;
    chas chas2;
    cin>>boza;
    a = (boza[0]-'0')*10 + boza[1]-'0';
    b = (boza[3]-'0')*10 + boza[4]-'0';
    chas2.hour=a;
    chas2.minutes=b;
    chas res = {0, 0};
    while(chas1.hour != chas2.hour || chas2.minutes != chas1.minutes)
    {
        chas1.minutes++;
        if(chas1.minutes==60)
        {
            chas1.minutes=0;
            chas1.hour++;
        }
        if(chas1.hour>=24)
        {
            chas1.hour=0;
        }
        res.minutes++;
        if(res.minutes==60)
        {
            res.minutes=0;
            res.hour++;
        }
        if(res.hour==24)
        {
            res.hour=0;
        }
    }
    cout<<res.hour<<":"<<res.minutes<<endl;
    return 0;
}
