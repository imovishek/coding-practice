#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pf printf
#define sf scanf
#define mini(x,y) (x<y)?x:y
using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int>edge[2007];
int dp[1007],n,a,b,flag[2007]={},ara[1007][2],last,asb;
int cow=0,bull=0,bigflag=0;
void bicolor(int node, int color)
{
    int siz=edge[node].size(),emnei;
    flag[node]=color;
    emnei=(color==1)? bull++ : cow++;
    for(int i=0; i<siz; i++)
    {
        if(flag[edge[node][i]]==0)
        {
            bicolor(edge[node][i],(color==1)? -1 : 1);
        }
        else{
            if(flag[edge[node][i]]==color)
            {
                bigflag= 1;
            }
        }
    }
}
int test(int pos,int cpb, int cpc)
{
    if(pos==last && ((cpb<=a && cpc<=b)||(cpb<=b && cpc<=a)))return 1;
    if(pos==last)return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    int& ret=dp[pos];
    ret=0;
    ret|=test(pos+1,cpb+ara[pos][0],cpc+ara[pos][1]);
    ret|=test(pos+1,cpb+ara[pos][1],cpc+ara[pos][0]);
    return ret;

}
int main()
{
    int t;
    sf("%d",&t);
    while(t--)
    {

        int u,v;
        scanf("%d %d %d",&a,&b,&n);
        asb=a+b;
        for(int i=1;i<=asb;i++){
            edge[i].clear();
            flag[i]=0;
        }
        for(int i=0;i<n;i++){
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        bigflag=0;
        last=0;
        for(int i=1;i<=asb;i++){
            if(edge[i].size()>0 && !flag[i]){
                bicolor(i,1);
                if(bigflag)break;
            }
            if(bull || cow)
            {
                ara[last][0]=bull;
                ara[last][1]=cow;
                bull=0;
                cow=0;
                last++;
            }
        }

        if(bigflag){
                pf("no\n");
                bull=0;
                cow=0;
        }
        else {
//                pf("%d &\n",last);
//                for(int i=0;i<last;i++)pf("%d %d @\n",ara[i][0],ara[i][1]);
                for(int i=0;i<last;i++)
                 dp[i]=-1;
                if(test(0,0,0))
                    pf("yes\n");
                else pf("no\n");

        }

    }
    return 0;
}
/*
5
2 2 4
1 2
2 3
3 4
4 1

3 3 5
1 2
3 6
6 5
5 4
3 4

*/
