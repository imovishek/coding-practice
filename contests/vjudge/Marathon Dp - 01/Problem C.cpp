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
using namespace std;
typedef long long int lint;
typedef double dbl;
int flag[101];
int n;
int ara[101][101];
int dp[101][101];
int maxi(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int rec(int p, int q,int get)
{
    if(p==n-1 && q==0)return ara[p][q];
    if(dp[p][q]!=-65536){
//        printf("%d %d %d***\n",p,q,dp[p][q]);

    return dp[p][q];
    }
    int &ret=dp[p][q];

    if(q-1>-1)
    {
        ret=ara[p][q]+rec(p,q-1,ara[p][q]);
    }
    if(p+1<n)
    {
        ret=maxi(ret,ara[p][q]+rec(p+1,q,ara[p][q]));
    }

    return ret;
}
int main()
{
    int t,test=1;
    sf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)flag[i]=n-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                dp[i][j]=-65536;
        }
//        printf("%d*\n",flag[0]);
        int s=n*2-1,c=1,k,l=0;
//        printf("s=%d\n",s);
        for(int i=0;i<s;i++,l++)
        {
            if(i<n)k=l+1;
            else k=l-c++;
//            printf("k=%d\n",k);
            for(int j=0;j<k;j++)
            {
                if(flag[j]>-1)
                {
//                    printf("k=%d\n",flag[j]);
                    scanf("%d",&ara[j][flag[j]--]);
//                    printf("k*=%d\n",k);
                }
                else {
                        int minus_ache=j;
                        while(flag[j]==-1){j++;k++;}
                        scanf("%d",&ara[j][flag[j]--]);
                }
            }
            if(c>1)l--;
        }

//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//                pf("%d ",ara[i][j]);
//            pf("\n");
//        }
        pcase(test++);
        printf("%d\n",rec(0,n-1,0));
    }
    return 0;
}

/*

5
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5

10
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6 7
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10
3 4 5 6 7 8 9 10
4 5 6 7 8 9 10
5 6 7 8 9 10
6 7 8 9 10
7 8 9 10
8 9 10
9 10
10

*/
