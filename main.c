#include <stdio.h>
#include <stdlib.h>
void insert_heap(int a[],int n)
{
    int i=n,x=a[n],j=i/2;
    while(i>1 && x>a[i/2])
    {
       a[i]=a[i/2];
       i=i/2;
    }
    a[i]=x;
}

void delete_heap(int a[],int n)
{
    int x,i=1,j,temp;
    x=a[1];
    a[i]=a[n];
    j=i*2;
    while(j<n-1)
    {
        if(a[j+1]>a[j])
            j=j+1;

        if(a[j]>a[i])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=j*2;
        }
        else
            break;
    }
    a[n]=x;
}
int main()
{
    int i,n,a[100];
    a[0]=-1;
    printf("Enter elements in an Array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=2;i<=n;i++)
    {
        insert_heap(a,i);
    }
    printf("After Insert In Heap: ");
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=n;i>1;i--)
    {
        delete_heap(a,i);
    }
    printf("After Delete In Heap: ");
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
