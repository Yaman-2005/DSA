#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next,*prev;
}node;
node* cn(int x)
{
    node* head=(node*)malloc(sizeof(node));
    head->data=x;
    head->next=NULL;
    head->prev=NULL;
    return head;
}
int count(node *head)
{
    node *t=head; int c=0;
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}
void display(node *head)
{
    node *t=head;
    while(t)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}
node *ib(node *head,int x)
{
    node *t=cn(x);
    t->next=head;
    if(head)
        head->prev=t;
    head=t;
    return head;
}
node *ie(node *head,int x)
{
    node *a=cn(x);
    if(!head) return a;
    node *t=head;
    while(t->next)
        t=t->next;
    t->next=a;
    a->prev=t;
    return head;
}
node *ig(node *head,int x)
{
    if(!head){
        printf("List is empty\n");
        return head;
    }
    printf("Enter pos : ");
    int c;
    scanf("%d",&c);
    if(c>count(head)||c<0)
    {
        printf("Invalid pos,couldnt insert\n");
        return head;
    }
    if(c==0){
        head=ib(head,x);
        return head;
    }
    c--;
    node *t=head;
    while(c--)
        t=t->next;
    node *a=cn(x);
    a->next=t->next;
    if(a->next)
        a->next->prev=a;
    a->prev=t;
    t->next=a;
    return head;
}
node *id(node *head,int x)
{
    printf("Enter data after which you want to insert : "); int q;
    scanf("%d",&q);
    node *t=head;
    while(t&&t->data!=q)
        t=t->next;
    if(!t)
    {
        printf("Data not found\n");
        return head;
    }
    node *a=cn(x);
    a->next=t->next;
    if(a->next)
        a->next->prev=a;
    a->prev=t;
    t->next=a;
    return head;
}
node *delb(node *head)
{
    head=head->next;
    if(head)
        head->prev=NULL;
    return head;
}
node *dell(node *head)
{
    node *t=head;
    while(t->next)
        t=t->next;// 1
    if(!t->prev) return NULL;
    t->prev->next=NULL;
    free(t);
    return head;
}
node *delp(node *head)
{
    int c;
    printf("Enter pos : ");
    scanf("%d",&c);
    if(c>count(head)-1||c<0)
    {
        printf("Invalid pos,couldnt delete\n");
        return head;
    }
    if(c==0){
        return delb(head);
    }
    node *t=head;
    while(c--)
        t=t->next;
    t->prev->next=t->next;
    if(t->next)
        t->next->prev=t->prev;
    free(t);
    return head;
}
node *deld(node *head,int x)
{// 1 2 3 4 5
    node *t=head;
    while(t&&t->data!=x)
        t=t->next;
    if(!t){
        printf("Data not found\n");
        return head;
    }
    if(!t->prev)
        return delb(head);
    t->prev->next=t->next;
    if(t->next)
        t->next->prev=t->prev;
    free(t);
    return head;
}
int search1(node *head,int x)
{
    node *t=head;
    while(t!=NULL)
    {
        if(t->data==x)
            return 1;
        t=t->next;
    }
    return 0;
}
int search2(node *head,int x)
{
    node *t=head; int c=0;
    while(t){
        if(t->data==x)
            return c;
        t=t->next;
        c++;
    }
    return -1;
}
int search3(node *head,int x)
{
    node *t=head; int c=0;
    while(t)
    {
        if(t->data==x)
            c++;
        t=t->next;
    }
    return c;
}
node* sort(node* head) {
    node *t=head;
    while(t)
    {
        node *f=t->next;
        while(f)
        {
            if(f->data<t->data)
            {
                int temp=f->data;
                f->data=t->data;
                t->data=temp;
            }
            f=f->next;
        }
        t=t->next;
    }
    return head;
}
node *rev(node *head)
{// 1 2 3 4 5
    node *t=head,*x=NULL;
    while(t)
    {
        x=t->prev;
        t->prev=t->next;
        t->next=x;
        t=t->prev;
    }
    if(x)
        head=x->prev;
    return head;
}