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
int main()
{
    char ara[150];
    int t,tst=1;
    sf("%d",&t);
    while(t--)
    {
        scanf("%s",ara);
        int mxlen=0,len=strlen(ara),i,j;
        if(ara[5]==ara[7])pf("<3\n");
        for(i=0;ara[i];i++)
        {
            int slen=1;
            for(j=1;ara[j];j++)
            {
//                if(i==6 && ara[i+j]==ara[i-j])printf("%c%c%c*****\n",ara[i-j],ara[i],ara[i+j]);
                if(i+j<len && i-j>=0 && ara[i+j]==ara[i-j])
                {
                    printf("%c%c%c*****\n",ara[i-j],ara[i],ara[i+j]);
                    slen+=2;
                }
                else break;
            }
            printf("%d*\n",slen);
            if(mxlen<slen)mxlen=slen;
            slen=0;
            for(j=0;ara[j];j++)
            {
                if(i+j+1<len && i-j>=0 && ara[i+j+1]==ara[i-j])
                    slen+=2;
                else break;
            }
            if(mxlen<slen)mxlen=slen;printf("%d**\n",slen);
        }
        pcase(tst++);
        printf("%d\n",len-mxlen);

    }
    return 0;
}
