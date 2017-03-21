#include<bits/stdc++.h>
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
using namespace std;
void strsum(char sum[], char ara[])
{
    int c = 0,i;
    for( i = 0; ara[i] ; i++)
    {
        if(sum[i] == 0) sum[i] = '0';
        int temp = sum[i] + ara[i] + c - 2 * '0';
        sum[i] = temp%10 + '0';
        c = temp/10;

    }
    while(c)
    {
        if(sum[i] == 0) sum[i] = '0';
        int temp = sum[i]  + c - '0';
        sum[i] = temp%10 + '0';
        c = temp/10;
        i++;
    }
}
int main()
{
    char sum[507], ara[107];
    mem(sum, 0);
    sum[0] = '0';
    while(gets(ara))
    {
        if(ara[0]=='0' && ara[1]==0) break;
        int i = 0,j;
        for(i = 0; ara[i]; i++)
            if(ara[i]!='0') break;
        for(j = 0; ara[i] ; i++, j++)
            ara[j] = ara[i];
        ara[j] = 0;
        int len = strlen(ara);
        for(i = 0; i<len/2 ; i++)
            swap(ara[i], ara[len-1-i]);
        strsum(sum, ara);
    }
    int len = strlen(sum);
        for(int i = 0; i<len/2 ; i++)
            swap(sum[i], sum[len-1-i]);
    puts(sum);
    return 0;
}
