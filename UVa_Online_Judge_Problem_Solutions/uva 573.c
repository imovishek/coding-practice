#include<stdio.h>
int main()
{

    int hwall,dup,nfall,factor,inh,dcount,flag;

    while(scanf("%d %d %d %d",&hwall,&dup,&nfall,&factor))
    {
        if(hwall==0)break;
        factor=dup*factor;
        flag=0;
        dcount=0;
        hwall*=100;
        dup*=100;
        nfall*=100;
        inh=0;
        while(1)
        {
            /*printf("%d %d %d %d\n",inh,inh+dup,inh+dup-nfall,dup-factor);*/
            dcount++;
            inh+=dup;
            if(inh>hwall){/*printf("broked 1 :p\n");*/break;}
            inh-=nfall;
            if(inh<0){/*printf("broked 2 :p\n");*/flag=1;break;}
            dup-=factor;
            if(dup<0){/*printf("broked 3 :p\n");dcount++;flag=1;break;*/dup=0;}
        }
        if(flag)printf("failure on day %d\n",dcount);
        else printf("success on day %d\n",dcount);


    }
    return 0;
}
