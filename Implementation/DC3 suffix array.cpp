/*input
yeshowmuchiloveyoumydearmotherreallyicannotbelieveit
yeaphowmuchiloveyoumydearmother

*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 200005
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
#define ws ww
#define rank rnk
int wa[N],wb[N],wv[N],ws[N];
int rank[N],height[N];    
int sa[3*N],r[3*N];
char c[N];
int Max(int a,int b)
{
    return a>b?a:b;
} 
int Min(int a,int b)
{
    return a<b?a:b;
}
int cmp(int *y,int a,int b,int l)
{
    return y[a]==y[b]&&y[a+l]==y[b+l];   
}

int c0(int *y,int a,int b)
{
    return y[a]==y[b]&&y[a+1]==y[b+1]&&y[a+2]==y[b+2];
}
int c12(int k,int *y,int a,int b)
{
    if(k==2) return y[a]<y[b]||y[a]==y[b]&&c12(1,y,a+1,b+1);
    else return y[a]<y[b]||y[a]==y[b]&&wv[a+1]<wv[b+1];
}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0;i<n;i++) wv[i]=r[a[i]];
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[wv[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
    return;
}
void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else for(i=0;i<tbc;i++) san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0;i<ta && j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
    return;
}
void get_height(int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return; 
}
char a[N], b[N];
int main()
{
	scanf("%s %s", a, b);
    int len1 = strlen(a);
    strcat(a, "#");
    strcat(a, b);
    int len2 = strlen(a);
    for(int i = 0; i<=len2; i++)
        r[i] = a[i];
    dc3(r, sa, len2+1, 256);
    get_height(len2);
    int ans = 0;
    for(int i = 2; i<=len2; i++)
    {
        if((sa[i-1] < len1 && sa[i] > len1) || (sa[i-1] > len1 && sa[i] < len1))
            ans = max(ans, height[i]);
    }
    printf("%d\n", ans);
	return 0;
}