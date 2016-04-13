#include<iostream>
#include<vector>
#include<algorithm>

std::vector < int > neighbours0[400000];
std::vector < int > neighbours1[400000];
bool usable[400000];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio("false");

    int n, a, b;
    std::cin>>n>>a>>b;

    int dijkstra[n];
    for(int i=0;i<=n;i++)
    {
        dijkstra[i]=999999;
    }
    dijkstra[a]=0;

    std::vector <int> queue;


    std::vector <int> blacklist;
    blacklist.push_back(a);

    queue.push_back(a);

    bool unfairInput1=true;
    bool unfairInput2=true;


    int numberusable=1;

    while(std::cin)
    {
        int tempa, tempb;
        std::cin>>tempa>>tempb;
        if(usable[tempa]==0)
        {
            numberusable++;
        }
        usable[tempa]=1;
        if(usable[tempb]==0)
        {
            numberusable++;
        }
        usable[tempb]=1;
        if(tempa == a or tempb == a)
        {
            unfairInput1=false;
        }
        if(tempa == b or tempb == b)
        {
            unfairInput2=false;
        }
        neighbours0[tempa].push_back(tempb);
        neighbours1[tempb].push_back(tempa);
    }

    if(unfairInput1 or unfairInput2)
    {
        std::cout<<"X"<<std::endl;
        return 0;
    }

    int currentprice=0;
    int currentposition=0;
    //std::cout<<n<<" "<<numberOfNumbers<<" "<<std::endl;
    //if(numberOfNumbers<n)

    while(numberusable-2 != currentposition)
    {

        for(int i=0;i<neighbours0[queue[currentposition]].size() and neighbours0[queue[currentposition]].begin()!=neighbours0[queue[currentposition]].end();i++)
        {
            if(currentprice + 0 < dijkstra[neighbours0[queue[currentposition]][i]])
            {
                dijkstra[neighbours0[queue[currentposition]][i]] = 0 + currentprice;

            }
            bool Blacklisted=false;
            for(int j=0;j<blacklist.size();j++)
            {
                if(neighbours0[queue[currentposition]][i] == blacklist[j])
                {
                    Blacklisted=true;
                    break;
                }
            }
            if(!Blacklisted)
            {
                queue.push_back(neighbours0[queue[currentposition]][i]);
                blacklist.push_back(neighbours0[queue[currentposition]][i]);
            }
        }

        for(int i=0;i<neighbours1[queue[currentposition]].size() and neighbours1[queue[currentposition]].begin()!=neighbours1[queue[currentposition]].end();i++)
        {

            if(currentprice + 1 < dijkstra[neighbours1[queue[currentposition]][i]])
            {
                dijkstra[neighbours1[queue[currentposition]][i]] = 1 + currentprice;
            }
            bool Blacklisted=false;
            for(int j=0;j<blacklist.size();j++)
            {
                if(neighbours1[queue[currentposition]][i] == blacklist[j])
                {
                    Blacklisted=true;
                    break;
                }
            }
            if(!Blacklisted)
            {
                queue.push_back(neighbours1[queue[currentposition]][i]);
                blacklist.push_back(neighbours1[queue[currentposition]][i]);
            }
        }

        currentposition++;
        currentprice=dijkstra[queue[currentposition]];
    }


    if(dijkstra[b] == 999999)
    {
        std::cout<<"X"<<std::endl;
        return 0;
    }
    std::cout<<dijkstra[b]<<std::endl;
    return 0;
}
