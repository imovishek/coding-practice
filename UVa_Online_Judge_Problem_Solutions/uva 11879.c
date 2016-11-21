#include<stdio.h>
void strsub(char ara[], int n, int len)
{
    int sub[3];
    sscanf(sub,"%d",n);

}
int isMultipleOfSeventeen(char ara[],int len)
{
    int rem;
    if(len<2)
    {
        rem=(ara[len-1]-'0')%17;
        if(rem==0)return 1;
        return 0;
    }
    else
    {
        printf("%d\n",n);
        int k=ara[len-1]-'0';
        ara[len-1]=0;
        strsub(ara, k*5, len);

        return isMultipleOfSeventeen(n/10-(n%10)*5);
    }

}

int main()
{
    int num=2098765413,num2=132597382;
    char ara[1000];
    while(scanf("%s",ara))
    printf("%d\n",isMultipleOfSeventeen(ara,strlen(ara)));
}
