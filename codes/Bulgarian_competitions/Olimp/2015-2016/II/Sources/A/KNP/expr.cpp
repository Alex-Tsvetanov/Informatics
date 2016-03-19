#include<iostream>
#include<cstring>
#include<vector>
int N;
bool alpha[26];
bool solve(std::string str)
{
    if(str.size()==1) return alpha[str[0]-'a'];
    return !(alpha[str[0]-'a']&&solve(str.substr(1, str.size())));
}
struct tree
{
    std::string val;
    std::vector<tree*> kid;
    tree() {val="";}
    bool get_res()
    {
        if(val=="")
        {
            bool res = 0;
            for(int i=0; i<kid.size(); ++i)
                res = !(res&&(kid[i]->get_res()));
            return res;
        }
        else return solve(val);
    }
    void grow()
    {
        kid.push_back(new tree);
    }
};
int build_tree(tree* &root, std::string str)
{
    //std::cout<<str<<'\n';
    int kids=-1, i=0;
    bool in = true;
    if(str[0]!='(')
    {
        root->grow();
        ++kids;
        in=false;
    }
    while(i<str.size())
    {
        if(str[i]=='(')
        {
            root->grow(); ++kids;
            i+=build_tree(root->kid[kids], str.substr(i+1, str.size()));
        }
        if(str[i]!='('&&str[i]!=')')
        {
            root->kid[kids]->val+=str[i];
            ++i;
        }
        if(str[i]==')')
        {
            if(in) return i;
            else ++i;
        }
    }
    return str.size();
}
int main()
{
    std::string str;
    std::cin>>str;
    tree* root = new tree;
    build_tree(root, str);
    std::string input;
    std::cin>>input;
    while(input[0]!='2')
    {
        for(int i=0; i<26; ++i) alpha[i]=0;
        for(int i=0; i<input.size(); ++i)
            alpha[i] = input[i]-'0';
        std::cout<<root->get_res()<<'\n';
        std::cin>>input;
    }
    return 0;
}
