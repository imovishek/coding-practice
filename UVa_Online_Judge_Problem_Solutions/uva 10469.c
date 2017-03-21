#include<stdio.h>
int main()
{

    char ara1[50],ara2[50];
    int a,b,i=0,j=0;
    while(scanf("%d %d",&a,&b)==2)
    {
        for(i=0;i<50;i++){ara1[i]='0';ara2[i]='0';}
        i=0;j=0;
        for(i=0;a>0;i++)
        {
            ara1[i]='0'+a%2;
            a/=2;
        }
        ara1[i]='\0';
        for(j=0;b>0;j++)
        {
            ara2[j]='0'+b%2;
            b/=2;
        }
        ara2[j]='\0';

        if(i>j){a=i;i=j;j=a;}
        for(i=0;i<j;i++)
        {
            if(ara1[i]=='1' && ara2[i]=='1')ara1[i]='0';
            else if (ara1[i]=='0' && ara2[i]=='1')ara1[i]='1';
            else if (ara1[i]=='1' && ara2[i]=='0')ara1[i]='1';
            else if (ara1[i]=='0' && ara2[i]=='0')ara1[i]='0';
            else if(a!=j)ara1[i]=ara2[i];
        }
        ara1[j]='\0';
        b=1;
        a=0;
        for(i=0;i<j;i++)
        {
            a=a+(ara1[i]-'0')*b;
            b=b*2;
        }
        printf("%d\n",a);
    }


    return 0;
}
