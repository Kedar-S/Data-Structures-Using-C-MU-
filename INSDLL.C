#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
 long data;
 struct node *next;
 struct node *prev;
};
int count=0;

struct node * create()
{
// int count;
 char c;
 struct node *start=NULL;
 struct node *newnode,*last;
 do
 {
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter data: ");
  scanf("%d",&newnode->data);
  if(start==NULL)
    {
     last=newnode;
     start=newnode;
     newnode->next=NULL;
     newnode->prev=NULL;
    }
  else
    {
     last->next=newnode;
     newnode->prev=last;
     last=newnode;
     newnode->next=NULL;
    }
  printf("addd element? ");
  c=getch();
  if(c=='n')
    count++;
 }while(c!='n');
 return start;
}

struct node * insert_beg(struct node *header)
{
  struct node *head,*node1;
  node1=(struct node *)malloc(sizeof(struct node));
  head=header;
  printf("Enter data ");
  scanf("%d",&node1->data);
  node1->prev=NULL;
  node1->next=head;
  head->prev=node1;
  head=node1;
  return head;
}

struct node * insert_end(struct node *st)
{
 struct node *start,*node2,*i;
 start=st;
 for(i=start;i->next!=NULL;i=i->next)
    {
    }
 node2=(struct node *)malloc(sizeof(struct node));
 printf("Enter data: ");
 scanf("%d",&node2->data);
 node2->prev=start;
 start->next=node2;
 node2->next=NULL;
 return st;
}
struct node * insert_pos(struct node *strt)
{
 int pos,c=1;
 struct node *temp,*rest,*node3,*i;
 temp=strt;
 printf("Which position?\n");
 scanf("%d",&pos);
 for(i=temp;i->next!=NULL;i=i->next)
    {
     c++;
     if(c==pos)
       {
	rest=i->next;
	printf("Enter the data: ");
	node3=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&node3->data);
	node3->prev=i;
	i->next=node3;
	i=node3;
	i->next=rest;
	rest->prev=i;
       }
     }
 return strt;
}
void display(struct node *s)
{
 struct node *temp;
 temp=s;
 while(temp!=NULL)
    {
     printf("%d  ",temp->data);
     temp=temp->next;
    }
}

void main()
{
 int choice;
 struct node *head1,*head3,*head2,*head4;
 clrscr();
 head1=create();
 printf("\n+++++++++++++++++++++++\n");
 printf("Enter choice:\n");
 printf("1.insert beg\n2.insert end\n3.insert at pos");
 scanf("%d",&choice);
 switch(choice)
{
 case 1: head2=insert_beg(head1);
	 display(head2);break;
 case 2: head3=insert_end(head1);
	 display(head3);break;
 case 3: head4=insert_pos(head1);
	 display(head4);break;
 default: printf("INVALID INPUT");
}
// display(head2);
 getch();
}









