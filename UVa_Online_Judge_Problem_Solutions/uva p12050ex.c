#include<stdio.h>
#include<string.h>

int is_palindrome(char ara[])
{
    int i,len;
    len=strlen(ara);
    for(i=0;i<len/2;i++)
    {
        if(ara[i]!=ara[len-i]) return 0;
    }
    return 1;
}
void main()
{
    int i,j;
    char ara[30]={'0'};

    for(i=0;;i++)
    {
        if(ara[0]!='9') ara[i]++;
        else {

        }
    }
}
