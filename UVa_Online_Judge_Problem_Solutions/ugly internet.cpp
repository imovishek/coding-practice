#include<stdio.h>
int main()
{
    const int n=1499;
    int p2=0,p3=0,p5=0,ugn[1500],last=0;
    ugn[0]=1;
    while(last<n)
    {
        while(ugn[p2]*2<=ugn[last])p2++;
        while(ugn[p3]*3<=ugn[last])p3++;
        while(ugn[p5]*5<=ugn[last])p5++;
        if(ugn[p2]*2<ugn[p3]*3 && ugn[p2]*2<ugn[p5]*5)
            ugn[++last]=ugn[p2++]*2;
        else if(ugn[p3]*3<ugn[p5]*5)
            ugn[++last]=ugn[p3++]*3;
        else ugn[++last]=ugn[p5++]*5;
        }
        printf("The 1500'th ugly number is %d.\n",ugn[n]);
    return 0;
}
