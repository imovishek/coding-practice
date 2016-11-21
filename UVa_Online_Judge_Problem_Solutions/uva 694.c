#include<stdio.h>
int main()
{
    int a,i,l,count;
    for(i=1;scanf("%d %d",&a,&l)!=EOF;i++)
    {
        count=0;
        if(a<0 && l<0)break;
        printf("Case %d: A = %d, limit = %d",i,a,l);
        if(l%3==0)l=l/3;
        else l=l/3+1;
        while(1)
        {
            if(a==1){count++;break;}
            if(a%2==0)a=a/2;
            else {
                if(a>=l){count++;break;}
                a=3*a+1;
            }
            count++;
        }
        printf(", number of terms = %d\n",count);

    }
    return 0;
}
