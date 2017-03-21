#include<stdio.h>
#include<limits.h>
void merge(int ara[],int p,int q,int r);
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
int b_s(int ara[],int n,int i, int j)
{
    int mid=(i+j)/2;
    while(i<=j)
    {
        mid=(i+j)/2;
        if(ara[mid]==n)break;
        else if(ara[mid]>n)j=mid-1;
        else if(ara[mid]<n)i=mid+1;
    }

     if(i>j) return 0;
     else return 1;

}


int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int sub1,sub2,i,j,k,l,is_fin,max;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        l=-1;
        max=INT_MIN;
        if(n==0)break;
        int ara[n];
        is_fin=0;
        for(i=0;i<n;i++)scanf("%d",&ara[i]);
        m_s(ara,0,n-1);
        for(i=n-1;i>=0;i--)if(ara[i]<0){l=i;break;}
        printf("\n%d",l);
        for(i=n-1;i>2;i--)
        {
            for(j=i-1;j>1;j--){
                sub1=ara[i]-ara[j];
                //printf("\n%d",sub1);
            for(k=j-1;k>0;k--){
            sub2=sub1-ara[k];
            //printf("\n%d*\n",sub2);
            if(b_s(ara,sub2,0,n-1)){is_fin=1;break;}

            }
            if(is_fin==1)break;
            }
            if(is_fin==1)break;
        }
        if(is_fin)printf("%d\n",ara[i]);
        else if(l!=-1) {//printf("no solution\n");

             for(i=0;i<l-2;i++)
        {
            for(j=i+1;i<l-1;j++){
                sub1=ara[i]-ara[j];
                //printf("\n%d",sub1);
            for(k=j+1;i<l;k++){
            sub2=sub1-ara[k];
            //printf("\n%d*\n",sub2);
            if(b_s(ara,sub2,k+1,l)){if(ara[i]>max)max=ara[i];}

            }

            }

        }
        if(max!=INT_MIN)printf("%d\n",ara[i]);
        else printf("no solution\n");
        }
        else printf("no solution\n");

    }
    return 0;
}

