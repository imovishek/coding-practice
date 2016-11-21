#include<cstdio>
using namespace std;
bool isvowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
}
bool isconso(char ch){
    return ((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))&&!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
}
bool isalpha(char ch){
    return (ch>='a' && ch<='z')||(ch>='A' && ch<='Z');
    }
char ara[1000007],isw=0,ch;
int main()
{

    while(gets(ara))
    {
        isw=0;
        for(int i=0;ara[i];i++)
        {
            if(ara[i]==' '){isw=0;printf(" ");continue;}
            if(!isalpha(ara[i])){printf("%c",ara[i]);continue;}
            if(!isw && isvowel(ara[i]))
            {
                while(ara[i]!=' ' && ara[i] && isalpha(ara[i]))
                {
                    printf("%c",ara[i]);
                    i++;
                }
                i--;
                printf("ay");
            }
            else if(!isw && isconso(ara[i])&&isalpha(ara[i]))
            {
                ch=ara[i++];
                while(ara[i]!=' ' && ara[i] && isalpha(ara[i]))
                {
                    printf("%c",ara[i]);
                    i++;
                }
                i--;
                printf("%c",ch);
                printf("ay");
            }


        }
        printf("\n");

    }
    return 0;
}
