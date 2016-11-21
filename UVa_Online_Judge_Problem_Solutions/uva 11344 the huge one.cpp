#include<stdio.h>
int str_mod(char ara[], int n);


int main()
{
    int t,n,i,flag=0,num;
    char str[1010];

    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%s %d",str, &n);

        for(i=0; i<n; i++)
        {
            scanf("%d",&num);
            if(str_mod(str,num)) flag=1;
        }
        if(!flag)printf("%s - Wonderful.\n",str);
        else printf("%s - Simple.\n",str);

    }
    return 0;
}

int str_mod(char ara[], int n)
{
    int i,mod=0;
    for(i=0; ara[i]; i++)
    {
        mod=((mod*10)+ara[i]-'0')%n;
    }
    return mod;
}
