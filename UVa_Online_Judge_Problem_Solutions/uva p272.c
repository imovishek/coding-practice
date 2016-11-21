#include<stdio.h>
#include<string.h>
void main()
{
    char i,len,ara[1000];
    int is_started=0;
    while(gets(ara))
    {
        len=strlen(ara);
        for(i=0;i<len;i++){
           if(ara[i]!='\"') printf("%c",ara[i]);
           else if (ara[i]=='\"' && is_started==0) {printf("``");is_started=1;}
           else {printf("''");is_started=0;}
        }
        printf("\n");
    }
}
