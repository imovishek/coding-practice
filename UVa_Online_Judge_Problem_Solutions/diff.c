#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

int main()
{
    char ara1[1000],ara2[1000],flag=0,i=1;
    int x,y;
    FILE *ac,*get;
    ac=fopen("acoutput.txt","r");
    get=fopen("output.txt","r");
    while(1)
    {
        x=fgets(ara2,sizeof(ara2),ac);
        y=fgets(ara1,sizeof(ara1),get);
        if(!(x || y))break;

        if(strcmp(ara1,ara2)!=0)
        {
            if(x==0){ara2[0]='e';ara2[2]=0;ara2[1]='\n';}
            if(y==0){ara1[0]='e';ara1[2]=0;ara1[1]='\n';}
            if(ara1[0]=='\n'){ara1[0]='n';ara1[1]='e';ara1[2]='w';ara1[3]='l';ara1[4]='i';ara1[5]='n';ara1[6]='e';ara1[7]=0;}
            if(ara2[0]=='\n'){ara2[0]='n';ara2[1]='e';ara2[2]='w';ara2[3]='l';ara2[4]='i';ara2[5]='n';ara2[6]='e';ara2[7]=0;}
            if(flag==0){printf("Ac Output\nYour outputs are:\n");flag=1;}
            printf("on %dth line:\n%s%s\n",i,ara2,ara1);

        }
        i++;
    }
    if(flag==0)printf("Ooops! Outputs are identical!!!!!!!!\n");
    fclose(ac);
    fclose(get);
    getch();
    return 0;
}
