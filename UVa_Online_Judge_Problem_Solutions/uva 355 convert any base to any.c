#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<inttypes.h>
int main()
{
 freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int64_t i,j,len,b1,b2,digit,is_err=0,num1=0,rem;
    char ara[100],res[1000],ch;
    while(scanf("%"PRId64" %"PRId64"",&b1,&b2)==2)
    {
        is_err=0;

        num1=0;

            scanf("%s",ara);
            len=strlen(ara);

            for(i=0;i<len;i++)
            {
                if(ara[i]>='0' && ara[i]<='9')digit=ara[i]-'0';
                else digit=toupper(ara[i])-'A'+10;

                if(digit>=b1 || digit<0){is_err=1;break;}
                num1=num1*b1+digit;

            }

            if(num1==0){res[0]='0';i=0;}
            else i=-1;
            for(++i;!is_err && num1>0;i++)
            {
                rem=num1%b2;

                if(rem<10)res[i]=rem+'0';
                else res[i]='A'+rem-10;

                num1/=b2;

            }

            res[i]='\0';

            for(j=0;j<i/2;j++){ch=res[j];res[j]=res[i-1-j];res[i-1-j]=ch;}
            if(is_err ) printf("%s is an illegal base %"PRId64" number\n",ara,b1);
            else printf("%s base %"PRId64" = %s base %"PRId64"\n",ara,b1,res,b2);






    }
    return 0;
}
