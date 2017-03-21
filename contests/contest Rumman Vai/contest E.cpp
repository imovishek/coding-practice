#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdlib>
#include<cstdio>
using namespace std;
vector <int > flag;
//int flag[8]= {-1,-1,-1,-1,-1,-1,-1,-1};
vector< vector<int> > vt;
bool is_legal(int a, int b)
{
    int i;
    if(flag[a]!=-1){return 0;}

    for(i=0; i<8; i++)
        if(flag[i]!=-1 && (flag[i]==b || abs(flag[i]-b)==abs(i-a))){/*printf(":p *\n");*/return 0;}

//    if(a>b){
//            a=a^b;
//            b=a^b;
//            a=a^b;
//    }
//    b-=a; a=0;
//    for(;a<b && a<8 && b<8;a++,b++)
//        if(flag[a]==b)return 0;


    return 1;

}

void fillchess(int a)
{

    for(int i=0; i<8; i++)
    {
        if(is_legal(a,i))
        {
            flag[a]=i;
            if(a==7)
            {
//                printf("got that\n");
//                for(int l=0; l<8; l++)
//                {
//                    for(int j=0; j<8; j++)
//                    {
//                        if(flag[l]==j)
//                            printf("* ");
//                        else printf("0 ");
//                    }
//                    printf("\n");
//                }
//                printf("\n\n***\n\n");

                vt.push_back(flag);
                flag[a]=-1;
                return;
            }
//            printf("%d %d: flag[a]=%d\n",a,i,flag[a]);
            else {
                fillchess(a+1);
                flag[a]=-1;
            }
        }
    }
}
int main()
{
    for(int i=0;i<8;i++)flag.push_back(-1);
    //freopen("output.txt","w",stdout);
    fillchess(0);
    int t;
    printf("%d\n",vt.size());
    scanf("%d",&t);
    int ara[8][8],sum,maxi=0;
    while(t--)
    {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            scanf("%d",&ara[i][j]);
            maxi=0;
        for(int i=0;i<92;i++)
        {
            sum=0;
            for(int j=0;j<8;j++)
            {
                sum+=ara[j][vt[i][j]];
            }
            if(maxi<sum)maxi=sum;
        }
        printf("%5d\n",maxi);
    }
    return 0;
}
