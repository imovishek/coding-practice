#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ara[1000],ch;
    int i,j,start,end,is_fin=0;
    while(1)
    {
        for(i=0;i<1000;i++)ara[i]='\0';
        for(i=0;;i++){

            if(scanf("%c",&ch)==EOF){ is_fin=1;break;}
            if(ch=='\n') {ara[i]='\0';break;}
            else ara[i]=ch;

        }

        for(i=0;;i++)
        {
            if(ara[i]==' ')continue;
            for(end=i;;){end++;if(ara[end]==' ' || ara[end]=='\0'){end--;break;}}
           start=i;i=end;
            for(j=0;start+j<=(start+end)/2;j++){
                ch=ara[start+j];
                ara[start+j]=ara[end-j];
                ara[end-j]=ch;
                if(start+j==end-j)break;
            }
            if(ara[end]=='\0')break;
        }
        if(is_fin==0)
        puts(ara);
        else printf("%s",ara);
        if(is_fin==1)return 0;
    }
    return 0;
}
