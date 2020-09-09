#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int*)malloc((q->size)*sizeof(int));
}

void enqueue(struct queue *q,int element)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=element;
    }
}

int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        return(x);
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
        return(x);
    }
}
int main()
{
    int size,choice,element;
    struct queue q;
    printf("Enter the size of queue\n");
    scanf("%d",&size);
    create(&q,size);
    do
    {
        printf("Enter 1.Enqueue 2.Dequeue 3.Exit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter element\n");
            scanf("%d",&element);
            enqueue(&q,element);
        }
        else if(choice==2)
        {
            element=dequeue(&q);
            if(element==-1)
                printf("Queue is empty\n");
            else
                printf("%d is deleted\n",element);
        }
    }while(choice!=3);
    return 0;
}
