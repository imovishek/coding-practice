#include<stdio.h>
#include<string.h>

int main()
{


{
    int i,len,is_started=0,count=0;
    char ara[500];
    while(gets(ara))
    {
        len=strlen(ara);
        for(i=0;i<len;i++)
        {
            if(((ara[i]>='A' && ara[i]<='Z') || (ara[i]>='a' && ara[i]<='z')) && is_started==0){is_started=1; count++;}
            else if (!((ara[i]>='A' && ara[i]<='Z') || (ara[i]>='a' && ara[i]<='z'))) is_started=0;
        }
        is_started=0;
        printf("%d\n",count);
        count=0;
    }
}
return 0;
}
