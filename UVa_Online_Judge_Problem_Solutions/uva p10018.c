#include<stdio.h>
#include<inttypes.h>
int is_palindrome(int64_t n)

{
  int64_t m,x=0;
  m=n;
  for(;m!=0;)
  {
      x=x*10+(m%10);
      m=(m-(m%10))/10;
  }
  if(x==n) return 1;
  return 0;

}
int64_t rearrange(int64_t n)
{
    int64_t m,x=0;
  m=n;
  for(;m!=0;)
  {
      x=x*10+(m%10);
      m=(m-(m%10))/10;
  }
  return x;
}



int main()
{
    int64_t n;
    int i,j=0,ntest,x;
    scanf("%d",&ntest);
    for(i=0;i<ntest;i++)
    {
        scanf("%"PRId64"",&n);
        while(1){
        x=rearrange(n);
        n=n+x;
        j++;
        if(is_palindrome(n)) break;

        }
        printf("%d %"PRId64"\n",j,n);
        j=0;
        n=0;

    }
   return 0;
}
