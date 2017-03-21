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
#define pcase(x) printf("Case %d: ",x)
#define pb push_back
using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int>edge[10];
vector<int>vt;
int flag[6][6];
void gopen(int pos)
{
    int siz=vt.size();
    if(siz==8){
        printf("1");
        for(int i=0;i<siz;i++)
            printf("%d",vt[i]);
        printf("\n");
    return;
    }
    siz=edge[pos].size();
    for(int i=0;i<siz;i++)
    {
        if(flag[edge[pos][i]][pos]==0)
        {
            flag[edge[pos][i]][pos]=1;
            flag[pos][edge[pos][i]]=1;
            vt.push_back(edge[pos][i]);
            gopen(edge[pos][i]);
            vt.pop_back();
            flag[edge[pos][i]][pos]=0;
            flag[pos][edge[pos][i]]=0;
        }
    }

}

int main()
{
    edge[1].pb(2);
    edge[1].pb(3);
    edge[1].pb(5);
    edge[2].pb(1);
    edge[2].pb(3);
    edge[2].pb(5);
    edge[3].pb(1);
    edge[3].pb(2);
    edge[3].pb(4);
    edge[3].pb(5);
    edge[4].pb(3);
    edge[4].pb(5);
    edge[5].pb(1);
    edge[5].pb(2);
    edge[5].pb(3);
    edge[5].pb(4);
    flag[1][2]=0;
    flag[1][3]=0;
    flag[1][5]=0;
    flag[2][1]=0;
    flag[2][3]=0;
    flag[2][5]=0;
    flag[3][1]=0;
    flag[3][2]=0;
    flag[3][4]=0;
    flag[3][5]=0;
    flag[4][3]=0;
    flag[4][5]=0;
    flag[5][1]=0;
    flag[5][2]=0;
    flag[5][3]=0;
    flag[5][4]=0;


    gopen(1);
    return 0;
}











