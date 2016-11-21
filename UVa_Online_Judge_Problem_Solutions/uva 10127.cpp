#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct div_mod
{
    int mod;
    char div[10100];

};
div_mod str_mod(char ara[], int n);
int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,j;
    div_mod b;
    char str[10000];


    while(scanf("%d",&n)!=EOF)
    {
        memset(str,0,sizeof(str));
        for(j=0;j<10000;j++){
        str[j]='1';
        b=str_mod(str,n);
        if(b.mod==0){printf("%d\n",j+1);break;}
        }

    }
    return 0;
}

div_mod str_mod(char ara[], int n)
{
    int i,j,flag=0,temp,div;
    div_mod a;
    a.mod=0;
    for(i=0,j=0;ara[i]; i++)
    {
        temp=((a.mod*10)+ara[i]-'0');
        div=temp/n;
        if(!flag && div)flag=1;
        if(flag)
        {
            a.div[j]=div+'0';
            j++;
        }
        a.mod=temp%n;
    }
    if(j==0){a.div[j]='0';j++;}
    a.div[j]=0;
    return a;
}
