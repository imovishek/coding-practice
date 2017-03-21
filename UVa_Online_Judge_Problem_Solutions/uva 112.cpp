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
int bigflag=0,want;
int sflag=0;
bool is_num(char ch)
{
    return ch>='0' && ch<='9';
}
void rec(int sum)
{
    int num=0;
//    for(int i=0;i<2;i++)
    {
        int isneg=0;
        char ch;
        int gflag=0;
        while(sf(" %c",&ch))
        {
            if(is_num(ch)){
                num=num*10+ch-'0';
                sflag++;
            }
            else if(ch=='('){
                sflag=0;
                if(isneg)num=-num;
                rec(sum+num);
                if(sflag==0 && gflag==1 &&  sum+num==want )bigflag=1;
//                if (sflag==0 && gflag==1)pf("%d*\n",sum+num);
                if(sflag==0)gflag++;
                isneg=0;
                sflag++;
            }
            else if (ch==')')
            {
                return;
            }
            else if(ch=='-')isneg=1;
        }
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(sf1(want)!=EOF)
    {
//        pf("%d***\n",want);
        bigflag=0;
        char ch;
        int st;
        sf(" %c",&ch);
        sf1(st);
        rec(st);
        if(bigflag) pf("yes\n");
        else pf("no\n");
    }
    return 0;
}
/*

22 (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
67 (5(2(1()(3()()))(7(5(6()())(1()()))()))(3()(2(41(4()(7(3()(2()()))()))())())))
-238 (-87 (-86 (-91 (-57 (60 ( )
() )(74 ()(
) ))(26 ()()
)) (32 (-43 (58  ()() )(-23 ( ) ()))()))(
))

*/
