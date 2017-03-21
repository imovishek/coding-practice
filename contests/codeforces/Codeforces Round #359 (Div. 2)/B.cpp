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
    cin >> n;
    int ara[n],sorted[n];
    for(int i=0;i<n;i++){
        sf("%d",&ara[i]);
        sorted[i]=ara[i];
    }
    sort(sorted,sorted+n);
//    for(int i=0;i<n;i++)pf("%d ",sorted[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ara[j]==sorted[i])
            {
                for(int k=j+1;k>i+1;k--)
                {
                    pf("%d %d\n",k-1,k);
                    swap(ara[k-1],ara[k-2]);
                }
                ara[i]=2147483647;
                break;
            }
        }
    }

    return 0;
}
