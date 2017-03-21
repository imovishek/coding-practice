#include<stdio.h>
#include<string.h>
void str_mult(char ara1[],char ara2[],char res[]);
void str_sum(char str1[],char str2[],char sum[]);
int main()
{

    char ara1[1000],sign[3],ara2[1000],mult[1000],len1,len2,len3;
    int len[3],i,j;
    while(gets(ara1))
    {
        puts (ara1);
        sscanf(ara1,"%s %s %s",ara1,sign,ara2);
        int flag=0;
        for(i=0,j=0; ara1[i]; i++)
        {
            if(flag==0 && ara1[i]=='0')continue;
            else flag=1;
            if(flag)ara1[j++]=ara1[i];
        }
        ara1[j]=0;

        flag=0;
        for(i=0,j=0; ara2[i]; i++)
        {
            if(flag==0 && ara2[i]=='0')continue;
            else flag=1;
            if(flag)ara2[j++]=ara2[i];
        }
        ara2[j]=0;
        int flag1=0,flag2=0,flag3=0;
        len1=strlen(ara1);
        if(len1>10)flag1=1;
        else if(len1==10)
        {
            if(1==strcmp(ara1,"2147483647"))flag1=1;
        }
        len2=strlen(ara2);
        if(len2>10)flag2=1;
        else if(len2==10)
        {
            if(strcmp(ara2,"2147483647")==1)flag2=1;
        }


            for(i=0; i<20; i++)mult[i]='0';
            if(sign[0]=='*' || sign[1]=='*')str_mult(ara1,ara2,mult);
            else str_sum(ara1,ara2,mult);
            puts(mult);
            len3=strlen(mult);
            if(len3>10)flag3=1;
            else if(len3==10)
            {
                if(strcmp(mult,"2147483647")==1)flag3=1;
            }



        if(flag1==0 && flag2==0 && flag3==0);
        else
        {

            if(flag1)printf("first number too big\n");
            if(flag2)printf("second number too big\n");
            if(flag3)printf("result too big\n");
        }
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
    if(str1[i])
    {
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
    }
    else
    {
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
    if(j==0)
    {
        sum[0]='0';
        j++;
    }
    sum[j]='\0';

}
void str_mult(char ara1[],char ara2[],char res[])
{
    char ch,max=0;
    int i,k,len1,len2,j,mult,c=0;
    len1=strlen(ara1);
    for(i=0; i<len1/2; i++)
    {
        ch=ara1[i];
        ara1[i]=ara1[len1-1-i];
        ara1[len1-1-i]=ch;
    }
    len2=strlen(ara2);
    for(i=0; i<len2/2; i++)
    {
        ch=ara2[i];
        ara2[i]=ara2[len2-1-i];
        ara2[len2-1-i]=ch;
    }
    for(i=0; i<len1; i++)
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
    for(i=0; i<len2/2; i++)
    {
        ch=res[i];
        res[i]=res[len2-1-i];
        res[len2-1-i]=ch;
    }
    int flag=0;
    for(i=0,j=0; res[i]; i++)
    {
        if(flag==0 && res[i]=='0')continue;
        else flag=1;
        if(flag)res[j++]=res[i];
    }
    res[j]=0;
    if(j==0)
    {
        res[0]='0';
        res[1]=0;
    }


}
