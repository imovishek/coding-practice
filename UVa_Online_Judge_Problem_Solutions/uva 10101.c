#include<stdio.h>
#include<inttypes.h>
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int64_t num;
    int i,j,rem,sav[20],alert;
    for(i=1;scanf("%"PRId64"",&num)!=EOF;i++)
    {
        if(num/100==0)alert=1;
        else alert=0;
        j=0;
        if(num==0){sav[0]=0;j++;}
        while(num>0)
        {

            if(j%4==1){sav[j]=num%10;num/=10;}
            else {sav[j]=num%100;num/=100;}
            j++;
        }
        j-=2;
        if(i>0 && i<10)printf("   ");
        else if(i>9 && i<100)printf("  ");
        else if(i>99 && i<1000)printf(" ");


        printf("%d. ",i);
        rem=j%4;

            if(sav[j+1]!=0){
            switch(rem)
            {
                case 0:
                printf("%d shata",sav[j+1]);
                break;
                case 1:
                printf("%d hajar",sav[j+1]);
                break;
                case 2:
                printf("%d lakh",sav[j+1]);
                break;
                case 3:
                printf("%d kuti",sav[j+1]);
                break;
                default:
                    break;

            }
            }
            j--;
        while(j>=0)
        {
            rem=j%4;
            if(sav[j+1]!=0){
            switch(rem)
            {
                case 0:
                printf(" %d shata",sav[j+1]);
                break;
                case 1:
                printf(" %d hajar",sav[j+1]);
                break;
                case 2:
                printf(" %d lakh",sav[j+1]);
                break;
                case 3:
                printf(" %d kuti",sav[j+1]);
                break;
                default:
                    break;

            }

            }
            else if(j%4==3)printf(" kuti");
            j--;
        }
        if(sav[0]!=0 && !alert )
        printf(" %d\n",sav[0]);
        else if(alert) printf("%d\n",sav[0]);
        else printf("\n");
    }
    return 0;
}
