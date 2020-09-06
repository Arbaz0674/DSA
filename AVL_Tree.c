#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
};
struct Node *root=NULL;

struct Node* RR_Rotation(struct Node *p)
{
   struct Node *pr=p->rchild;
   struct Node *prl=pr->lchild;
   pr->lchild=p;
   p->rchild=prl;
   p->height=Node_Height(p);
   pr->height=Node_Height(pr);

   if(root==p)
     root=pr;

   return(pr);
}

struct Node* LL_Rotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=Node_Height(p);
    pl->height=Node_Height(pl);

    if(root==p)
        root=pl;

    return(pl);
}
struct Node* LR_Rotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;

    p->height=Node_Height(p);
    pl->height=Node_Height(pl);
    plr->height=Node_Height(plr);
    if(root==p)
        root=plr;

    return(plr);
}
struct Node *RL_Rotation(struct Node *p)
{
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;
    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->lchild=p;
    prl->rchild=pr;

    p->height=Node_Height(p);
    pr->height=Node_Height(pr);
    prl->height=Node_Height(prl);

    if(root==p)
        root=prl;

    return(prl);
}
struct Node* insert(struct Node *p,int key)
{
    struct Node *t;
    if(p==NULL)
    {
       t=(struct Node*)malloc(sizeof(struct Node));
       t->data=key;
       t->height=1;
       t->lchild=t->rchild=NULL;
       return(t);
    }
    if(key<p->data)
        p->lchild=insert(p->lchild,key);
    else if(key>p->data)
        p->rchild=insert(p->rchild,key);

    p->height=Node_Height(p);
    //Checking Balance Factor
    if(balance_factor(p)==2 && balance_factor(p->lchild)==1)
        return(LL_Rotation(p));
    else if(balance_factor(p)==2 && balance_factor(p->lchild)==-1)
        return(LR_Rotation(p));
    else if(balance_factor(p)==-2 && balance_factor(p->rchild)==1)
        return(RL_Rotation(p));
    else if(balance_factor(p)==-2 && balance_factor(p->rchild)==-1)
          return(RR_Rotation(p));

    return(p);
}

int balance_factor(struct Node *p)
{
    int lh,rh;
    lh=p->lchild!=NULL?p->lchild->height:0;
    rh=p->rchild!=NULL?p->rchild->height:0;
    return(lh-rh);
}
int Node_Height(struct Node *p)
{
    int lh,rh;
    lh=p->lchild!=NULL?p->lchild->height:0;
    rh=p->rchild!=NULL?p->rchild->height:0;
    return(lh>rh?lh+1:rh+1);
}

void display(struct Node *root)
{
   if(root!=NULL)
   {
       display(root->lchild);
       printf("Element:%d Height:%d\t",root->data,root->height);
       printf("Balance_Factor:%d\n",balance_factor(root));
       display(root->rchild);
   }

}
int main()
{
    int element,n;
    do
    {
        printf("Enter Element\n");
        scanf("%d",&element);
        root=insert(root,element);
        printf("Enter 2 to Exit a loop\n");
        scanf("%d",&n);
    }while(n!=2);
    display(root);
    return 0;
}
