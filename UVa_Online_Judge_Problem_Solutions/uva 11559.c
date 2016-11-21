#include<stdio.h>
int main()
{

    int n,b,h,w,hc,wc,temp,cost=0,dkte_hb=0,tmcost;
    while(scanf("%d %d %d %d",&n,&b,&h,&w)==4)
    {

        tmcost=0;
        cost=0;
        while(h--)
        {
            scanf("%d",&hc);
            tmcost=n*hc;
            if(tmcost<=b){
            temp=w;

            while(temp--)
            {
                scanf("%d",&wc);
                if( cost==0 && wc>=n){cost=tmcost;scanf("%*[^\n]s");break;}
                if( wc>=n && cost>tmcost){cost=tmcost;scanf("%*[^\n]s");break;}
            }
            }
            else {
                scanf("%d",&wc);
                scanf("%*[^\n]s");

            }
        }
        if(cost)printf("%d\n",cost);
        else printf("stay home\n");
    }
    return 0;
}
