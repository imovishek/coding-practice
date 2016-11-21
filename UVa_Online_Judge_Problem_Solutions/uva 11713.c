#include<stdio.h>
#include<math.h>
#include<string.h>
int isvowel(char ch)
{
    if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u')return 1;
    return 0;
}
int main()
{

    int n,i;
    char str1[30],str2[30];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s %s",str1,str2);
        if(strlen(str1)==strlen(str2))
        {
            for(i=0; str1[i]; i++)
            {
                if(!isvowel(str1[i]))
                {
                    if(str1[i]!=str2[i])
                    {
                        printf("No");
                        break;
                    }
                }
                else if(!isvowel(str2[i]))
                {
                    printf("No");
                    break;
                }
            }
            if(str1[i]==0)printf("Yes");
        }
        else printf("No");
        printf("\n");
    }

    return 0;
}

