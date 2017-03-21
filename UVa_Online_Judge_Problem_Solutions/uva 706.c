#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
typedef long long int lint;
typedef double dbl;
int main()
{
    int s;
    char ara[15];
    while(scanf("%d %s",&s,ara)!=EOF && s)
    {
        int i,j,k;
        for(i=0;ara[i];i++)
        {
            if(i!=0)pf(" ");
            if(ara[i]=='2' || ara[i]=='3' || ara[i]=='5' || ara[i]=='6'|| ara[i]=='7' || ara[i]=='8' || ara[i]=='9' || ara[i]=='0')
            {
                pf(" ");
                for(j=0;j<s;j++)
                    pf("-");
                pf(" ");
            }
            else for(j=-2;j<s;j++)
                    pf(" ");
        }
        pf("\n");

        for(i=0;i<s;i++)
        {
            for(j=0;ara[j];j++)
            {
                if(j!=0)pf(" ");
                if( ara[j]=='4' ||  ara[j]=='5' ||  ara[j]=='6' ||  ara[j]=='8' ||  ara[j]=='9' ||  ara[j]=='0' )
                    printf("|");
                else printf(" ");
                for(k=0;k<s;k++)pf(" ");
                if( ara[j]=='1' ||  ara[j]=='2' ||  ara[j]=='3' ||  ara[j]=='4' ||   ara[j]=='7'  ||  ara[j]=='8'  ||  ara[j]=='9' ||  ara[j]=='0' )
                    pf("|");
                else pf(" ");
            }
            pf("\n");
        }

        for(i=0;ara[i];i++)
        {
            if(i!=0)pf(" ");
            if(ara[i]=='2' || ara[i]=='3' || ara[i]=='5' || ara[i]=='6'|| ara[i]=='4' || ara[i]=='8' || ara[i]=='9')
            {
                pf(" ");
                for(j=0;j<s;j++)
                    pf("-");
                pf(" ");
            }
            else for(j=-2;j<s;j++)
                    pf(" ");
        }

        pf("\n");
        for(i=0;i<s;i++)
        {
            for(j=0;ara[j];j++)
            {
                if(j!=0)pf(" ");
                if( ara[j]=='2' ||  ara[j]=='6' ||  ara[j]=='8' ||  ara[j]=='0'  )
                    printf("|");
                else printf(" ");
                for(k=0;k<s;k++)pf(" ");
                if( ara[j]=='1' ||  ara[j]=='5' ||  ara[j]=='3' ||  ara[j]=='4' ||   ara[j]=='7'  ||  ara[j]=='8'  ||  ara[j]=='9' ||  ara[j]=='0' || ara[j]=='6')
                    pf("|");
                else pf(" ");
            }
            pf("\n");
        }
        for(i=0;ara[i];i++)
        {
            if(i!=0)pf(" ");
            if(ara[i]=='2' || ara[i]=='3' || ara[i]=='5' || ara[i]=='6'|| ara[i]=='0' || ara[i]=='8' || ara[i]=='9')
            {
                pf(" ");
                for(j=0;j<s;j++)
                    pf("-");
                pf(" ");
            }
            else for(j=-2;j<s;j++)
                    pf(" ");
        }
        printf("\n\n");
    }

    return 0;
}
