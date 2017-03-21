#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
void rev(string &b)
{
    int len=b.length();
    for(int i=0;i<len/2;i++)
    {
        swap(b[i],b[len-1-i]);
    }
}
void sub(string &b)
{
    int len=b.length();
    if(b[len-1]>'0'){b[len-1]--;return;}
    for(int i=len-1;i>=0;i--)
    {
        if(b[i]>'0'){b[i]--;break;}
        b[i]='6';
    }
}
int main()
{
    int n,m,len1=0,len2=0;
    cin>>n>>m;
    string a,b;
    while(n)
    {
        a+='0'+n%7;
        n/=7;
        len1++;
    }
    rev(a);
    sub(a);
    cout << a << endl;
    while(m)
    {
        b+='0'+m%7;
        m/=7;
        len2++;
    }
    rev(b);
    sub(b);
    cout << b << endl;
    int sum=0;

        int mult=1;
        for(int i=0;i<len1;i++)
        {
            mult*=7-(len2+len1-i-1);
        }
        if(mult!=1)sum+=mult;


         mult=1;
        for(int i=0;i<len2;i++)
        {
            mult*=7-(len2-1-i);
        }
        if(mult!=1)sum+=mult;


//
for(int j=0;j<len1-1;j++){
         mult=1;
        for(int i=j+1;i<len1;i++)
        {
            mult*=7-(len2+len1-i-1);
        }
        if(mult!=1)sum+=mult;
    }
    for(int j=0;j<len2-1;j++){
         mult=1;
        for(int i=j+1;i<len2;i++)
        {
            mult*=7-(len2-1-i);
        }
        if(mult!=1)sum+=mult;
    }
    pf("%d\n",sum);
    return 0;
}
