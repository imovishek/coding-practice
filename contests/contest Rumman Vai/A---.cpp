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
vector<int>vt,flag;
vector< vector<int> >vtall;
int n,a,maxi=0;
int getmaxirel(int check,int counti,int maxall[])
{
    if(check<0){
            if(maxi<(counti-1))maxi=counti-1;
            return counti-1;
    }
//    if(maxall[check]!=0)
//    {
////        for(int i=0;i<=n;i++)
////            printf("%d\n",maxall[i]);
//        if(maxi<maxall[check]+counti)maxi=maxall[check]+counti;
//        return maxall[check]+counti;
//    }

    int siz=vtall[check].size();

    if(flag[check]==0)
    {
        int smax=0;
        for(int j=0,a; j<siz; j++)
        {
            flag[check]=1;
            a=getmaxirel(vtall[check][j],counti+1,maxall)-counti;
            if(a>smax)smax=a;
            flag[check]=0;

        }
        maxall[check]=smax;
    }
    else if(maxi<counti){maxi=counti;return counti;}

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int x,y;
    while(scanf("%d %d",&n,&a)!=EOF && !(n==0 && a==0))
    {
        int maxall[n];
        for(int i=0; i<=n; i++)
        {
            vtall.push_back(vt);
            flag.push_back(0);
            maxall[i]=0;
        }
        for(int i=0; i<a; i++)
        {
            scanf("%d %d",&x,&y);
            vtall[x].push_back(y);

        }
//        for(int i=0;i<=n;i++)
//        {
//            printf("%d: ",i);
//            for(int j=0;j<vtall[i].size();j++)
//                printf("%d ",vtall[i][j]);
//            printf("\n");
//        }
        for(int i=1;i<=n;i++)
            getmaxirel(i,0,maxall);
        for(int i=1;i<=n;i++)
            if(vtall[i].size()==0)maxi++;
        printf("%d\n",maxi);
        maxi=0;
//        for(int i=1;i<=n;i++)
            vtall.clear();

    }
    return 0;
}

/*
4 5
1 2
1 -4
2 -3
3 1
3 4
1 1
1 -1
3 3
1 2
2 3
3 -1

*/
