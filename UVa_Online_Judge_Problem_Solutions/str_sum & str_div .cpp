#include <cstdio>
#include <cstring>
using namespace std;
void str_sum(char str1[],char str2[],char sum[]);
struct div_mod
{
    int mod;
    char div[50];

};
div_mod str_mod(char ara[], int n)
{
    int i,j,flag=0,temp,div;
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
    if(flag==0){a.div[0]='0';j++;}
    a.div[j]='\0';
    return a;
}

int main()
{
    char str1[50],sum[50];
    int n,f,i;
    div_mod a;
    for(int k=1; scanf("%d %d",&n,&f)!=EOF; k++)
    {
        if(n==0 && f==0)break;
        for(i=0;i<50;i++)sum[i]=0;
        scanf("%s",sum);
        n--;
        while(n--)
        {
            scanf("%s",str1);
            str_sum(str1,sum,sum);

        }
        a=str_mod(sum,f);
        printf("Bill #%d costs %s: each friend should pay %s\n\n",k,sum,a.div);
    }
    return 0;
}
void str_sum(char str1[],char str2[],char sum[])
{
    int i,j=0,len,temp,c=0,flag=0;
    char ch;
    len=strlen(str1);
    for(i=0; i<len/2; i++)
    {
        ch=str1[i];
        str1[i]=str1[len-1-i];
        str1[len-1-i]=ch;
    }
    len=strlen(str2);
    for(i=0; i<len/2; i++)
    {
        ch=str2[i];
        str2[i]=str2[len-1-i];
        str2[len-1-i]=ch;
    }
    for(i=0; str1[i] && str2[i]; i++)
    {
        temp=str1[i]+str2[i]-'0'-'0'+c;
        if(temp>9)
        {
            temp%=10;
            c=1;
        }
        else c=0;
        sum[i]=temp+'0';
    }
    while(str1[i])
    {
        temp=str1[i]-'0'+c;
        if(temp>9)
        {
            temp%=10;
            c=1;
        }
        else c=0;
        sum[i]=temp+'0';
        i++;
    }
    while(str2[i])
    {
        temp=str2[i]-'0'+c;
        if(temp>9)
        {
            temp%=10;
            c=1;
        }
        else c=0;
        sum[i]=temp+'0';
        i++;
    }
    if(c==1)
    {
        sum[i]='1';
        i++;
    }
    sum[i]='\0';
    len=i;
    for(i=0; i<len/2; i++)
    {
        ch=sum[i];
        sum[i]=sum[len-1-i];
        sum[len-1-i]=ch;
    }
    for(i=0; sum[i]; i++)
    {
        if(sum[i]=='0' && flag==0)continue;
        else flag++;
        if(flag==1)j=0;
        sum[j]=sum[i];
        j++;
    }
    if(j==0){sum[0]='0';j++;}
    sum[j]='\0';
}
