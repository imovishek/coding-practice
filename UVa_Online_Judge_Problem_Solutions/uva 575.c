#include<stdio.h>
#include<string.h>
int main()
{
    char ara[35];
    while(scanf("%s",ara)!=EOF)
    {
        int i,len=strlen(ara),mult=1,sum=0;
        if(len==1 && ara[0]=='0')break;
        for(i=len-1;i>=0;i--)
        {
            mult=mult<<1;
            sum+=(ara[i]-'0')*(mult-1);
        }
        printf("%d\n",sum);
    }
    return 0;
}
