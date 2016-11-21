#include<stdio.h>

int main()
{
    char ara[7],i=0;
    while(scanf("%s",ara))
    {   i++;
        if(ara[0]=='*')break;
        if(ara[0]=='H')printf("Case %d: Hajj-e-Akbar\n",i);
        else printf("Case %d: Hajj-e-Asghar\n",i);
    }


return 0;
}
