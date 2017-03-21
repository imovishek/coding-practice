#include<stdio.h>
#include<inttypes.h>
#include<math.h>
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int64_t n=2,c;
    int int_sq,i,lst_dig;
    double sq;
    for(i=0;i<10;i++)
    {
        for(;;n++)
        {
            c=1+8*n*n;
            if(c>=0)
            {
                sq=sqrt(c);
                int_sq=(int)sq;
                if((double)int_sq*int_sq==c && int_sq%2==1){
                    lst_dig=(int_sq-1)/2;
                    break;
                }
                else continue;
            }
            else continue;

        }
        printf("%"PRId64" %d\n",n,lst_dig);
        n++;
    }

    return 0;
}
