#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
int main()
{
    int num,choice=1,m,n;
    do
    {   if(choice==1)
       {
        printf("Enter numbers in linked list.\n");
        scanf("%d",&num);
        insert(num);
       }
        else if(choice==2)
        {
            printf("Enter the nodes to retain and node to delete");
            scanf("%d%d",&m,&n);
            retain(m,n);
        }
        else
        {
            display();
        }

             printf("1.Add\t 2.Delete\t 3.Display\t 0.Exit\n");
             scanf("%d",&choice);
    }while(choice!=0);
}

void insert(int num)
{
  struct Node *node=(struct Node *)malloc(sizeof(struct Node));
  struct Node *temp=head;
  node->data=num;
  node->next=NULL;
  if(head==NULL)
  {
      head=node;
      return;
  }
  while(temp->next!=NULL)
  {
      temp=temp->next;
  }
   temp->next=node;
   return;
}

void display()
{
    struct Node *temp=head;
    if(temp==NULL)
    {
      printf("There are no nodes in linked list\n");
      return;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    return;
}

void retain(int m,int n)
{
    int i,j;
    struct Node *temp=head;
    struct Node *prev=NULL;

    while(temp!=NULL)
    {
        for(i=1;i<=m;i++)
        {
            if(temp==NULL)
            {
                return;
            }
            else
            {
            prev=temp;
            temp=temp->next;
            }
        }

       /* if(temp==NULL)
            return;*/

        for(j=1;j<=n;j++)
        {
            if(temp==NULL)
            {
                return;
            }
            else
            {
            prev->next=temp->next;
            free(temp);
            temp=prev->next;
            }
        }
    }
}
