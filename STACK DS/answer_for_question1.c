#include<stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *top;
void push1(int x)
{
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=x;
  new_node->next=top;
  top=new_node;
}
void push2(int x)
{
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=x;
  new_node->next=top;
  top=new_node;
}
int pop1()
{
  int ele;
  struct node *newtop;
  newtop=top;
  ele=top->data;
  top=top->next;
  free(newtop);
  return ele;
}
int pop2()
{
  int element;
  struct node *newtop2;
  newtop2=top;
  element=top->data;
  top=top->next;
  free(newtop2);
  return element;
}
int main()
{
  int n,a[10],b[10],i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    push1(a[i]);
  }
  printf("Popped element from stack1 is %d\n",pop1());
  for(j=0;j<n;j++)
  {
    scanf("%d",&b[j]);
    push2(b[j]);
  }
  printf("Popped element from stack2 is %d\n",pop2());
  return 0;
}
