#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
typedef long long int lint;
int main()
{
    int n,m,i,flag=0,j,c,k,t=1;;
    while(scanf("%d %d",&n,&m) && (n || m))
    {
        if(flag)printf("\n");
        flag=1;
        char ara[n][m+1];
        for(i=0;i<n;i++)
            scanf("%s",ara[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ara[i][j]=='*')
                {
                    for(c=-1;c<2;c++)
                    {
                        for(k=-1;k<2;k++)
                        {
                            if(c==0 && k==0)continue;
                            if(i+c<n && i+c>-1 && j+k<m && j+k>-1)
                            {

                                if(ara[i+c][j+k]=='.')ara[i+c][j+k]='1';
                                else if(ara[i+c][j+k]!='*') ara[i+c][j+k]++;
                            }
                        }

                    }
                }
                else if(ara[i][j]=='.')ara[i][j]='0';
            }
        }
        printf("Field #%d:\n",t++);
        for(i=0;i<n;i++)
            printf("%s\n",ara[i]);




    }
    return 0;
}
