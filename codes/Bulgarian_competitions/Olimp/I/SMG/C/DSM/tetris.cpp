#include<iostream>
using namespace std;
char Map[105][105],Input[105];
long long x,y,N,M;
int main()
{
    cin>>N>>M;
    bool correctLine=true;
    long long numberOfCorrectLines=0,answ=0,j;
    for(y=0; y<N; y++)
    {
        cin>>Input;
        for(x=0;x<M;x++){
           Map[x][y]=Input[x];
        }
    }
    for(j=0; j<N;)
    {
        correctLine=true;
        numberOfCorrectLines=0;
        for(y=0; y<N-j; y++)
        {
            correctLine=true;
            for(x=0; x<M; x++)
            {
                if(Map[x][y]=='.')
                {
                    correctLine=false;
                    numberOfCorrectLines=0;
                    break;
                }
            }
            if(!correctLine)
            {
                answ=answ+(numberOfCorrectLines*(numberOfCorrectLines+1)/2);
                numberOfCorrectLines=0;
            }
            else
            {
                numberOfCorrectLines=numberOfCorrectLines+1;
            }
        }
        answ=answ+(numberOfCorrectLines*(numberOfCorrectLines+1)/2);
        if(numberOfCorrectLines==0){
          j=j+1;
        }else{
            j=j+numberOfCorrectLines;
        }
    }
    cout<<answ<<endl;
    return 0;
}
