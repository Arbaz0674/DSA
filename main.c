#include <stdio.h>
#include <stdlib.h>
void Iterative_MergeSort(int a[],int n)
{
    int l,h,mid,p,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            mergee(a,l,mid,h);
        }
    }
    if(p/2<n)
        mergee(a,0,p/2,n-1);
}

void mergee(int a[],int low,int mid,int high)
{
    int *b=(int*)malloc((high+1)*sizeof(int));
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=high)
    {
        b[k++]=a[j++];
    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
    free(b);
    return;
}
int main()
{
    int i,n;
    printf("Enter no of elements");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    Iterative_MergeSort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
