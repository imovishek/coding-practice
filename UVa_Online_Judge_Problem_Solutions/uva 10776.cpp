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
char ara[35];
int l,flag[35]= {0};
vector<char>res;
//map <vector<char>, int> mp;
void addArrange()
{
    int siz=res.size();
    if(siz==l)
    {
//        if(mp.find(res)==mp.end())
//        {
//            mp[res]=1;
            for(int i=0; i<l; i++)
            {
                printf("%c",res[i]);
            }
            printf("\n");
//        }
        return;
    }
    char current=0;
    for(int i=0; ara[i]; i++)
    {
        if(flag[i]==0 && (res.empty() || res[siz-1]<=ara[i]) && current!=ara[i])
        {
            current=ara[i];
            flag[i]=1;
            res.push_back(ara[i]);
            addArrange();
            res.pop_back();
            flag[i]=0;
        }
    }
}
int main()
{
//for(int i=0;i<35;i++)flag.push_back(0);
    while(scanf("%s %d",ara,&l)!=EOF)
    {
//        printf("%s\n\n",ara);
//        for(int i=0;i<35;i++)printf("%d ",flag[i]);
        int len=strlen(ara);
        sort(ara,ara+len);
        addArrange();
//        mp.clear();
    }
    return 0;
}
