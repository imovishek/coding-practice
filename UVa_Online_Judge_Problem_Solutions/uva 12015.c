#include<stdio.h>
int main()
{

    char ara[100][100],temp[100];
    int t,i,j,k,l,relv,max;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        max=0;
        for(j=0;j<10;j++){
            scanf("%s %d",temp,&relv);
            if(relv>max){max=relv;k=0;l=-1;
            do{l++;ara[k][l]=temp[l];
            }while(temp[l]!='\0');
            }
            else if(relv==max){l=-1;k++;
            do{l++;ara[k][l]=temp[l];
            }while(temp[l]!='\0');

            }
            else continue;

        }
        printf("Case #%d:\n",i);
        for(j=0;j<=k;j++)
            puts(ara[j]);
    }
    return 0;
}
