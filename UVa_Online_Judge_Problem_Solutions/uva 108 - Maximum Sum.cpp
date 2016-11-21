#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int ara[101][101];
int maxi=0;
int dp[101][101][101][101];
int find_max(int sx, int sy, int ex, int ey)
{
    int sum=0;
    if(sx==ex){
            for(int i=sy;i<=ey;i++)
                sum+=ara[sx][i];
            if(sum>maxi)maxi=sum;
            return sum;
    }
    else if(sy==ey){
            for(int i=sx;i<=ex;i++)
                sum+=ara[i][sy];
            if(sum>maxi)maxi=sum;
            return sum;
    }



}
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&ara[i][j]);
    }
    find_max(0,0,0,0);

    return 0;
}
