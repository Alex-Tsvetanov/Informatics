#include<iostream>
 
int masiv[10000000];
int masiv2[10000000];
 
int inv=0;
 
void mergeSort(int begin,int end)
{
    //std::cout<<245<<std::endl;
    if(end-begin==0)
        return;
    mergeSort(begin,(end+begin)/2);
    mergeSort((end+begin)/2+1,end);
    int index1=begin,index2=(end+begin)/2+1;
    int counter=begin;
     
    while(index1<=(end+begin)/2 && index2<=end)
    {
        if(masiv[index1]<=masiv[index2])
        {
            masiv2[counter]=masiv[index1];
            index1++;
            counter++;
        }
        else
        {
            masiv2[counter]=masiv[index2];
            inv+=((end+begin)/2-begin+1);
            index2++;
            counter++;
        }
    }
    while(index1<=(end+begin)/2)
        {
               masiv2[counter]=masiv[index1];
               index1++;
               counter++;
        }
        while(index2<=end)
        {               
               masiv2[counter]=masiv[index2];
               index2++;
               counter++;
        }
    for(int i=begin;i<=end;i++)
    {
        masiv[i]=masiv2[i];
    }
    //return;
}
 
int main(){
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::cin>>masiv[i];
    }
    mergeSort(0,n-1);
    /*for(int i=0;i<n;i++)
    {
        std::cout<<masiv[i];
    }*/
    std::cout<<inv<<std::endl;
    return 0;
}
