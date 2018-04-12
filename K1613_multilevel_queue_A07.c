# OS-Assignment
Operating Systems

#include<stdio.h>
struct process
{
    char process_name;
    int at,bt,ct,wt,tat,priority,bt1;
};
int main()
{
	struct process process[10];
	struct process process1[10];
	struct process temp;
    int i,time=0,tq1,tq2,bu_t=0,largest,n_pro,count=0,k,pf2=0,n_pro2,n,loc,j,flag=0,y;
    float wait_time=0,turnaround_time= 0,average_wt,average_tat;
    printf("\nEnter Total Number of Processes:\n");
    scanf("%d",&n_pro);
    n=n_pro;
    for(i=0;i<n_pro;i++)
    {
    	printf("\nProcess name:-");
    	fflush(stdin);
        scanf("%c",&process[i].process_name);
        printf("\nDetails For processor %c:\n",process[i].process_name);
        printf("Arrival Time:-");
        scanf("%d",&process[i].at);
        printf("Burst Time:-");
        scanf("%d",&process[i].bt);
        process[i].bt1=process[i].bt;
        printf("priorityity:\t");
        scanf("%d",&process[i].priority);
    }
    printf("\nTime Quantum for Fixed priorityity queue:-");
    scanf("%d",&tq1);
    printf("\nTime Quantum for Round Robin queue:-");
    scanf("%d",&tq2);
    printf("\n\nProcess\t Turnaround Time\t Waiting Time\n\n");
    for(i=0;i<n_pro;i++)
    {
        loc=i;
        for(j=i+1;j<n_pro;j++)
        {
            if(process[j].at<process[loc].at)
                loc=j;
        }
        temp=process[i];
        process[i]=process[loc];
        process[loc]=temp;
    }
    time=process[0].at;
    for(i=0;n_pro!=0;i++)
    {
    	while(count!=tq1)
    	{
    		count++;
    		if(process[i].at<=time)
    		{
    			for(j=i+1;j<n_pro;j++)
    			{
    				if(process[j].at==time&&process[j].priority<process[i].priority)
    				{
    					process1[pf2]=process[i];
						pf2++;
    					for(k=i;k<n_pro-1;k++)
    						process[k]=process[k+1];
    					n_pro--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			process[i].bt--;
			if(process[i].bt==0)
			{
				process[i].tat=time-process[i].at;
				process[i].wt=process[i].tat-process[i].bt1;
				printf("%c\t \t %d\t \t %d\n",process[i].process_name,process[i].tat,process[i].wt);
				wait_time+=time-process[i].at-process[i].bt1; 
    			turnaround_time+=time-process[i].at;
    			for(k=i;k<n_pro-1;k++)
    				process[k]=process[k+1];i--;
    			n_pro--;
				count=tq1;break;
			}
		}
		count=0;
		if(process[i].bt!=0)
		{
			process1[pf2]=process[i];
			pf2++;
			for(k=i;k<n_pro-1;k++)
    			process[k]=process[k+1];
    		n_pro--;
		}
			if(i==n_pro-1)
				i=-1;
	}
	
	n_pro2=pf2;
	for(count=0;n_pro2!=0;) 
	{ 
		if(process1[count].bt<=tq2&&process1[count].bt>0) 
    	{ 
    		time+=process1[count].bt; 
    		process1[count].bt=0; 
    		flag=1; 
    	} 
    	else if(process1[count].bt>0) 
    	{ 
    		process1[count].bt-=tq2; 
    		time+=tq2; 
    	} 
    	if(process1[count].bt==0&&flag==1) 
    	{ 
    		n_pro2--; 
    		process1[count].tat=time-process1[count].at;
			process1[count].wt=process1[count].tat-process1[count].bt1; 
			printf("%c\t \t %d\t \t %d\n",process1[count].process_name,process1[count].tat,process1[count].wt); 
    		turnaround_time+=time-process1[count].at; 
    		wait_time+=time-process1[count].at-process1[count].bt1;
    		for(k=count;k<n_pro2;k++)
    			process1[k]=process1[k+1];count--;
    		flag=0; 
    	} 

    	if(count==n_pro2-1) 
      		count=0; 
    	else 
    		count++; 
    }
    printf("\nAverage Waiting Time= %.2f\n",wait_time*1.0/n); 
    printf("Avg Turnaround Time = %.2f",turnaround_time*1.0/n);   
}
