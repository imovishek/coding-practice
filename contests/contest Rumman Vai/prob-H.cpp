#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
vector<int>result;
int diflag[20]={};
int l,flag=0,siz;
void findnext(vector<int> vt[], int start)
{
    if(result.size()==l+1){
            flag=1;
            siz=result.size();
            if(siz==1){
                    if(vt[0][0]==0)printf("(1)\n");
                    else flag=0;

                    return;
            }
        printf("(%d",result[0]+1);
        for(int i=1;i<siz-1;i++)
        {
            printf(",%d",result[i]+1);

        }
        printf(",%d)\n",result[siz-1]+1);
        return;
    }
    for(int i=0; i<vt[start].size(); i++)
    {
        if(diflag[vt[start][i]]==0)
        {
            result.push_back(vt[start][i]);
            diflag[vt[start][i]]=1;
            findnext(vt,vt[start][i]);
            diflag[vt[start][i]]=0;
            result.pop_back();
        }
    }
}

int main()
{
    int n,weight;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-9999){printf("\n");continue;}

        scanf("%d",&l);
        vector<int> vt[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                scanf("%d",&weight);
                if(weight==1)vt[i].push_back(j);
            }
        }
//printf("\n");
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++)
//            {
//                printf("%d ",ara[i][j]);
//            }
//            printf("\n");
//        }
        diflag[0]=1;
        result.clear();
        result.push_back(0);

        findnext(vt,0);
        if(flag==0)printf("no walk of length %d\n",l);
        flag=0;
        for(int i=0;i<20;i++)
            diflag[i]=0;
        for(int i=0;i<n;i++)
            vt[i].clear();

    }
    return 0;
}
/*
5 2
0 1 0 1 0
1 0 1 0 0
0 1 0 1 1
1 0 1 0 1
0 0 1 1 0

*/
