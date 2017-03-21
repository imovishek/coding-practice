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
int n,divi;
int ara[60];
int dp[51][257];
int flag[60];
int rec(int pos, int cp, int f)
{
    if(cp==0){
            if(f==2)return 1;
        if(rec(0,divi,2))return 1;
    }
    if(pos==n)return 0;
    if(cp<0)return 0;
    int ret=0;
    int past=flag[pos];
    if(flag[pos]==0)
    {
        flag[pos]=1;
        ret|=rec(pos+1,cp-ara[pos],f);
    }
    if(ret)return ret;
    flag[pos]=past;
    ret|=rec(pos+1,cp,f);
    return ret;
}
int main()
{
    int t,tst=1;
    sf1(t);
    int sum;
    while(t--)
    {
        memset(flag,0,sizeof(flag));
        sum=0;
        sf1(n);
        for(int i=0;i<n;i++)
        {
            sf1(ara[i]);
            sum+=ara[i];
        }
        pcase(tst++);
        if(sum%3!=0)pf(":(\n");
        else{
            int flagi=0;
            divi=sum/3;
            for(int i=0;i<n;i++)
            if(ara[i]>divi){flagi=1;break;}
            if(flagi)pf(":(\n");
            else{
                    int i;
                for(i=0;i<n;i++){
                    if(rec(i,divi,1))
                    {
                        pf("Eid Makes Happy Everyone\n");
                        break;
////                        for(int j=0;j<n;j++)if(flag[j]==1){pf("%d ",ara[j]);flag[j]=2;}
////                        pf("*\n");
//                        if(rec(i,divi)){
////                            for(int j=0;j<n;j++)if(flag[j]==1){pf("%d ",ara[j]);}
////                            pf("*:p\n");
//
//                        }
//                        else
                    }
                    else {memset(flag,0,sizeof(flag));}
                }
                if(i==n)pf(":(\n");
            }
        }
    }
    return 0;
}
