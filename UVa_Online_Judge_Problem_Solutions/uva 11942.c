#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);

    int test,i,j,is_ac,a,b,lumprint=0;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        lumprint=0;
        scanf("%d",&b);
     for(j=0;j<9;j++)
     {
         scanf("%d",&a);
         if(b<a && j==0)is_ac=1;
         else if (b>a && j==0)is_ac=0;
         if((is_ac==1 && b>a)||(is_ac==0 && b<a)){if(i==0){printf("Lumberjacks:\n");lumprint=1;}printf("Unordered\n");scanf("%*[^\n]s");break;}
         b=a;

     }
     if(i==0 && lumprint==0)printf("Lumberjacks:\n");
     if(j==9) printf("Ordered\n");
    }

   return 0;
}
