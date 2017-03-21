#include<stdio.h>
#include<string.h>
#include<math.h>
void str_mult(char ara1[],char ara2[],char res[])
{
    char ch,max=0;
    int i,k,len1,len2,j,mult,c=0;
    len1=strlen(ara1);
    for(i=0;i<len1/2;i++)
    {
        ch=ara1[i];
        ara1[i]=ara1[len1-1-i];
        ara1[len1-1-i]=ch;
    }
    len2=strlen(ara2);
    for(i=0;i<len2/2;i++)
    {
        ch=ara2[i];
        ara2[i]=ara2[len2-1-i];
        ara2[len2-1-i]=ch;
    }
    for(i=0;i<len1;i++)
    for(j=0; j<len2; j++)
    {
        mult=(ara1[i]-'0')*(ara2[j]-'0')+(res[i+j]-'0')+c;
        if(mult>9)
        {
            c=mult/10;
            mult%=10;
        }
        else c=0;
        res[i+j]=mult+'0';
        if(max<i+j)max=i+j;
        for(k=1; c>0; k++)
        {
            mult=(res[i+j+k]-'0')+c;
            if(mult>9)
            {
                c=mult/10;
                mult%=10;
            }
            else c=0;
            res[i+j+k]=mult+'0';
            if(max<i+j+k)max=i+j+k;
        }
    }
    res[max+1]=0;
    len2=strlen(res);
    for(i=0;i<len2/2;i++)
    {
        ch=res[i];
        res[i]=res[len2-1-i];
        res[len2-1-i]=ch;
    }
    int flag=0;
    for(i=0,j=0;res[i];i++)
    {
        if(flag==0 && res[i]=='0')continue;
        else flag=1;
        if(flag)res[j++]=res[i];
    }
    res[j]=0;
    if(j==0){res[0]='0';res[1]=0;}

}

int main()
{

    char ara1[300],ara2[300],res[510];
    int i;

    while(scanf("%s %s",ara1,ara2)!=EOF)
    {
        for(i=0;i<510;i++)res[i]='0';
        str_mult(ara1,ara2,res);
        puts(res);

    }
    return 0;
}
