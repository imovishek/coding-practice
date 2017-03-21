#include<stdio.h>
#include<inttypes.h>

int main()
{
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    int64_t x,a,b,count;
while(1)
{   count=0;
    x=0;
    scanf("%"PRId64" %"PRId64"",&a,&b);
    if(a==0 && b==0) break;
    while(1){
        if((a%10+b%10+x)>9) {count=count+1;x=1;}
        else x=0;
        a=a/10;b=b/10;
        if(a==0 || b==0) {
            if(x==1 && (a%10==9 || b%10==9) )count++;
            break;
            }

    }
    if(count==1) printf("1 carry operation.\n");
    else if(count) printf("%"PRId64" carry operations.\n",count);
    else printf("No carry operation.\n");
}

return 0;
}
