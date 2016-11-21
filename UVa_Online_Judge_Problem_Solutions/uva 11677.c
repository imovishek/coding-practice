#include<stdio.h>
int main()
{

    int h1,m1,h2,m2;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2)!=EOF)
    {

        if(h1==0 && m1==0 && h2==0 && m2==0 )break;
        if(m2<m1){m2+=60;h2--;}
        h2=h2-h1;
        m2=m2-m1;
        if(h2<0)h2+=24;

        m2=h2*60+m2;
        printf("%d\n",m2);

    }
    return 0;
}
