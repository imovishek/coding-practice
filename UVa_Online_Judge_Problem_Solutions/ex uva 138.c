#include<stdio.h>
#include<inttypes.h>
#include<math.h>
int main()
{
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int64_t n=2,c;
    int int_sq,i,mult=6,lst_dig;
    double sq;
    for(i=0;i<10;i++)
    {
        for(;;n++)
        {
            c=(n*n+n)/2;

                int_sq=(int)sqrt(c);

                if((double)int_sq*int_sq==c){
                    lst_dig=int_sq;
                    break;
                }
                else continue;


        }
        printf("%d %"PRId64"\n",lst_dig,n);
        mult*=6;
        n=mult;
    }

    return 0;
}

