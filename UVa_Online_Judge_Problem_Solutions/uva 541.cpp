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
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;

int main()
{
    int n;
    while(sf1(n) && n)
    {
        int ara[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sf1(ara[i][j]);
            }
        }
        int flag=0,posa,posb;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=ara[i][j];
            }
            if(sum&1){flag++;posa=i;}
        }
        if(flag==1 || flag==0){
            int flagi=0;
            for(int i=0;i<n;i++)
            {
                int sum=0;
                for(int j=0;j<n;j++)
                {
                    sum+=ara[j][i];
                }
                if(sum&1){flagi++;posb=i;}
            }
            if(flagi==0 && flag==0)pf("OK\n");
            else if(flag^flagi) pf("Corrupt\n");
            else if(!(flag^flagi))pf("Change bit (%d,%d)\n",posa+1,posb+1);
        }
            else pf("Corrupt\n");
    }

    return 0;
}
