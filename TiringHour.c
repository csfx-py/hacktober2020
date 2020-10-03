#include<stdio.h>
#include<math.h>
#include<limits.h>
#define MAX
int main ()
{
    int a[]={9,9,6,0,6,6,9};
    
   int m = 0;
for(int i = 0; i < 7; i++) {
int tiringDays = 0, nonTiringDays = 0;
for(int j = i; j < 7; j++) {
if(a[j] > 8)
 {
tiringDays++;
}
else {
nonTiringDays++;
}
if(tiringDays > nonTiringDays)
 {
m = MAX(m, j - i + 1);
}
}
}
printf("%d",m) ;
}