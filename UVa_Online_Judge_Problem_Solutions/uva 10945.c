#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
int i,j,is_iok,is_jok;
char ara[100];
while(gets(ara))
{
    if(!strcmp(ara,"DONE"))break;
    j=strlen(ara)-1;
    for(i=0;i<j+1;i++)ara[i]=toupper(ara[i]);

    for(i=0;j>=i;)
    {

        if(ara[i]<'A' || ara[i]>'Z'){i++;is_iok=0;}
        else is_iok=1;
        if(ara[j]<'A' || ara[j]>'Z'){j--;is_jok=0;}
        else is_jok=1;
        if(is_iok==1 && is_jok==1){if (ara[i]==ara[j]){i++;j--;}
        else break;}
    }
    if(j<i) printf("You won't be eaten!\n");
    else printf("Uh oh..\n");

}

return 0;
}
