#include<stdio.h>

struct div_mod
{
    long long int mod;
    char div[1010];

};
div_mod str_mod(char ara[], int n);
int main()
{
    int n;
    div_mod b;
    char str[1010],sign[5];


    while(scanf("%s %s %d",str,sign, &n)!=EOF)
    {

        //printf("%d\n",n);
        b=str_mod(str,n);
        if(sign[0]=='%')printf("%lld\n",b.mod);
        else printf("%s\n",b.div);

    }
    return 0;
}

div_mod str_mod(char ara[], int n)
{
    int i,j,flag=0,div;
    long long int temp;
    div_mod a;
    a.mod=0;
    for(i=0,j=0; ara[i]; i++)
    {
        temp=((a.mod*10)+ara[i]-'0');
        div=temp/n;
        if(!flag && div)flag=1;
        if(flag)
        {
            a.div[j]=div+'0';
            j++;
        }
        a.mod=temp%n;
    }
    a.div[j]=0;
    return a;
}
