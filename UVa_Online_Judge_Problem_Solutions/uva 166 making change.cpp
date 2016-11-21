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
#define pi acos(-1.0)
#define mini(a,b) (a<b)?a:b
#define inf 21474836
using namespace std;
typedef long long int lint;
typedef double dbl;
int coin[]={5, 10, 20, 50, 100, 200};
int c[7], amount[1007], ara[1007];
void print(int arr[], int n)
{
    puts("");
    for(int i=0;i<n;i++)
        pf("%d ",arr[i]);
    puts("");
}
int tabledp(int m)
{
    int flag[m+2],alest[m+2];
    for(int i=0;i<m+2;i++) amount[i]=inf;
    memset(alest,0,sizeof(alest));
    amount[0]=0;
    for(int i=0;i<6;i++)
    {
        memset(flag,0,sizeof(flag));
        for(int j=coin[i],l=0;j<=m;j++,l++)
        {
            alest[j]=amount[j];
//            ara[j]=mini(ara[l]+1,ara[j]);
            if((flag[j]=flag[l]+1)<=c[i])
            {
                amount[j]=mini(amount[j], amount[l]+1);
            }
            else {
                for(int k=j,n=0;k>=0 && n<=c[i]; n++,k-=coin[i])
                    amount[j]=mini(amount[j], alest[k]+n);
            }
        }
    }
    return ara[m];
}

int tabledp1(int m)
{
    int alest[m+2];
    for(int i=0;i<m+2;i++) ara[i]=inf;
    ara[0]=0;
    for(int i=0;i<6;i++)
    {
        for(int j=coin[i],l=0;j<=m;j++,l++)
        {
            ara[j]=mini(ara[l]+1,ara[j]);
        }
    }
    return ara[m];
}
int main()
{
    int m,n;
    while(1)
    {
        int zeros=0;
        for(int i=0;i<6;i++){
            sf1(c[i]);
            if(c[i]==0)zeros++;
        }
        if(zeros==6)break;
        dbl d;
        sf("%lf",&d);
        m=d*100+.5;


        tabledp(2*m);
        tabledp1(m);
        int min0=inf,val;int ci=0;
        for(int i=m;i<=2*m; i+=5){
            if(min0>amount[i]+ara[i-m]){
                min0=amount[i]+ara[i-m];

                val=i;
            }

//            pf("%d %d %d + %d = %d* %d\n",min0,i,amount[i],ara[i-m],amount[i]+ara[i-m],++ci);
        }
//        pf("%.2lf\n",val/100.0);
        if(min0>=inf){pf("  0\n");continue;}
        pf("%3d\n",min0);
    }
    return 0;

}
/*
2 2 1 2 1 0  0.95
1 1 6 1 4 0  4.65

3 0 3 0 0 0 0.55

*/
