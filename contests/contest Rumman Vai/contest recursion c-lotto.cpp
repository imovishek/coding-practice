#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> res;

void addArrange(int n, int flag[], int ara[])
{
    if(res.size()==6)
    {
        for(int i=0; i<5; i++)
            printf("%d ",res[i]);
        printf("%d\n",res[5]);
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(flag[i]==0)
        {
            if(!res.empty() && res.back()>ara[i])continue;
            res.push_back(ara[i]);
            flag[i]=1;
            addArrange(n,flag,ara);
            flag[i]=0;
            res.pop_back();

        }
    }
}


int main()
{
    int n,j=0;
vector<char>vt;
vt.push_back('A');
vt.push_back('B');
string a;
a=vt;
cout << a <<endl;
//    while(scanf("%d",&n)!=EOF && n!=0)
//    {
//        if(j)printf("\n");
//        j=1;
//        int ara[n],flag[n]={0};
//        for(int i=0; i<n; i++)
//            scanf("%d",&ara[i]);
//        addArrange( n,  flag,ara);
//    }
    return 0;
}
