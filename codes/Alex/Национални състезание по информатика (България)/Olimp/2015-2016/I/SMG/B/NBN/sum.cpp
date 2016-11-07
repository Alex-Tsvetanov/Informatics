#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int diff = 2;
    int changeDiffAt = 2;
    int diffJump=2;
    int changeDiffJumpAt = 2;
    int changeDiffJumpAtNext = 2;
    long long ans=2;
    for(int i = 3;i < n;i+=2)
    {
        ans+=diff;
        changeDiffAt--;
        if(changeDiffAt == 0)
        {
            changeDiffAt = 2;
            if(changeDiffJumpAt == 0)
            {
                changeDiffJumpAt = changeDiffJumpAtNext;
                changeDiffJumpAtNext++;
                diffJump+=2;
            }
            diff+=diffJump;
            changeDiffJumpAt--;
        }
    }
    if(n==1)
        cout<<0<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
