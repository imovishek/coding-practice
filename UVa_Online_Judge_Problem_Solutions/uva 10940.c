#include<stdio.h>
int main()
{

    int n,add,reslt,len;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        if(n==1){printf("1\n");continue;}
        len=n/2;
        add=4;
        if(n%2==1)reslt=2;
        else {reslt=4;len--;}
        while(len>1)
        {
            if(len%2==1){
                len--;
                reslt+=add;
            }
            add*=2;
            len/=2;
        }
        printf("%d\n",reslt);
    }
    return 0;
}
