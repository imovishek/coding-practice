#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

void findnext(vector<int> vt[])
{

}

int main()
{
    int n,l,weight;
    while(scanf("%d",n)!=EOF)
    {
        if(n==-9999)continue;
        scanf("%d",&l);
        vector<int> vt[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&weight);
                if(weight==1)vt[i].push_back(j);
            }
    }
    return 0;
}
