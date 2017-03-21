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
int ara[100001];
bool comp(int a, int b)
{
    if(abs(a)<abs(b))
        return false;
    return true;
}
int main()
{
    int tc;
    int neg=0,lastn=0,lastp=0,nxtp=0,nxtn=0,flag=0;
    int n,k;
    lint mult=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        sort(ara,ara+n,comp);
//        for(int i=0;i<n;i++)
//        {
//            printf("%d ",ara[i]);
//        }
//        pf("\n");
        neg=0,lastn=0,lastp=0,nxtp=0,nxtn=0,flag=0;
        for(int i=0;i<k;i++)
        {
            if(ara[i]<0){neg++;lastn=i;}
            else lastp=i;
        }
        if((neg&1) && k!=1)
        {
            for(int i=k;i<n;i++)
            {
                if(ara[i]>=0 && nxtp==0)nxtp=i;
                if(ara[i]<0 && nxtn==0)nxtn=i;
                if(nxtp!=0 && nxtn!=0)break;
            }
            if(nxtn==0 && nxtp==0)flag=0;
            else if(nxtn==0 && nxtp!=0)
            {
                flag=1;
            }
            else if(nxtn!=0 && nxtp==0)
            {
                flag=-1;
            }
            else if(ara[lastn]*ara[nxtn]>ara[lastp]*ara[nxtp])
            {
                flag=-1;
            }
            else if(ara[lastn]*ara[nxtn]<=ara[lastp]*ara[nxtp]) flag=1;
        }
        mult=1;
        if(flag==1)
        {
            for(int i=0;i<k;i++)
            {
                if(i==lastn)
                    continue;
                mult=(mult*abs(ara[i]))%1000000007;
            }
            mult=(mult*ara[nxtp])%1000000007;
        }
        else if(flag==-1)
        {
            for(int i=0;i<k;i++)
            {
                if(i==lastp)
                    continue;
                mult=(mult*abs(ara[i]))%1000000007;
            }
            mult=(mult*abs(ara[nxtn]))%1000000007;
        }
        else if(flag==0)
        {
            if(k==1 && neg==1)
            {
                int bigp=0,smalln=0;
                for(int i=0;i<n;i++)
                {
                    if(ara[i]>=0){
                        bigp=i;
                        break;
                    }
                }
                if(bigp==0){
                    for(int i=n-1;i>=0;i--)
                    {
                        if(ara[i]<0){
                            smalln=ara[i];
                            break;
                        }
                    }
                    mult=smalln%1000000007+1000000007;
                }
                else mult=ara[bigp]%1000000007;

            }
            else if(nxtn==0 && nxtp==0 && n==k)
            {
                for(int i=0;i<n;i++)
                {
                    int rem;
                    if(ara[i]<0)rem=ara[i]%1000000007+1000000007;
                    else rem=ara[i]%1000000007;
                    mult=(mult*rem)%1000000007;
                }
            }
            else{
                for(int i=0;i<k;i++)
                {
                    mult=(mult*abs(ara[i]))%1000000007;
                }
            }
        }


        printf("%I64d\n",mult%1000000007);


    }
    return 0;
}

/*
2
10 6
-15 -2 -4 5 3 -1 0 15 2 1
*/

