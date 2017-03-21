#include<stdio.h>
struct data
{
    int num;
    int age;
    data(int a,int b){num=a;age=b;}
//    void operator=(data b)
//    {
//        num=b.num;
//    }
};
int main()
{
    data a(6,12),c(8,16);
    a=c;
    printf("%d %d\n",a.num,a.age);
    return 0;
}
