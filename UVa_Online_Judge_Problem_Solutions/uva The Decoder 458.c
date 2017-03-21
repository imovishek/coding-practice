#include<stdio.h>
#include<string.h>
int main()
{
    char ara[500];
    int i,len;
    while(gets(ara))
    {

        len=strlen(ara);
        for(i=0;i<len;i++)
        {
          ara[i]=ara[i]-7;

        }
        printf("%s\n",ara);
    }


    return 0;
}
