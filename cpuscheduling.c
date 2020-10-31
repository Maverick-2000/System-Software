#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct
{
int pid;
float at, wt, bt, ta, st;
bool isComplete;
}process; // for sjf

void fcfs();
void sjf();
void rr();
void prio();

void main(){
int ch;
do
{
printf("\nCPU Scheduling Simulation\n");
printf("-------------------------------");
printf("\n1.First Come First Serve\n2.Shortest Job First\n3.Round Robin\n4.Priority\n5.Exit\n");
printf("\nEnter choice : ");
scanf("%d",&ch);

switch(ch)
{
case 1:fcfs();break;
case 2:sjf();break;
case 3:rr();break;
case 4:prio();break;
case 5:printf("\nExit.... \n");break;
default:printf("\nInvalid entry");
}
}while(ch!=5);

}

void fcfs ()
{
	int i,j,n,bt[30],wt[30],tat[30];
	float awt=0,atat=0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	printf("Enter the burst time: ");
	for (i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	printf("Process\t Burst Time\t Waiting Time\t Turn around time\n");
	for (i=0;i<n;i++)
	{
		wt[i]=0;
		tat[i]=0;
		for (j=0;j<i;j++){
			wt[i]=wt[i]+bt[j];
		}
		tat[i]=wt[i]+bt[i];
		awt=awt+wt[i];
		atat=atat+tat[i];
		printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}

	awt=awt/n;
	atat=atat/n;
	printf("\nAverage Waiting Time: %f",awt);
	printf("\nAverage Turn Around Time: %f \n",atat);

}

void procdetail(int i, process p[])
{
printf("Process id: ");
scanf("%d", &p[i].pid);
printf("Arrival Time: ");
scanf("%f", &p[i].at);
printf("Burst Time: ");
scanf("%f", &p[i].bt);
p[i].isComplete = false;
}//for sjf
void sort(process p[], int i, int start)
{
int k = 0, j;
process temp;
for (k = start; k<i; k++)
{
for (j = k+1; j<i; j++)
{
if(p[k].bt < p[j].bt)
continue;
else
{
temp = p[k];
p[k] = p[j];
p[j] = temp;
}
}
}
}//sort for sjf

void sjf()
{
    int n, i, k = 0, j = 0;
float avgwt = 0.0, avgta = 0.0, tst = 0.0;
printf("Enter number of processes: ");
scanf("%d",&n);
process p[n];
for (i = 0; i<n; i++)
{
printf("\nEnter process %d's details: ",i);
procdetail(i,p);
}
for (i = 0; i<n; i++)
{
if (p[i].isComplete == true)
continue;
else
{
k = i;
while (p[i].at<=tst && i<n)
i++;
sort (p,i,k);
i = k;
if(p[i].at<=tst)
p[i].st = tst;
else
p[i].st = p[i].at;
p[i].st = tst;
p[i].isComplete = true;
tst += p[i].bt;
p[i].wt = p[i].st - p[i].at;
p[i].ta = p[i].bt + p[i].wt;
avgwt += p[i].wt;
avgta += p[i].ta;
}
}
avgwt /= n;
avgta /= n;
printf("Process Schedule Table: \n");
printf("\tProcess ID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");
for (i = 0; i<n; i++)
printf("\t%d\t\t%f\t%f\t%f\t%f\n", p[i].pid,p[i].at, p[i].bt, p[i].wt, p[i].ta);
printf("\nAverage wait time: %f", avgwt);
printf("\nAverage turnaround time: %f\n", avgta);
}

void rr()
{
      int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("\nEnter the number of process: ");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
 
            printf("Arrival Time:");
 
            scanf("%d", &arrival_time[i]);
 
            printf("Burst Time:");
 
            scanf("%d", &burst_time[i]);
 
            temp[i] = burst_time[i];
      }
 
      printf("\nEnter Time Quantum: ");
      scanf("%d", &time_quantum);
      printf("\nProcess   \tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\n%5d\t\t%5d\t\t %5d\t\t\t %5d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\nAverage Waiting Time: %f", average_wait_time);
      printf("\nAverage Turnaround Time: %f\n", average_turnaround_time);
}

void prio()
{
    int et[20],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];
    
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Process Number,Arrival Time,Burst Time & Priority:");
  
        scanf("%s%d%d%d",pn[i],&at[i],&et[i],&p[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nProcess\tArrivalTime\tBurstTime\tPriority\tWaitingTime\tTurnAroundTime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
    printf("\nAverage Waiting Time :%f",awt);
    printf("\nAverage Turnaround Time:%f \n",ata);
}