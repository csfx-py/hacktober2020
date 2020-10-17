#include<stdio.h>

int main()
{
 int i,n,item,pos,a[10];
 printf("Enter the elements in an array: \n");

 for(i=0;i<n;i++)
 {
  scanf("%d", &a[i]);
 }

 printf("An array is: \n");

 for(i=0;i<n;i++)
 {
  printf(" ");
  printf("%d", a[i]);
 }

 printf("\nEnter the element to be searched linearly: \n");
 scanf("%d", &item);

for(i=0;i<n;i++)
 {
  if (item==a[i])
  {
   printf("%d",i);
   break;
  }
 }

  if(i==sizeof(a[i]))
  {
   printf("\nnot found.");
  }

 }



