#include<stdio.h>
#include<string.h>
#define sf scanf
#define pf printf

int main()
{
    int t,ara[10];
    char a[15],b[15];
    sf("%d",&t);
    while(t--)
    {
        for(int i=0;i<10;i++)ara[i]=0;
        sf("%s %s",&a, &b);
        for(int i=0;a[i];i++){
                for(int j=0;b[j];j++)
                    if(a[i]==b[j])ara[a[i]-'0']=1;
        }
        int counti=0;
        for(int i=0;i<10;i++) if(ara[i]){pf("%d",i);counti++;}
        if(!counti)pf("N");
        pf("\n");
    }
    return 0;
}




