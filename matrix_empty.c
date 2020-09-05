#include <stdio.h>
#include <stdlib.h>
struct Matrix
{
    int *row;
    int i;
    int j;
    int *column;
    int size;
    int free_space;
};
void init(struct Matrix *m,int si)
{
   m->i=m->j=0;
   m->size=si;
   m->row=(int*)malloc(m->size*sizeof(int));
   m->column=(int*)malloc(m->size*sizeof(int));
   m->free_space=si*si;
}

void freespace(struct Matrix *m,int row,int column)
{
    if(search(m->row,m->i,row))
    {
        m->free_space=m->free_space-(m->size-m->j);
        m->row[m->i]=row;
        m->i++;
    }
    if(search(m->column,m->j,column))
    {
        m->free_space=m->free_space-(m->size-m->i);
        m->column[m->j]=column;
        m->j++;
    }
}
int search(int a[],int n,int key)
{
    int i=0;
    while(i<=n && n!=0)
    {
        if(a[i]==key)
            return 0;
        i++;
    }

    return 1;
}
int main()
{
    struct Matrix m;
    int row,column,exitt,n;
    printf("Enter size of Matrix\n");
    scanf("%d",&n);
    init(&m,n);
    do
    {
        printf("Enter row and column to Insert X\n");
        scanf("%d%d",&row,&column);
        freespace(&m,row,column);
        printf("Free Space: %d\n",m.free_space);
        printf("Enter 2 to Exit");
        scanf("%d",&exitt);

    }while(exitt!=2);
    return 0;
}
