#include<stdio.h>
#include<string.h>

int main()
{

    char ara[100];
    int i,len,length[35],flag=0;
    memset(length,0,sizeof(length));
    while(gets(ara))
    {


            if(ara[0]=='#')
            {
                for(i=1; i<35; i++)
                    if(length[i]!=0)
                        printf("%d %d\n",i,length[i]);
                printf("\n");flag=0;
                memset(length,0,sizeof(length));
                continue;
            }
            if(!flag)len=0;
            for(i=0;ara[i]; i++)
            {
                if(flag)flag=0;
                if(isalpha(ara[i]))len++;
                else if(ara[i]=='.' || ara[i]=='?' || ara[i]=='!' || ara[i]==',' || ara[i]==' ')
                {
                    length[len]++;
                    len=0;
                }
                else if(ara[i]=='-' && ara[i+1]==0)flag=1;

            }
            if(!flag)length[len]++;

    }
    return 0;
}
