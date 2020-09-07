#include <stdio.h>
#define max_a 100
int top_a=-1,top_b=-1;
int a[100],b[100];

void enqueue(int element)
{
    if(top_a!=max_a-1)
    {
        top_a++;
        a[top_a]=element;
        return;
    }
    else
    {
        printf("Stack is not empty\n");
        return;
    }
}

int dequeue()
{
    int element;
    if(top_a==-1 && top_b==-1)
    {
        printf("Queue is empty");
        return;
    }
    else if(top_b!=-1)
    {
      element=b[top_b];
      top_b--;
      return(element);
    }
    else
    {
        while(top_a!=-1)
        {
            top_b++;
            b[top_b]=a[top_a];
            top_a--;
        }
        element=b[top_b];
        top_b--;
        return(element);
    }
}
int main()
{
    int choice,element;
    do
    {
        printf("1.Enqueue 2.Dequeue 3.Exit\t");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter element\n");
            scanf("%d",&element);
            enqueue(element);
        }
        else if(choice==2)
        {
            element=dequeue();
            printf("Element deleted:%d\n",element);
        }
    }while(choice!=3);
    return 0;
}
