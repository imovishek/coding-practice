#include<stdio.h>
#include<string.h>
int main()
{
    char ara[20];
    int i;
    for(i=1;scanf("%s",ara)!=EOF;i++)
    {
        if(strlen(ara)==1 && ara[0]=='#')break;
        if(!strcmp(ara,"HELLO"))printf("Case %d: ENGLISH\n",i);
        else if(!strcmp(ara,"HOLA"))printf("Case %d: SPANISH\n",i);
        else if(!strcmp(ara,"HALLO"))printf("Case %d: GERMAN\n",i);
        else if(!strcmp(ara,"BONJOUR"))printf("Case %d: FRENCH\n",i);
        else if(!strcmp(ara,"CIAO"))printf("Case %d: ITALIAN\n",i);
        else if(!strcmp(ara,"ZDRAVSTVUJTE"))printf("Case %d: RUSSIAN\n",i);
        else printf("Case %d: UNKNOWN\n",i);

    }


return 0;
}
