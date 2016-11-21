#include<stdio.h>
#include<string.h>
int main()
{
int i,result=0,ntest,len,j,k,sum=0;
char ara[1000];
scanf("%d",&ntest);
int ara2[ntest];
for(i=0;i<ntest;i++)
{
    scanf("%s",ara);
    len=strlen(ara);
    again:
    for(j=0;j<len;j++)
    { if(ara[j]=='0'){continue;}
	for(k=0;k<len;k++)
        {
            if(k!=j)
            {
                    sum=sum+ara[k]-'0';

            }
        }

        if(sum%3==0 && result==0) {
                result=1;
            ara[j]='0';
            if(sum!=0)goto again; }
        else if(sum%3==0 && result==1) {
            result=0;
        ara[j]='0';
        if(sum!=0)goto again;}

        sum=0;
    }

        if(result==1)printf("Case %d: S\n",i+1);
        else printf("Case %d: T\n",i+1);
        result=0;



}

return 0;
}
