//Task: best - test generator
//Author: Alexander Ivanov & Yoana Zelova
#include <bits/stdc++.h>
//#define DEBUG_GEN
//#define DEBUG_TEST

const int SMALL_TEST_COUNT=6;
const int BIG_TEST_COUNT=14;
const int MAXN=10000;
const int SMALL_MAXN=25;
const double MAXP=100.0;
const double SMALL_MAXP=100.0;
const int GREEDY_CHANCE=6;
const int LOWERCASE_CHANCE=2;

using namespace std;

struct uset_hash
{
    unsigned long long operator () (const pair<int, int> item)const
    {
        return 1000ull*item.first+item.second;
    }
};

struct test
{
    int n, m;
    int v1, v2;
    double p1, p2;
    vector<pair<string, string>> pairs;
    string to_string()
    {
        stringstream rt;
        rt.str("");

        rt<<n<<' '<<m<<endl;
        rt<<p1<<' '<<v1<<endl;
        rt<<p2<<' '<<v2<<endl;
        for(const pair<string, string> &x : pairs)rt<<x.first<<' '<<x.second<<endl;


        return std::move(rt.str());
    }

    bool operator < (const test &that)const
    {
        return n<that.n;
    }
};

void shuffle_case(string &s, int chance)
{
    for(char &c : s)
    {
        if(c>='A'&&c<='Z'){c-='A';c+='a';}
        if(rand()%chance==0&&c>='a'&&c<='z')
        {
            c-='a';
            c+='A';
        }
    }
}

vector<string> fetch_names()
{
    vector<string> rt;

    set<string> names;
    fstream in;
    in.open("names.txt");
    while(!in.eof())
    {
        string name;
        in>>name;
        if(name.size()<3)continue;
        if(names.find(name)==names.end())
        {
            names.insert(name);
            rt.push_back(name);
        }
    }

    return std::move(rt);
}
vector<string> names=fetch_names();
string alphabet="abcdefghijklmnopqrstuvwxyz_";

int get_rand(int from, int to)
{
    int rt;
    /* */if(to-from+1<=RAND_MAX)rt= rand()%(to-from+1)+from;
    else if(rand()%2==0)rt= get_rand(from, (from+to)/2);
    else rt= get_rand((from+to)/2+1, to);
    //printf("%d %d -> %d\n", from, to, rt);
    return rt;
}
inline int get_rand(int to){return get_rand(0, to);}

vector<int> generate_unions(int n, int unionCount)
{
    //printf("generate_unions called %d %d\n", n, unionCount);
    vector<int> rt(unionCount, n/unionCount);

    for(int i=0;i<n%unionCount;i++)rt[get_rand(0, rt.size()-1)]++;

    for(int i=0;i<n;i++)
    {
        vector<int> fromIndexes;
        for(int j=0;j<rt.size();j++)if(rt[j]>2)fromIndexes.push_back(j);
        if(!fromIndexes.empty())
        {
            int x=fromIndexes[get_rand(0, fromIndexes.size()-1)];
            int y=get_rand(0, rt.size()-1);
            rt[x]--;
            rt[y]++;
        }
    }

    sort(rt.begin(), rt.end());
    //puts("generate_unions returning");
    return std::move(rt);
}

int greedy_fit(int in, vector<int> coins)
{
    sort(coins.rbegin(), coins.rend());
    int sum=0;
    for(int i : coins)
    {
        if(sum+i<=in)sum+=i;
        if(sum==in)return sum;
    }
    return sum;
}

int smart_fit(int in, const vector<int> &coins)
{
    vector<bool> summed(in+1, false);
    vector<int> sums{0};
    for(int c : coins)
    {
        for(int len=sums.size(), i=0;i<len;i++)
        {
            int sum=sums[i]+c;
            if(sum<=in&&!summed[sum])
            {
                summed[sum]=true;
                sums.push_back(sum);
            }
        }
    }

    int ans=0;
    for(int i : sums)ans=max(ans, i);
    return ans;
}

template<typename T> vector<int> indexes_of(const T &value, const vector<T> &in)
{
    vector<int> rt;
    for(int i=0;i<in.size();i++)if(in[i]==value)rt.push_back(i);
    return std::move(rt);
}

vector<vector<int>> generate_graph(int n, vector<int> unionSizes)
{
    vector<vector<int>> gr(n);
    vector<vector<int>> unions;
    vector<bool> used(n);
    int edges=0;

    for(int uSize : unionSizes)
    {
        vector<int> unused=indexes_of(false, used);
        vector<int> currentUnion;
        currentUnion.push_back(unused[get_rand(0, unused.size()-1)]);
        used[currentUnion.back()]=true;

        while(currentUnion.size()<uSize)
        {
            unused=indexes_of(false, used);
            int connectTo=currentUnion[get_rand(0, currentUnion.size()-1)];
            int toAdd=unused[get_rand(0, unused.size()-1)];
            currentUnion.push_back(toAdd);
            used[toAdd]=true;
            gr[connectTo].push_back(toAdd);
            gr[toAdd].push_back(connectTo);
            edges++;
        }

        unions.push_back(currentUnion);
    }

    return std::move(gr);
}

string filename(int id)
{
    stringstream rt;
    rt<<"best.";
    if(id<10)rt<<'0';
    rt<<id<<".in";
    return rt.str();
}

test generate_test(int minN, int maxN, double maxP, bool letterName, bool shuffleCase, bool greedyWorks)
{
    regenerate:;

    int n=get_rand(minN, maxN);
    int unionCount=get_rand(3, max(n/2, 3));

    int sumAllUnions=0;
    vector<int> unions=generate_unions(n, unionCount);
    for(int i : unions)sumAllUnions+=i;

    int cheapSpace=sumAllUnions/get_rand(2, 5);
    if((smart_fit(cheapSpace, unions)==greedy_fit(cheapSpace, unions))!=greedyWorks)goto regenerate;

    vector<vector<int>> graph=generate_graph(n, unions);
    unordered_set<pair<int, int>, uset_hash> edges;

    for(int i=0;i<n;i++)for(int j : graph[i])
    {
        edges.emplace(i, j);
        edges.emplace(j, i);
    }

    test rt;
    rt.n=n;
    rt.m=edges.size();
    if(!letterName)
    {
        for(const pair<int, int> &e : edges)rt.pairs.emplace_back(names[e.first], names[e.second]);
    }
    else
    {
        for(const pair<int, int> &e : edges)
        {
            rt.pairs.emplace_back(string()+alphabet[e.first], string()+alphabet[e.second]);
        }
    }

    if(shuffleCase)
    {
        for(pair<string, string> &x : rt.pairs)
        {
            shuffle_case(x.first, 3);
            shuffle_case(x.second, 3);
        }
    }

    int faggtSpace=get_rand(n-cheapSpace, min(maxN-cheapSpace, n));
    double cheapPrice=get_rand(1*100, maxP*100)/100.0;
    double faggtPrice=get_rand(1*100, maxP*100)/100.0;
    if(cheapPrice>faggtPrice)swap(cheapPrice, faggtPrice);

    if(rand()%2==0)
    {
        rt.p1=cheapPrice;
        rt.v1=cheapSpace;
        rt.p2=faggtPrice;
        rt.v2=faggtSpace;
    }
    else
    {
        rt.p1=faggtPrice;
        rt.v1=faggtSpace;
        rt.p2=cheapPrice;
        rt.v2=cheapSpace;
    }

    return rt;
}

int main()
{
    srand(time(nullptr));
    vector<test> tests;

    int i, minN, maxN;
    for(i=0;i<SMALL_TEST_COUNT-1;i++)
    {
        tests.push_back(generate_test(3, SMALL_MAXN, SMALL_MAXP, true, i%LOWERCASE_CHANCE==1, i%GREEDY_CHANCE==0));
        printf("%d small tests generated\n", tests.size());
    }
    tests.push_back(generate_test(SMALL_MAXN, SMALL_MAXN, SMALL_MAXP, true, i%LOWERCASE_CHANCE==1, i%GREEDY_CHANCE==0));
    printf("%d small tests generated\n", tests.size());

    for(i=0, minN=3, maxN=MAXN/BIG_TEST_COUNT;i<BIG_TEST_COUNT-1;i++)
    {
        tests.push_back(generate_test(minN, maxN, MAXP, false, i%LOWERCASE_CHANCE==1, i%GREEDY_CHANCE==0));
        printf("%d tests generated\n", tests.size());

        minN+=MAXN/BIG_TEST_COUNT;
        maxN+=MAXN/BIG_TEST_COUNT;
    }
    tests.push_back(generate_test(MAXN, MAXN, MAXP, false, i%LOWERCASE_CHANCE==1, i%GREEDY_CHANCE==0));
    printf("%d tests generated\n", tests.size());

    sort(tests.begin(), tests.begin()+SMALL_TEST_COUNT);
    sort(tests.begin()+SMALL_TEST_COUNT, tests.end());

    for(int i=0;i<tests.size();i++)
    {
        ofstream file;
        file.open("tests/"+filename(i+1));
        file<<tests[i].to_string();
        file.close();
    }
}
