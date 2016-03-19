#include <iostream>
#include <cstring>

using namespace std;

char values[256];
Vertex vertices[4096];

class Vertex
{
    public:
    void* in1;
    void* in2;

    bool GetVal()
    {
        bool v1, v2;
        if(IsVertex(in1)) v1 = ((Vertex*)in1)->GetVal();
        else v1 = *((char*)in1);

        if(IsVertex(in2)) v2 = ((Vertex*)in2)->GetVal();
        else v2 = *((char*)in2);

        return !(v1 & v2);
    }

    private:

    bool IsVertex(void* ptr)
    {
        return ptr >= vertices && ptr <= (vertices+4096);
    }
}

void Print(char* s, int l)
{
    for(int i = 0; i < l; i++) cout<<char(s[i]+'0');
    cout<<endl;
}


bool And(char* ptr)
{
    /*cout<<"AND input: ";
    Print(ptr, 2);*/
    bool r = (*ptr) & (*(ptr+1));
    //cout<<"output: "<<r<<endl;
    return r;
}

bool Nand(char* ptr)
{
    /*cout<<"NAND input: ";
    Print(ptr, 2);*/
    bool r = !((*ptr) & (*(ptr+1)));
    //cout<<"output: "<<r<<endl;
    return r;
}

int PrepareString(char* str)
{
    int len = strlen(str);
    for(char* c = str; c < (str+len); c++) *c -= '0';
    return len;
}


int main()
{

}
