#include<stdio.h>
#include<string.h>
int main()
{

    int i,len,num,is_start;
    char ara[1001];
    while(scanf("%s",ara)!=EOF)
    {
        len=strlen(ara);
        if(len==1 && ara[0]=='0')break;
        num=0;
        is_start=0;
        for(i=0;i<len;)
        {
            if(is_start==0 && ara[i]=='0'){i++;continue;}
            is_start=1;
            if(num==0 && i!=len-1) {num=(ara[i]-'0')*10+(ara[i+1]-'0');num=num%11;i+=2;}
            else {num=num*10+(ara[i]-'0');num=num%11;i++;}

        }
        if(num==0)printf("%s is a multiple of 11.\n",ara);
        else printf("%s is not a multiple of 11.\n",ara);
    }
    return 0;

}
