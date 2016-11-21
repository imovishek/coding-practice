#include<stdio.h>
int main()
{
    char ara[1000][1000];
    int i,flag=0,s=1,j,k,l;
    for(i=0;scanf("%s",ara[i])!=EOF;i++)
    {
        if(ara[i][0]=='9')
        {
            for(j=0;j<i;j++)
            {
                for(k=j+1; k<i ; k++)
                {
                    for(l=0;ara[j][l] && ara[k][l];l++)
                    {
                        if(ara[j][l]==ara[k][l]){
                            if(ara[j][l+1]==0 || ara[k][l+1]==0){
                                flag=1;

                                break;
                            }
                        }
                        else break;


                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            if(flag)printf("Set %d is not immediately decodable\n",s++);
            else printf("Set %d is immediately decodable\n",s++);
            flag=0;
            i=-1;
        }
    }
    return 0;
}
