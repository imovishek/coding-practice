#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<inttypes.h>
int p,q,r,s,t,u;
double x,flag=0,current=0;
double solvei(double a, double b)
{
    x=(a+b)/2;
    double res;
    for( x=0;x<=1;x+=.00001)
    {
    res=p*exp(-x)+q* sin(x)+r* cos(x)+ s* tan(x)+ t* x*x + u;
    printf("%lf %lf*\n",x,res);
    if(res>0 && res<=0.0001)return 1;
    }
    flag=1;
    return 0;
//    printf("%lf %lf*\n",x,res);
//    if(x==1 || x==0){flag=1;return 0;}
//    if(res>0 && res<=0.0000001)return 1;
//    if(res>0)return solve(x,b);
//    return solve(a,x);

}
double cal(double xi)
{
    return p*exp(-xi)+q* sin(xi)+r* cos(xi)+ s* tan(xi)+ t* xi*xi + u;
}
int sign=0;
int check(double murgi)
{
    if((murgi>=0 && murgi<=0.00001)||(murgi<=0 && murgi>=-0.00001))return 1;
    return 0;
}
double solve(double a, double b)
{
    x=(a+b)/2;
    double res,last=current;
    res=p*exp(-x)+q* sin(x)+r* cos(x)+ s* tan(x)+ t* x*x + u;
    //printf("%.9lf %.9lf*\n",x,res);
    current=res;
    if(res>0 && res<=0.0000001)return 1;
//    if((x<=1 && x>=.99999)|| (x>=0 && x<=.000001)){flag=1;return 0;}
if(x==1 || x==0){flag=1;return 0;}
if(sign){
    if(res>0)return solve(a,x);
    return  solve(x,b);
}
else{
    if(res>0)return solve(x,b);
    return solve(a,x);
}

}
int main()
{
    //freopen("output.txt","w",stdout);
    //printf("%.10lf*\n",cal(0.374381781));
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF){
            if(cal(1)-cal(0)>1)sign=1;
    else sign=0;
        solve(0,1);

        if((p==0 && q==0 && r==0 && s==0 && t==0 && u==0 ) || check(cal(0)))printf("0.0000\n");
        else if(check(cal(1.0000)))printf("1.0000\n");
        else if(flag)puts("No solution");
        else printf("%.4lf\n",x);
        flag=0;
    }
    return 0;

}
