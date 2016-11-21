#include<stdio.h>
int main()
{
int n,m,x,y,test,x1,y1;
while(scanf("%d",&test))
{
    if(test==0)break;
    scanf("%d %d",&n,&m);
    while(test--)
    {
        scanf("%d %d",&x,&y);
        x1=x-n;
        y1=y-m;
        if(x1==0 || y1==0) printf("divisa\n");
        else if(x1>0 && y1>0) printf("NE\n");
        else if(x1<0 && y1>0) printf("NO\n");
        else if(x1<0 && y1<0) printf("SO\n");
        else  printf("SE\n");
    }
}
return 0;
}
