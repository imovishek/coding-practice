#include<stdio.h>
#include<limits.h>
void multi(int ara3[],int ara2[],int mult[]);
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int m,len,ara2[110],ara3[110],mult[110],root,start;
    char ara[110];
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",ara);
        len=strlen(ara);
        if(len/n<2)j=2;
        else {j=1; start=len/n;
        for(i=1;i<start;i++)j*=10;}
        for(;j<=INT_MAX;j++){
        for(i=1;i<110;i++){ara2[i]=INT_MIN;mult[i]=INT_MIN;ara3[i]=INT_MIN;}
        ara2[0]=j,mult[0]=0,ara3[0]=j;m=n;m--;printf("%d\n",j);
        while(m--){
            multi(ara3,ara2,mult);
            for(i=0;i<110;i++){ara2[i]=mult[i];mult[i]=INT_MIN;}

            for(i=109;i>=0;i--)if(ara2[i]!=INT_MIN){printf("%d",ara2[i]);}
            printf("\n");
        }
        for(i=0;i<len;i++){if(ara2[i]!=ara[len-1-i]-'0')break;}
        if(i==len){root=j;break;}
        /*for(i=109;i>=0;i--)if(ara2[i]!=INT_MIN){printf("%d",ara2[i]);}
        printf("\n");*/
        }
        printf("%d\n",root);

    }
    return 0;
}

void multi(int ara3[],int ara2[],int mult[])
{
    int i,j,k,dig;
    for(i=0;ara2[i]!=INT_MIN;i++)
    {
        for(j=0;ara3[j]!=INT_MIN;j++)
        {
            if(mult[i+j]==INT_MIN)mult[i+j]=0;
            k=1;
            dig=mult[i+j]+ara2[i]*ara3[j];
            mult[i+j]=dig%10;
                dig/=10;
            while(dig>0)
            {if(mult[i+j+k]==INT_MIN)mult[i+j+k]=0;
                mult[i+j+k]+=dig%10;
                dig/=10;
                k++;
            }

        }


    }

}
