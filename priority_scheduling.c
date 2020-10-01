#include<stdio.h>
void sort(int *a,int *b,int *c,int n){
    int temp,x;
    for(int i=0;i<n;i++){
        x=i;
        for(int j=i+1;j<n;j++){
            if(c[j]<c[i])
                x=j;
        }
        temp=a[i];
        a[i]=a[x];
        a[x]=temp;

        temp=b[i];
        b[i]=b[x];
        b[x]=temp;

        temp=c[i];
        c[i]=c[x];
        c[x]=temp;

        
    }    
}
void main(){
    int burst[30],p[30],wait[30],turn_t[30],i,j,n,priority[30];
    printf("enter no.of processes:");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<n;i++){
        printf("Enter the burst time of process p%d :",i+1);
        scanf("%d",&burst[i]);
        printf("Enter the priority of process p%d :",i+1);
        scanf("%d",&priority[i]);
        printf("\n");
        p[i]=i+1;
    }
    //printf("%d",burst[2]);
    sort(burst,p,priority,n);
    //printf("%d",burst[2]);
    wait[0]=0;
    turn_t[0]=burst[0];
    for(i=1;i<n;i++){
        wait[i]=burst[i-1]+wait[i-1];
        turn_t[i]=wait[i]+burst[i];
    }
    // for(i=0;i<n;i++){
    //     printf("%d",turn_t[i]);
    // }
    // printf("wait time is:%d",turn_t[2]);
    float avg_wt,avg_turn_t;
    int sum=0,sum1=0;
    for(i=0;i<n;i++){
        sum=sum+wait[i];
        sum1=sum1+turn_t[i];
    }
    avg_wt=(float)sum/n;
    avg_turn_t=(float)sum1/n;

    printf("JOB\tPriority\tBurst Time\tWaiting TIme\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\n",p[i],priority[i],burst[i],wait[i],turn_t[i]);
    }
    printf("\nAverage waiting time is %f.",avg_wt);
    printf("\nAverage turn-around time is %f.\n",avg_turn_t);

}
