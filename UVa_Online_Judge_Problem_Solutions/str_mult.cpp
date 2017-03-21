#include <cstdio>
#include <cstring>
using namespace std;
void str_multi(char str1[],char str2[],char mult[]);

int main()
{
    char str1[100],str2[100],mult[100];
    while(scanf("%s %s",str1,str2)!=EOF)
    {
        for(int i=0;i<100;i++)mult[i]='0';
        str_multi(str1,str2,mult);
        puts(mult);
    }
    return 0;
}

void str_multi(char str1[],char str2[],char mult[])
{
    int i,j=0,len1,len2,temp,c=0,flag=0,k;
    char ch;
    len1=strlen(str1);
    for(i=0; i<len1/2; i++)
    {
        ch=str1[i];
        str1[i]=str1[len1-1-i];
        str1[len1-1-i]=ch;
    }
    //puts(str1);
    len2=strlen(str2);
    for(i=0; i<len2/2; i++)
    {
        ch=str2[i];
        str2[i]=str2[len2-1-i];
        str2[len2-1-i]=ch;
    }
    //puts(str2);
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            temp=(str1[i]-'0')*(str2[j]-'0')+mult[i+j]-'0';
            //printf("%d\n",temp);
            k=i+j;
            while(temp>9){
                    c=temp/10;temp%=10;
                    mult[k]=temp+'0';
                    k++;
                    temp=mult[k]-'0'+c;
            }
            mult[k]=temp+'0';

        }
    }
    int len=k+1;
    mult[len]='\0';
    for(i=0; i<len/2; i++)
    {
        ch=mult[i];
        mult[i]=mult[len-1-i];
        mult[len-1-i]=ch;
    }
    for(i=0; mult[i]; i++)
    {
        if(mult[i]=='0' && flag==0)continue;
        else flag++;
        if(flag==1)j=0;
        mult[j]=mult[i];
        j++;
    }
    if(j==0){mult[0]='0';j++;}
    mult[j]='\0';


}
