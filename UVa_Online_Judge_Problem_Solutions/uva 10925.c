#include <stdio.h>
#include <inttypes.h>
#include <string.h>

void str_sum(char ara[], char res[]);



int main()
{

    int64_t a,b,mult,rem,temp;
    int n,p;
    int i,j,len,k;
    char ara[40],res[40],ch;

    for(i=1;scanf("%d %d",&n,&p)==2;i++)
    {

        a=0;
        b=0;
        if(n==0 && p==0)break;

        scanf("%s",res);
        n--;
        len=strlen(res);
        for(k=0;k<len/2;k++){ch=res[k];res[k]=res[len-1-k];res[len-1-k]=ch;}
        while(n--)
        {
            scanf("%s",ara);

            str_sum(ara,res);

        }

        len=strlen(res);
        mult=1;

        for(j=len-1;j>12;j--){a=a*10+res[j]-'0';}
        for(;j>=0;j--){b=b*10+res[j]-'0';mult*=10;}

        rem=a%p*mult+b%p;
        rem/=p;

        a=a/p+rem/mult;
        rem=rem%mult+b/p;



        for(k=0;k<len/2;k++){ch=res[k];res[k]=res[len-1-k];res[len-1-k]=ch;}
        printf("Bill #%d costs %s:",i,res);

        temp=rem;j=0;
        while(temp>0){j++;temp/=10;}
        j=13-j;
        printf(" each friend should pay ");
        if(a!=0){printf("%"PRId64"",a);

        while(j--)printf("0");
        }
        if(a==0 && b==0)printf("0");
        if(b!=0)printf("%"PRId64"\n\n",rem);
        else printf("\n\n");
    }
    return 0;
}






void str_sum(char ara[], char res[])
{
    int c=0,sum,flag=0;
    int i=strlen(ara),j;
    for(j=0,i--;i>=0;i--,j++)
    {
        if(res[j]=='\0')flag=1;
        if(!flag)sum=ara[i]-'0'+res[j]-'0'+c;
        else sum=ara[i]- '0'+c;

        if(sum>9){c=1;sum%=10;}
        else c=0;

        res[j]=sum+'0';

    }
    if(!flag){
    while(res[j]!='\0')
    {
        sum=res[j]-'0'+c;
        if(sum>9){c=1;sum=0;}
        else c=0;

        res[j]=sum+'0';
        j++;
    }
    if(c==1){res[j]='1';j++;}
    res[j]='\0';
    }
    else {
    if(c==1){res[j]='1';j++;}
    res[j]='\0';
    }

}
