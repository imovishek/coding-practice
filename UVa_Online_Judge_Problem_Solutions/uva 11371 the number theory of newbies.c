#include<stdio.h>
#include<string.h>
void str_sub(char high[],char low[],char str[]);

int str_mod(char ara[], int n)
{
    int i,j,temp,mod,div,wdiv=0;
    for(i=0,j=0; ara[i]; i++)
    {
        temp=((mod*10)+ara[i]-'0');
        div=temp/n;
        wdiv=wdiv*10+div;
        mod=temp%n;
    }
    return wdiv;
}

int main()
{
    char str[20],high[20],low[20],max,high2[20];
    int i,j,len,k,wdiv;
    while(scanf("%s",str)!=EOF)
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            max=str[0];
            k=0;
            for(j=1;j<len;j++)
            {
                if(max<str[j]){max=str[j];k=j;}
            }
            high[i]=max;
            str[k]='0';
        }
        high[i]='\0';
        for(;i>=0;i--)high2[i]=high[i];
        for(i=0;i<len;i++){low[len-1-i]=high[i];}
        low[i]='\0';
        str_sub(high2,low,str);
        wdiv=str_mod(str,9);
        printf("%s - %s = %s = 9 * %d\n",high,low,str,wdiv);


    }
    return 0;
}

void str_sub(char high[],char low[],char str[])
{
    int i,sub,len;
    len=strlen(high);
    for(i=len-1;i>=0;i--)
    {
        sub=high[i]-low[i];
        if(sub<0){sub+=10;high[i-1]--;}
        str[i]=sub+'0';
    }

}
