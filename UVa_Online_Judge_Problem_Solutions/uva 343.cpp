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
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char ara[100],nxt[100],ara2[100],nxt2[100];
    while(scanf("%s %s",ara,nxt)!=EOF){
        strcpy(nxt2,nxt);
        strcpy(ara2,ara);
        int digit,minb1=0,minb2=0b0,len1,len2,i,flag=0,j;
        for(i=0;ara[i];i++)
        {
            if(ara[i]<='9' && ara[i]>='0')digit=ara[i]-'0';
            else digit=toupper(ara[i])-'A'+10;
            ara[i]=digit;
            if(digit>minb1)minb1=digit;
        }
        len1= i;
        for(i=0;nxt[i];i++)
        {
            if(nxt[i]<='9' && nxt[i]>='0')digit=nxt[i]-'0';
            else digit=toupper(nxt[i])-'A'+10;
            nxt[i]=digit;
            if(digit>minb2)minb2=digit;
        }
        len2=i;
        minb1++,minb2++;
        if(minb1==1)minb1++;
        if(minb2==1)minb2++;
        for(i=minb1;i<37;i++)
        {
            for(j=minb2;j<37;j++)
            {
                lint ans1=0,ans2=0;
                for(int k=0;k<len1;k++)
                    ans1=ans1*i+ara[k];
                for(int k=0;k<len2;k++)
                    ans2=ans2*j+nxt[k];
                if(ans1==ans2)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }
//        pf("*%d %d*****7\n",i,j);
        if(flag)printf("%s (base %d) = %s (base %d)\n",ara2,i,nxt2,j);
        else printf("%s is not equal to %s in any base 2..36\n",ara2,nxt2);

    }
    return 0;
}
