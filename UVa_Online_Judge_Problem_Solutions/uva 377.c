#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,n,num1[10],num2[10],num,c=0,len2,len;
    char ara[10],ara2[6];
    scanf("%d",&n);
    printf("COWCULATIONS OUTPUT\n");
    while(n--)
    {
        c=0;
        scanf("%s %s",ara,ara2);
        num1[0]=0;num2[0]=0;
        for(i=1;i<6;i++)
        {
            if(ara[i-1]=='V')num=0;
            else if(ara[i-1]=='U')num=1;
            else if(ara[i-1]=='C')num=2;
            else if(ara[i-1]=='D')num=3;
            num1[i]=num;
        }
        for(i=1;i<6;i++)
        {
            if(ara2[i-1]=='V')num=0;
            else if(ara2[i-1]=='U')num=1;
            else if(ara2[i-1]=='C')num=2;
            else if(ara2[i-1]=='D')num=3;
            num2[i]=num;
        }
        len2=5;
        for(j=0;j<3;j++){
        scanf("%s",ara);
        if(ara[0]=='A'){
        for(i=5,len=len2;i>=0;i--,len--)
        {
            num=num1[i]+num2[len]+c;
            if(num>3){num=num%4;c=1;}
            else c=0;
            num2[len]=num;
        }
        }
        else if(ara[0]=='L') num2[++len2]=0;
        else if(ara[0]=='R') {
                for(len=len2;len>0;len--)
                num2[len]=num2[len-1];
                num2[0]=0;
        }

        }
        scanf("%s",ara);
        j=0;
        int is_s=0;
        for(j=0;num2[j]==0;j++);
         for(i=1;i<9;i++)
        {
            if(ara[i-1]=='V')num=0;
            else if(ara[i-1]=='U')num=1;
            else if(ara[i-1]=='C')num=2;
            else if(ara[i-1]=='D')num=3;
            if(num==0 && is_s==0)continue;
            is_s=1;
            if(num2[j]!=num) break;
            j++;
        }
        if(i==9)printf("YES\n");
        else printf("NO\n");

    }
    printf("END OF OUTPUT");
    return 0;
}
