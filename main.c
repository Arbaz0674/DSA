#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *s;
};

void initialize(struct stack *q,int length)
{
    q->top=-1;
    q->size=length;
    q->s=(char*)malloc(q->size*sizeof(char));
}

void push(struct stack *q,char a)
{
    if(q->top!=q->size-1)
    {
        q->top++;
        q->s[q->top]=a;
    }
    return;
}

char pop(struct stack *q)
{
    char a;
    if(q->top!=-1)
    {
        a=q->s[q->top];
        q->top--;
    }
    return(a);
}

int isEmpty(struct stack q)
{
    if(q.top==-1)
        return 1;
    else
        return 0;
}

char peek(struct stack q)
{
    if(q.top==-1)
        return(-1);
    else
        return(q.s[q.top]);
}

int precedence(char top_ele)
{
    if(top_ele=='+' || top_ele=='-')
        return 1;
    else if(top_ele=='*'|| top_ele=='/')
        return 2;
    else if(top_ele=='^')
        return 3;
    else
        return 0;
}

int main()
{
    int t,length,i,j;
    char s[100],res[100],discard;
    struct stack st;
    initialize(&st,100);
    printf("Enter no of test cases\n");
    scanf("%d",&t);
    while(t>0)
    {
        i=0,j=0;
        printf("Enter the length of string\n");
        scanf("%d",&length);
        printf("Enter string\n");
        scanf("%s",s);
        while(s[i]!='\0')
        {
            if(s[i]>='A' && s[i]<='Z')
            {
               res[j++]=s[i];
            }
            else if(s[i]=='(')
            {
                push(&st,s[i]);
            }
            else if(s[i]==')')
            {
                while(peek(st)!='(')
                {
                    res[j++]=pop(&st);
                }
                discard=pop(&st);
            }
            else
            {
                while(precedence(peek(st))>=precedence(s[i]))
                {
                    res[j++]=pop(&st);
                }
                push(&st,s[i]);
            }
            i++;
        }
        while(!isEmpty(st))
        {
            res[j++]=pop(&st);
        }
        res[j]='\0';
        printf("%s",res);
        printf("\n");
        t--;
    }
    return 0;
}
