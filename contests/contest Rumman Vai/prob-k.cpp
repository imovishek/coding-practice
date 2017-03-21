#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
vector <char> sign[81],res;
char ara[]="+-*";
int k=0;
int signRecog(int a,int b,char sign)
{
    if(sign=='+')
        return a+b;
    if(sign=='-')
        return a-b;
    if(sign=='*')
        return a*b;
}
void reArrangeSign()
{
    if(res.size()==4)
    {
        sign[k]=res;
        k++;
        return;
    }
    for(int i=0;i<3;i++)
    {
        res.push_back(ara[i]);
        reArrangeSign();
        res.pop_back();
    }
}

int flag[5]={0};
int num[5],result,bigflag=0;
vector <int> anumset;
void reArrangeNum()
{
    if(anumset.size()==5)
    {
        for(int i=0;i<81;i++)
        {
            result=signRecog(anumset[0],anumset[1],sign[i][0]);
            result=signRecog(result,anumset[2],sign[i][1]);
            result=signRecog(result,anumset[3],sign[i][2]);
            result=signRecog(result,anumset[4],sign[i][3]);
            if(result==23){
                bigflag=1;
                return;
            }
            result=0;

        }
    }
    for(int i=0;i<5;i++)
    {
       if(flag[i]==0)
       {
            flag[i]=1;
            anumset.push_back(num[i]);
            reArrangeNum();
            anumset.pop_back();
            flag[i]=0;
            if(bigflag)return;
       }
    }
}

int main()
{
    reArrangeSign();
    while(scanf("%d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4]))
    {
        if(num[0]==0 && num[1]==0 && num[2]==0 && num[3]==0 && num[4]==0)break;
        reArrangeNum();
        if(bigflag)printf("Possible\n");
        else printf("Impossible\n");
        bigflag=0;

    }
    return 0;
}
