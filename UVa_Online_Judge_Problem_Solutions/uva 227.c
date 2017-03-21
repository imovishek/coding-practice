#include<stdio.h>
#include<string.h>
int main()
{
freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,k,is_sp=0,l=0,is_fin=0,len,is_fi=0,no_conf;
    char ara[5][15],ch,ara2[500000];
    while(gets(ara[0]))
    {
        no_conf=0;
        i=0;j=0;
        is_fin=0;


        len=strlen(ara[0]);
       if(len==1 && ara[0][0]=='Z')break;
       if(is_fi)printf("\n");
       is_fi=1;
       for(i=1;i<5;i++)gets(ara[i]);
       is_sp=0;
       for(i=0;i<5;i++)
       {
           for(j=0;j<5;j++)
           {
                if(ara[i][j]==' ' || ara[i][j]=='\0'){is_sp=1;break;}
           }
           if(is_sp==1)break;
       }

rescan:
       gets(ara2);
       len=strlen(ara2);
       for(k=0;k<len;k++)
       {
           ch=ara2[k];
        if(ch=='0'){is_fin=1; break;}

        if(!no_conf){

           if(ch=='A'){
                if(i-1<0){no_conf=1;continue;}
                ara[i][j]=ara[i-1][j];
                ara[i-1][j]=' ';
                i=i-1;
                }
            else if(ch=='B'){
                if(i+1>4){no_conf=1;continue;}
                ara[i][j]=ara[i+1][j];
                ara[i+1][j]=' ';
                i=i+1;
                }
            else if(ch=='R'){
                if(j+1>4){no_conf=1;continue;}
                ara[i][j]=ara[i][j+1];
                ara[i][j+1]=' ';
                j=j+1;
                }
            else if(ch=='L'){
                if(j-1<0){no_conf=1;continue;}
                ara[i][j]=ara[i][j-1];
                ara[i][j-1]=' ';
                j=j-1;
                }
            else if(ch==' ') continue;
            else   {no_conf=1;}
        }



       }
       if(0==is_fin)goto rescan;

       l++;
    printf("Puzzle #%d:\n",l);
    if(no_conf==1)printf("This puzzle has no final configuration.\n");
    else{
        for(k=0;k<5;k++)printf("%c %c %c %c %c\n",ara[k][0],ara[k][1],ara[k][2],ara[k][3],ara[k][4]);
    }

    }

    return 0;
}
