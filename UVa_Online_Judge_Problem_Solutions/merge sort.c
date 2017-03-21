#include<stdio.h>
#include<limits.h>
void merge(int ara[],int p,int q,int r);
void m_s(int ara[],int p,int q);
int main()
{
int i,ara[100];
for(i=0;i<100;i++)ara[i]=100-i;
for(i=0;i<100;i++)printf("%d ",ara[i]);printf("\n");
m_s(ara,0,99);printf("\n");
for(i=0;i<100;i++)printf("%d ",ara[i]);
return 0;
}
void m_s(int ara[],int p,int q)
{

    if(p<q)
    {
        int r=(p+q)/2;
        m_s(ara,p,r);
        m_s(ara,r+1,q);
        merge(ara,p,q,r);
    }
}
void merge(int ara[],int p,int q,int r)
{
    int n1=r-p+1,n2=q-r;
    int L[n1+1],R[n2+1];
    int i,j,k;
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    for(i=0;i<n1;i++)L[i]=ara[p+i];
    for(j=0;j<n2;j++)R[j]=ara[r+j+1];
    i=0,j=0;

    for(k=p;k<=q;k++)
    {
        if(L[i]<=R[j])
        {
            ara[k]=L[i];
            i++;
        }
        else {ara[k]=R[j];j++;}
    }

}
