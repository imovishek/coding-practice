#include<stdio.h>
int main()
{
    char ara[]="1234567890-=",ara2[]="QWERTYUIOP[]\\",ara3[]="ASDFGHJKL;'",
    ara4[]="ZXCVBNM,./",ina[1000000];
    int i,j,got_that=0;
    while(gets(ina))
    {
        for(i=0;ina[i]!='\0';i++)
        {
            got_that=0;
            for(j=0;ara[j]!='\0';j++)if(ina[i]==ara[j]){ina[i]=ara[j-1];got_that=1;break;}if(got_that)continue;
            for(j=0;ara2[j]!='\0';j++)if(ina[i]==ara2[j]){ina[i]=ara2[j-1];got_that=1;break;}if(got_that)continue;
            for(j=0;ara3[j]!='\0';j++)if(ina[i]==ara3[j]){ina[i]=ara3[j-1];got_that=1;break;}if(got_that)continue;
            for(j=0;ara4[j]!='\0';j++)if(ina[i]==ara4[j]){ina[i]=ara4[j-1];got_that=1;break;}if(got_that)continue;

        }
        puts(ina);
    }


    return 0;
}
