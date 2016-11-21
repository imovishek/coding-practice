#include<stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ara[25];
    int len,i,k,is_pali,is_mirr;
while(scanf("%s",ara)!=EOF)
{
    is_pali=1;
    is_mirr=1;
    len=strlen(ara);
    for(i=0;i<len/2;i++)
    {
        if(ara[i]!=ara[len-1-i]){is_pali=0;break;}
    }
    k=0;
    k=(len/2);

    if(len%2==1)if((ara[k]!='A' && ara[k]!='H' && ara[k]!='I'
                   && ara[k]!='M' && ara[k]!='O' && ara[k]!='0'
                   && ara[k]!='T' && ara[k]!='U'
                   && ara[k]!='V' && ara[k]!='W'
                   && ara[k]!='X' && ara[k]!='Y' && ara[k]!='8'
                   && ara[k]!='1') ){is_mirr=0;goto retry ;}
    for(i=0;i<len/2;i++)
    {
        if(!((ara[i]=='L' && ara[len-1-i]=='J')||
           (ara[i]=='E' && ara[len-1-i]=='3')||
           (ara[i]=='J' && ara[len-1-i]=='L')||
           (ara[i]=='S' && ara[len-1-i]=='2')||
           (ara[i]=='Z' && ara[len-1-i]=='5')||
           (ara[i]=='2' && ara[len-1-i]=='S')||
           (ara[i]=='3' && ara[len-1-i]=='E')||
           (ara[i]=='5' && ara[len-1-i]=='Z')||
           (ara[i]=='0' && ara[len-1-i]=='O')||
           (ara[i]=='O' && ara[len-1-i]=='0')||
           (ara[i]==ara[len-1-i]) && ara[i]=='A'||
           (ara[i]==ara[len-1-i]) && ara[i]=='H'||
           (ara[i]==ara[len-1-i]) && ara[i]=='I'||
           (ara[i]==ara[len-1-i]) && ara[i]=='M'||
           (ara[i]==ara[len-1-i]) && ara[i]=='O'||
           (ara[i]==ara[len-1-i]) && ara[i]=='0'||
           (ara[i]==ara[len-1-i]) && ara[i]=='T'||
           (ara[i]==ara[len-1-i]) && ara[i]=='U'||
           (ara[i]==ara[len-1-i]) && ara[i]=='V'||
           (ara[i]==ara[len-1-i]) && ara[i]=='W'||
           (ara[i]==ara[len-1-i]) && ara[i]=='X'||
           (ara[i]==ara[len-1-i]) && ara[i]=='Y'||
           (ara[i]==ara[len-1-i]) && ara[i]=='1'||
           (ara[i]==ara[len-1-i]) && ara[i]=='8')){is_mirr=0;break;}

    }
retry:
    if(is_pali==0 && is_mirr==0)printf("%s -- is not a palindrome.\n\n",ara);
else if(is_pali==1 && is_mirr==0)printf("%s -- is a regular palindrome.\n\n",ara);
else if(is_pali==0 && is_mirr==1)printf("%s -- is a mirrored string.\n\n",ara);
else if(is_pali==1 && is_mirr==1)printf("%s -- is a mirrored palindrome.\n\n",ara);

}

return 0;
}
