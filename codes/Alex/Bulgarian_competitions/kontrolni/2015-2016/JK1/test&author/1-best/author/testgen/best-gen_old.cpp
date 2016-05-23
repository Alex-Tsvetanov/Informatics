//Task: best - test generator
//Author: Alexander Ivanov & Yoana Zelova
#include <set>
#include <ctime>
#include <vector>
#include <cstdio>
#include <climits>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
using namespace std;

vector<string> names;
const int MAXN=32;
const double MAXP=200;

string get_random_string()
{
    stringstream rt;

    for(int i=rand();i!=0;i/=10)
    {
        rt<<(char)('a'+(i%10));
    }

    return rt.str();
}

string generate_name()
{
    vector<string> titles=  {"mr-", "mrs-", "miss-", "captain-", "chairman-", "earl-", "fellow-", "faggot-", "king-", "queen-", "prince-", "princess-"};
    vector<string> prefixes={"", "raz", "rez", "prez", "na", "po", "ne"};
    vector<string> bases=   {"ivan", "dragan", "petkan", "john", "bergen", "smith", "trev"};
    vector<string> suffixes={"sten", "stein", "in", "ov", "ova", "lo", "er", "ski", "ska", ""};
    vector<string> cities  ={"pleven", "yambol", "varna", "burgas", "plovdiv", "sofia", "vratsa", "rousse", "tarnovo", "vidin", "haskovo", "kardzhali", "samokov"};

    stringstream rt("");


    if(rand()%2==0)
    {
        rt<<titles[rand()%titles.size()];
    }

    if(rand()%2==0)
    {
        rt<<prefixes[rand()%prefixes.size()]<<bases[rand()%bases.size()]<<'-'<<bases[rand()%bases.size()]<<suffixes[rand()%suffixes.size()];
    }
    else
    {
        rt<<prefixes[rand()%prefixes.size()]<<bases[rand()%bases.size()]<<suffixes[rand()%suffixes.size()];
    }

    if(rand()%2==0)
    {
        if(rand()%2==0)rt<<"-sr";
        else rt<<"-jr";
    }

    if(rand()%2==0)
    {
        rt<<"-of-"<<cities[rand()%cities.size()];
    }

    if(rand()%2==0)
    {
        rt<<'-'<<get_random_string();
    }

    return rt.str();
}

void fetch_names()
{
    set<string> names;
    fstream in;
    in.open("names.txt");
    while(!in.eof())
    {
        string name;
        in>>name;
        if(name.size()<3)continue;
        names.insert(name);
    }

    //string namegen="abcdefghijklmnopqrstuvwxyz-";
    while(names.size()<MAXN+10)
    {
        //names.emplace(namegen.begin(), namegen.end()-1);
        //next_permutation(namegen.begin()+1, namegen.end());
        names.insert(generate_name());
    }

    ::names={names.begin(), names.end()};

    sort(::names.begin(), ::names.end(), [](const string &a, const string &b){return a.size()<b.size();});
}

int get_rand(int from, int to)
{
    /* */if(to-from+1<=RAND_MAX)return rand()%(to-from+1)+from;
    else if(rand()%2==0)return get_rand(from, (from+to)/2);
    else return get_rand((from+to)/2+1, to);
}
int get_rand(int to){return get_rand(0, to);}

struct test
{
    int n, m;
    double p1, p2;
    int v1, v2;
    vector<pair<string, string>> pairs;

    string to_string()
    {
        stringstream rt("");

        rt<<n<<' '<<m<<endl;
        rt<<p1<<' '<<v1<<endl;
        rt<<p2<<' '<<v2<<endl;
        for(auto &i : pairs)rt<<i.first<<' '<<i.second<<endl;
        return rt.str();
    }
};

test generate_test()
{
    funcent:;
    test rt;
    rt.n=get_rand(1, MAXN);
    rt.m=get_rand(1, rt.n*3);
    rt.p1=get_rand(MAXP*100)/100.0;
    rt.p2=get_rand(MAXP*100)/100.0;
    rt.v1=get_rand(rt.n*1.5);
    rt.v2=get_rand(rt.n*1.5);

    set<pair<string, string>> pairs;
    set<string> notAlone;

    for(int i=0;i<rt.m;i++)
    {
        int x=0, y=0;
        for(;;)
        {
            x=get_rand(rt.n-1);
            y=get_rand(rt.n-1);

            if(x!=y&&pairs.find({names[x], names[y]})==pairs.end())
            {
                    notAlone.insert(names[x]);
                    notAlone.insert(names[y]);
                    break;
            }
        }

        pair<string, string> p(names[x], names[y]);
        for(char &c : p.first)if(rand()%4==0&&c<='z'&&c>='a')  {c-='a';c+='A';}
        for(char &c : p.second)if(rand()%4==0&&c<='z'&&c>='a') {c-='a';c+='A';}
        pairs.insert(p);
    }

    if(notAlone.size()<rt.n)goto funcent;

    rt.m=pairs.size();
    rt.pairs={pairs.begin(), pairs.end()};

    return std::move(rt);
}

test generate_maxn_test()
{
    test rt;
    rt.n=MAXN;
    //rt.m=get_rand(1, rt.n*3);
    rt.p1=get_rand(MAXP*100)/100.0;
    rt.p2=get_rand(MAXP*100)/100.0;
    rt.v1=get_rand(rt.n*3);
    rt.v2=get_rand(rt.n*3);

    set<pair<int, int>> pairs;
    for(int i=0;;i++)
    {
        int times=get_rand(1, 32);
        for(int z=0;z<times;z++)for(int j=1;j<=rt.n;j++)
        {
            int neighbourCount=get_rand(1, 10);
            for(int k=0;k<neighbourCount;k++)
            {
                int nei=0;
                for(;;)
                {
                    nei=get_rand(1, rt.n);
                    if(j!=nei&&pairs.find({j, nei})==pairs.end()&&pairs.find({nei, j})==pairs.end())break;
                }
                pairs.emplace(j, nei);
            }
        }
    }

    for(auto &i : pairs)
    {
        rt.pairs.emplace_back(names[i.first-1], names[i.second-1]);
    }

    rt.m=pairs.size();
    return std::move(rt);
}

string filename(int id)
{
    stringstream rt("");
    rt<<"best.";
    if(id<10)rt<<'0';
    rt<<id<<".in";
    return rt.str();
}

int main()
{
    ios::sync_with_stdio(false);
    fetch_names();

    printf("there are %d names avaiable\n", names.size());

    srand(time(nullptr));

    for(;;)
    {
        system("del /F emilova.txt");
        system("del /F best.txt");
        test t=generate_test();
        puts("test generated");
        ofstream file;
        file.open("test.txt");
        file<<t.to_string();
        file.close();
        system("emilova.exe < test.txt > emilova.txt");
        system("best.exe < test.txt > best.txt");
        Sleep(4000);
        fstream fs;
        string solution, gSol;
        fs.open("emilova.txt");
        fs>>gSol;
        fs.close();
        fs.open("best.txt");
        fs>>solution;
        fs.close();
        puts(solution.c_str());
        puts(gSol.c_str());
        puts("__________");
        if(solution!=gSol)system("pause");
    }

    return 0;
    vector<test> tests;
    for(int i=0;i<19;i++)tests.push_back(generate_test());
    tests.push_back(generate_maxn_test());

    sort(tests.begin(), tests.end(), [](const test &a, const test &b){return a.n<b.n;});

    for(int i=0;i<tests.size();i++)
    {
        ofstream str;
        str.open("tests/"+filename(i+1));
        str<<tests[i].to_string();
        str.close();
    }
}
