#include<stdio.h>
#include<string.h>

int main()
{


    char ara[500000],ara2[500000];
    int len1,i,j;
    while(scanf("%s %s",ara,ara2)!=EOF)
    {

        len1=strlen(ara);

        for(i=0,j=0;i<len1 && ara2[j]!='\0';)
        {
            if(ara[i]!=ara2[j])j++;
            else {i++;j++;}
        }
        if(i==len1 )printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
