#include<stdio.h>
void in_s(int ara[],int p,int q);
void in_s(int ara[],int p,int q)
{
    int j,k,key;
    for(j=p+1;j<=q;j++)
    {
        key=ara[j];
        for(k=0;j-k-1>=0;k++){
        if(ara[j-k-1]>key){

        ara[j-k]=ara[j-k-1];

        }

        else {break;}
        }
        ara[j-k]=key;


    }
}
int main()
{
    int i,ara[]={10,12,45,125,9,39,7,41,59,5,87,13,3,47,23,1};
    for(i=0;i<16;i++)printf("%d ",ara[i]);printf("\n");
    in_s(ara,0,15);
    for(i=0;i<16;i++)printf("%d ",ara[i]);printf("\n");
    return 0;
}
