//C Program to add or subtract two matrices
#include<stdio.h>
#include<string.h>
void accept(int[10][10],int[10][10],int,int);
void display(int[10][10],int,int);
void add(int[10][10],int[10][10],int,int);
void subtract(int[10][10],int[10][10],int,int);
int main()
{
	int a[10][10],b[10][10],r,c=0,ch=0;
	printf("enter the no of rows\n");
	scanf("%d",&r);
	printf("enter the columns\n");
	scanf("%d",&c);
	accept(a,b,r,c);
	printf("\n1.add\n2.subtract\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
	switch(ch)
	{
	case 1:add(a,b,r,c);
		printf("\nsum of matrices is\n");
		display(a,r,c);
        break;
	case 2:	subtract(a,b,r,c);
		printf("\ndifference of matrices is\n");
		display(a,r,c);
		break;
	default:printf("invalid entry");
	}
	return 0;
}
void accept(int a[10][10],int b[10][10],int r,int c)
{    int j,i=0;
	printf("enter the elements of array a\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("enter the elements of array b\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d",&b[i][j]);
			}
			printf("\n");
		}
}
void add(int a[10][10],int b[10][10],int r,int c)
{    int j,i=0;
for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			a[i][j]+=b[i][j];
		}
	}
}
void subtract(int a[10][10],int b[10][10],int r,int c)
{    int j,i=0;
for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			a[i][j]-=b[i][j];
		}
	}
}
void display(int a[10][10],int r,int c)
{    int j,i=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}
