#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low-1;
    int j=high+1;
    while(1)
    {
        do
        {
            i++;
        }while(arr[i]<pivot);
        do
        {
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
        swap(&arr[i],&arr[j]);
    }

}
int partitionrandom(int arr[],int low, int high)
{
    int random=low+rand()%(high-low);
    swap(&arr[random],&arr[low]);
    return partition(arr,low,high);
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partitionrandom(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);

    }
}
void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
  printf("%d  ",arr[i]);
  printf("\n");
}
int main()
{
 double total_time;
 clock_t start,end;
 start=clock();
 srand(time(NULL));
 for(int p=0;p<5;p++)
 {
     int arr[100000],n;
     printf("size:");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
         arr[i]=rand()%1000;
     }
     quicksort(arr,0,n-1);
     printf("sorted array:");
     printarr(arr,n);
     end=clock();
     total_time=(double)(end-start)/CLOCKS_PER_SEC;
     printf("%f\n",total_time);
 }
}
