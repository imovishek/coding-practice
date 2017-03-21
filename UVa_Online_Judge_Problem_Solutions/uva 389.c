#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{

    int i,j,len,b1,b2,digit,num1=0,rem;
    char ara[15],res[100],ch;
    while(scanf("%s %d %d",ara,&b1,&b2)==3)
    {


        num1=0;


            len=strlen(ara);

            for(i=0;i<len;i++)
            {
                if(ara[i]>='0' && ara[i]<='9')digit=ara[i]-'0';
                else digit=toupper(ara[i])-'A'+10;
                num1=num1*b1+digit;

            }

            if(num1==0){res[0]='0';i=0;}
            else i=-1;
            for(++i; num1>0;i++)
            {
                rem=num1%b2;

                if(rem<10)res[i]=rem+'0';
                else res[i]='A'+rem-10;

                num1/=b2;

            }

            res[i]='\0';

            for(j=0;j<i/2;j++){ch=res[j];res[j]=res[i-1-j];res[i-1-j]=ch;}
            if(i>7) printf("  ERROR\n");
            else {i=7-i;while(i--)printf(" ");
                    printf("%s\n",res);}

}
    return 0;
}

