#include<stdio.h>
int main()
{
    //freopen("input.TXT","r",stdin);

    int test,len,len2,i,alpb[26];
    char ara[1000];

    scanf("%d",&test);
    while(test--)
    {
        for(i=0;i<26;i++)alpb[i]=0;
        scanf("%s",ara);
        len=strlen(ara);
        len2=len;
        for(i=0;i<len;i++)
        {
            alpb[ara[i]-'A']++;
        }
        for(i=0;i<26;i++) {if(alpb[i]%2!=0) len--;}

        if(len2%2!=0)len++;
                            /*if len odd then*/



        printf("%d\n",len);

    }

    return 0;
}
