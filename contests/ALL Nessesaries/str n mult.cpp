#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define MX 10000
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define mset(a,b) memset((a),b,sizeof((a)))
typedef long long int lint;
typedef double dbl;
int ara[MX+7];
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
bool is_num(char ch){return ch>='0' && ch<='9';}
void str_rev(char ara[])
{
    int len=strlen(ara);
    int lim=(len>>1);
    char ch;
    for(int i=0;i<lim;i++)
    {
       ch=ara[i];
       ara[i]=ara[len-1-i];
       ara[len-1-i]=ch;
    }
}
void strnmult(char ara[], int n, char ans[])
{

    for(int i=0;i<4005;i++)ans[i]=0;

    int len=strlen(ara),m=0,mult,i,ls=0;
    for( i=0;ara[i];i++)
    {
        mult=(ara[i]-'0')*n;
        m=i;

        do
        {
            if(is_num(ans[m])){
                ans[m]+=mult%10;
                mult+=10*((ans[m]-'0')/10);
                ans[m]=(ans[m]-'0')%10+'0';
            }
            else ans[m]=mult%10+'0';
            mult/=10;
            m++;
        }while(mult);
        if(m>ls)ls=m;
    }
    ans[ls]=0;
}

int main()
{
    int t,tst=1,n;
    sf("%d",&t);
    while(t--)
    {
        char str[5005]="1",ans[5005];
        mset(ara,0);
        int a,mult=1;
        sf1(n);
        while(n--)
        {
            sf1(a);
            int x=a;

            for(int i=0;i<25 && p[i]*p[i]<=x;i++)
            {
                int counti=0;
                while(a%p[i]==0)
                {
                    counti++;
                    a/=p[i];
                }
                if(ara[p[i]]<counti)ara[p[i]]=counti;
            }
            if(a>1 && ara[a]==0)ara[a]++;
        }
        for(int i=2;i<10001;i++)
        {
            if(ara[i]!=0)
            {
                for(int j=0;j<ara[i];j++)
                {
//                    pf("%d*\n",i);
                    strnmult(str,i,ans);
                    strcpy(str,ans);
                }

//               pf("%d %d : %s %s*\n",i,ara[i],str,ans);
            }
        }
        str_rev(str);
        pcase(tst++);
        printf("%s\n",str);

    }
    return 0;
}
