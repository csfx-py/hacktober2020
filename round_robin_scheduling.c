#include<stdio.h>
#include<stdlib.h>
void main(){
    int b[30],wait[30],turn_t[30],m,quanta,p_t[30],r_t=0,burst[30];
    char *p[30];
    printf("Enter the number of processes : ");
    scanf("%d",&m);

    for(int i=0;i<m;i++){
        printf("\nEnter the name of process : ");
        p[i]=malloc(5*sizeof(char));
        scanf("%s",p[i]);
        printf("Enter the burst time of process : ");
        scanf("%d",&burst[i]);
        //printf("%s",p[i]);
        
    }
    for(int i=0;i<m;i++){
        b[i]=burst[i];
    }
    printf("\nEnter time quanta : ");
    scanf("%d",&quanta);
    wait[0]=0;
    
    turn_t[0]=b[0];
    while(1){
    int f=0;
    for(int i=0;i<m;i++){
        if(b[i]>0){
            f=1;
        if(b[i]>quanta){
            r_t=r_t+quanta;
            b[i]-=quanta;
        }
        else{
            r_t=r_t+b[i];
            wait[i]=r_t-burst[i];
            b[i]=0;
        }
        

    }
    }
     
    if(f==0)
    break;
    }
    for(int i=0;i<m;i++){
        turn_t[i]=wait[i]+burst[i];
    }
    int s_wait=0,s_turn=0;
    for(int i=0;i<m;i++){
        s_wait+=wait[i];
        s_turn+=turn_t[i];
    }
    float avg_wait=(float)s_wait/m;
    float avg_turn=(float)s_turn/m;
    printf("\nJOB\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<m;i++){
        printf("%s\t\t%d\t\t%d\t\t%d\t\t\n",p[i],burst[i],wait[i],turn_t[i]);
    }
    printf("\nAverage waiting time is %f.",avg_wait);
    printf("\nAverage turn-around time is %f.\n",avg_turn);
}
