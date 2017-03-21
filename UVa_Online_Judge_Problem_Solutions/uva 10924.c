#include<stdio.h>
#include<math.h>
#include<string.h>
int is_prime(int n)
{
    int i,nsq;
    if(n==1)return 1;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    else{nsq=sqrt(n);
        for(i=3;i<=nsq;i+=2){
                if(n%i==0)return 0;
                }
    }
    return 1;
}
int main()
{freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    int sum,i,len;
    char ara[21];
    while(scanf("%s",ara)!=EOF)
    {

        sum=0;
        len=strlen(ara);
        for(i=0;i<len;i++)
        {
            if(ara[i]>='A' && ara[i]<='Z')sum=sum+ara[i]-'A'+27;
            else if(ara[i]>='a' && ara[i]<='z')sum=sum+ara[i]-'a'+1;
        }

        if(is_prime(sum))printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");

    }
    return 0;
}
