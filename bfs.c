#include<stdio.h>
#include<time.h>
void bfs(int a[10][10],int n, int source)
{
 	int s[10],q[10],f=0,r=-1,t,v;
	 for(v=0;v<n;v++)
	{
		s[v]=0;
	}
 	q[++r]= source;
 	s[source]=1;
	while(f<=r)
 	{
  		t=q[f++];
  		for(v=0; v<n; v++)
		if(a[t][v]==1 && s[v]==0)
		{
	 		q[++r]=v;
	 		printf("The BFS traversal is:\n %d %d", t, v);
			printf(“%d is reachable from source %d \n”, v, source);
	 		s[v]=1;
		}
 	}
  }


main()
{
 	int a[10][10],n,i,j,s;
      double clk;
      clock_t starttime,endtime;
	printf("\n Enter the number of vertices\n");
 	scanf("%d",&n);
	printf("\nEnter the matrix represention:");
 	for(i=0;i<n;i++)
 	for(j=0;j<n;j++)
  	scanf("%d",&a[i][j]);
 	printf("\nEnter the source vertix");
 	scanf("%d",&s);
      starttime=clock(); 
 	bfs(a,n,s);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
      printf("\nThe run time is %f\n",clk);
 
}


