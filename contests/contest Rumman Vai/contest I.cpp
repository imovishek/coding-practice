#include<cstdio>
#include<vector>
using namespace std;
vector <int > vt;
vector < vector <int> > allvt;
vector < int > diff;
int m,n;
void addnew(int ara[], int pos, int sum)
{
    if(pos==n)return;
    for(; pos<n; pos++)
    {
        sum+=ara[pos];
        vt.push_back(ara[pos]);
        if(sum>m){
            sum-=ara[pos];
            if(!vt.empty())vt.pop_back();
            allvt.push_back(vt);
            diff.push_back(m-sum);
            continue;
        }
        if(sum==m)
        {
            allvt.push_back(vt);
            diff.push_back(0);
        }
        else if(sum<m && pos==n-1)
        {
            allvt.push_back(vt);
            diff.push_back(m-sum);
        }
        else if(sum<m)
        {
            addnew(ara, pos+1, sum);
        }
        if(!vt.empty())vt.pop_back();
        sum-=ara[pos];


    }

}

int main()
{
    while(scanf("%d %d",&m,&n)==2)
    {
        int ara[n];
        for(int i=0;i<n;i++)
            scanf("%d",&ara[i]);
        addnew(ara,0,0);
        int mini=2147483647,k,j;
        for(j=0;j<diff.size();j++)
        {
            if(diff[j]<mini){mini=diff[j];k=j;}
//            for(int l=0;l<allvt[j].size();l++)
//                printf("%d ",allvt[j][l]);
//            printf("\n");
        }
        for(j=0; j<allvt[k].size()-1;j++)
            printf("%d ",allvt[k][j]);
        printf("%d sum:%d\n",allvt[k][j],m-mini);
        allvt.clear();
        diff.clear();
    }
    return 0;
}
