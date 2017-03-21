#include<stdio.h>
#include<string.h>
int main()
{

    int i,len;
    char ara[31];
    while(scanf("%s",ara)!=EOF)
    {
        len=strlen(ara);
        for(i=0;i<len;i++)
        {
            if(ara[i]>='A' && ara[i]<='C')printf("2");
            else if(ara[i]>='D' && ara[i]<='F')printf("3");
            else if(ara[i]>='G' && ara[i]<='I')printf("4");
            else if(ara[i]>='J' && ara[i]<='L')printf("5");
            else if(ara[i]>='M' && ara[i]<='O')printf("6");
            else if(ara[i]>='P' && ara[i]<='S')printf("7");
            else if(ara[i]>='T' && ara[i]<='V')printf("8");
            else if(ara[i]>='W' && ara[i]<='Z')printf("9");
            else printf("%c",ara[i]);
        }
        printf("\n");
    }
    return 0;
}
