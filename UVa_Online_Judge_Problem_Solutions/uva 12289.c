#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

int main()
{
    char ara[10],len;
    int t;
    scanf("%d",&t);
    while(t-- && scanf("%s",ara))
    {
        len=strlen(ara);
        if(len==3)
        {
            if(ara[0]=='o' &&(ara[1]=='n' || ara[2]=='e') )
                printf("1\n");
            else if(ara[1]=='n' &&(ara[0]=='o' || ara[2]=='e') )
                printf("1\n");
            else if(ara[2]=='e' &&(ara[0]=='o' || ara[1]=='n') )
                printf("1\n");
            else printf("2\n");
        }
        else printf("3\n");
    }
    return 0;
}
