#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int ara[17]={2,3,5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int main()
{
    char str[10];
    int flag=0,pos;
    for(int i=0;i<16;i++)
    {
        printf("%d\n",ara[i]);
        fflush(stdout);
        scanf("%s",str);
        if(0==strcmp(str,"yes") )
        {
            flag++;
            pos=i;
        }
    }
    if(flag>1){
            printf("composite\n");
            fflush(stdout);
            return 0;
    }
    if(flag==1 && ara[pos]<10)
    {
        printf("%d\n",ara[pos]*ara[pos]);
        fflush(stdout);
        scanf("%s",str);
        if(0==strcmp(str,"yes") )
        {
            printf("composite\n");
            fflush(stdout);
            return 0;
        }
    }
    printf("prime\n");
    fflush(stdout);
    return 0;
}

