#include<bits/stdc++.h>
#define sc scanf
#define pf printf
using namespace std;

int main()
{
int t,p=1,n;
sc("%d",&t);
while(t--)
{
sc("%d",&n);
pf("Case %d:\n",p++);
int k=1,i,j;
if(n>=3)
{
if(k==1)
{
for(i=1;i<=7;i++) pf(" ");
pf("%d %d ",n,n);
pf(" %d %d ",n,n-1);
for(i=2;n-i>=2;i++)
{
pf(" %d ",n);
pf("%d %d",n-i,i);
}
pf(" %d %d %d\n",n,i,n);
k++;
}
if(k==2)
{
pf("(a + b) = a + C a b");
for(i=1;i<=n-3;i++)
{
pf(" + C a b ");
}
pf(" + C ab + b\n");
k++;
}
if(k==3)
{
for(i=1;i<=18;i++) pf(" ");
pf("1");
pf(" ");
for(i=2;i<=n-2;i++)
{
pf("%d",i);
for(j=1;j<=9;j++) pf(" ");
}
pf("%d\n",n-1);
}
}
else if(n==1) pf("\n(a + b) = a + b\n");
else if(n==2)
{
for(i=1;i<=7;i++) pf(" ");
pf("2 2 2 2\n");
pf("(a + b) = a + C ab + b\n");
for(i=1;i<=18;i++) pf(" ");
pf("1\n");
}
}
return 0;
}
