#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,is_start=0,is_end=1,line,length;
scanf("%d",&line);
char ch[100];
int num[line+1];
for(i=0;i<=line;i++)
{
    num[i]=0;
    gets(ch);
    if(i){
       length=strlen(ch);
       for(j=0;j<length;j++)
       {
           if(is_start==0&&ch[j]!=' '){is_start=1; num[i]++;}
           else if(is_start==1 && (ch[j]==' '||ch[j]=='\0')) {is_start=0;}

       }
is_start=0;
    }


}
for(i=1;i<=line;i++)
{
 printf("%d ",num[i]);
}
return 0;
}
