#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define sf scanf
#define db double
typedef long long int LL;
int main()
{
while(1){
    LL num=0;
    pf("%d\n",~(-8)+1);
    int i,len,dig;
    char ara[100];
    scanf("%s",ara);
    for(len=0;ara[len];len++)
    {

        if(ara[len]>='0' && ara[len]<='9')dig=ara[len]-'0';
        else if(ara[len]>='A' && ara[len]<='Z')dig=ara[len]-'A'+10;
        else if(ara[len]>='a' && ara[len]<='z')dig=ara[len]-'a'+36;
        else if(ara[len]=='-')dig=62;
        else if(ara[len]=='_')dig=63;
        num=num*64+dig;


    }
    printf("%I64d\n",num);
}
    return 0;
}
