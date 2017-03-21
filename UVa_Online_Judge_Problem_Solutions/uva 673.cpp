#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
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
stringstream ss;
bool bigflag=1;
bool rec(char chr)
{
    char ch;
    while(ss >> ch){
        if(ch=='(')
            rec(ch);
        else if(ch=='[')
            rec(ch);
        else if(ch==')' && chr=='(')
            return 1;
        else if(ch==')' && chr!='(')
        {
            bigflag=0;
            return 0;
        }
        else if(ch==']' && chr=='[')
            return 1;
        else if(ch==']' && chr!='[')
        {
            bigflag=0;
            return 0;
        }

    }
    if(chr!='0'){
        bigflag=0;
        return 0;
    }
    return bigflag;
}
int main()
{
    string s;
    int t;
    sf1(t);
    getchar();
    while(t--)
    {
        s="";
        char ch;
        while(ss>>ch);
        getline(cin,s);
        ss.clear();
        ss << s;
        bigflag=1;
        if(rec('0'))pf("Yes\n");
        else pf("No\n");

    }
    return 0;
}
/*
3
([])
((([()]))
()([([()[]()])[[([([([()[]()])[[([()[]()])[]()]]()])[]()])[]()]]()])([[([([()[]()])[[([()[]()])[]()]]()])[]()]])[()[]()]

100
(((
))
[(])
[[()]()]
[[()]()]
*/
