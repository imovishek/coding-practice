#include<stdio.h>
#define sf scanf
#define pf printf
bool isLeap(int y)
{
    return y%400==0 || (y%4==0 && y%100!=0);
}
int counti(int y1 , int y2)
{
    return isLeap(y1) - (y1/4 - y1/100 + y1/400 )+ (y2/4 - y2/100 + y2/400);
}
int main()
{
    int y1, m1, d1;
    int y, m, d , ara[]={0,31,31,31,31,31,30,30,30,30,30,30,30};
    int t;
    sf("%d %d %d",&y1,&m1,&d1);
    sf("%d",&t);
    while(t--)
    {
        sf("%d %d %d",&y,&m,&d);
        int day=0,leaps;
        y1--;
        y++;
        leaps=counti(y, y1);
        int aleap=y1-y+1-leaps;
        y--;
        y1++;
        if(aleap>=0)
            day=leaps*366+aleap*365;
        day+=((m==11)? (isLeap(y)?31:30) : ara[m])-d+d1;
        int flag=0;
        int i;
        for(i=m+1;i<=12;i++)
        {
            if(i==m1 && y1==y){flag=1;break;}
            if(i==11 && isLeap(y))day++;
            day+=ara[i];
        }

        if(!flag){
            for(i=1; i<=12 && i!=m1; i++){
                if(i==11 && isLeap(y1))day++;
                day+=ara[i];
            }

        }
        pf("%d\n",day);


    }
}
