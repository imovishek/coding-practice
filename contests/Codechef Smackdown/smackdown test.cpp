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
lint ara[1000000];
bool comp(lint a, lint b)
{
    if(abs(a)<abs(b))
        return false;
    return true;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        lint n,k;
        scanf("%I64d %I64d",&n,&k);
        for(lint i=0;i<n;i++)
        {
            scanf("%I64d",&ara[i]);
        }
        sort(ara,ara+n,comp);

        lint neg=0,lastn,lastp,nxtp=-1,nxtn=-1,flag=0;
        for(lint i=0;i<k;i++)
        {
//            mult=(mult*abs(ara[i]))%1000000007;
            if(ara[i]<0){neg++;lastn=i;}
            else lastp=i;
        }
        if(neg&1 && k!=1)
        {
            for(lint i=k;i<n;i++)
            {
                if(ara[i]>=0 && nxtp==-1)nxtp=i;
                else if(ara[i]<0 && nxtn==-1)nxtn=i;
                if(nxtp!=-1 && nxtn!=-1)break;
            }
            if(nxtn==-1 && nxtp!=-1)
            {
                flag=1;
            }
            else if(nxtn!=-1 && nxtp==-1)
            {
                flag=-1;
            }
            else if(ara[lastn]*ara[nxtn]>ara[lastp]*ara[nxtn])
            {
                flag=-1;
            }
            else flag=1;
        }
        lint mult=1;
        if(flag==1)
        {
            for(lint i=0;i<k;i++)
            {
                if(i==lastn)
                    continue;
                mult=(mult*abs(ara[i]))%1000000007;
            }
            mult=(mult*ara[nxtp])%1000000007;
        }
        else if(flag==-1)
        {
//            printf("%d %d*\n",ara[lastn],ara[nxtn]);
            for(lint i=0;i<k;i++)
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
                lint bigp=-1,smalln=-1;
                for(lint i=0;i<n;i++)
                {
                    if(ara[i]>=0){
                        bigp=i;
                        break;
                    }
                }
                if(bigp==-1){
                    for(lint i=n-1;i>=0;i--)
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
            else{
                for(lint i=0;i<k;i++)
                {
                    mult=(mult*abs(ara[i]))%1000000007;
                }
            }
        }
        printf("%I64d\n",mult);


    }
    return 0;
}

