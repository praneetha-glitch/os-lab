#define max 10
#include<stdio.h>
struct process{
    int at;
    int bt;
    int wt;
    int tat;
    int ct;
    int done;
};
void sjf(struct process p[],int n){
int completed=0;
int t=0;
float totalwt=0;
float totaltat=0;
while(completed<n){
int idx=-1;
int minbt=9999;
for(int i=0;i<n;i++){
if(p[i].at<=t&&p[i].done==0){
if(p[i].bt<minbt){
minbt=p[i].bt;
idx=i;
}
else if(p[i].bt==minbt){
if(p[i].at<p[idx].at){
idx=i;
}
}
}
}
if(idx!=-1){
p[idx].wt=t-p[idx].at;
p[idx].ct=t+p[idx].bt;
p[idx].tat = p[idx].ct - p[idx].at;
totalwt += p[idx].wt;
totaltat += p[idx].tat;
p[idx].done = 1;
completed++;
t = p[idx].ct;
}
else {
t++;
}
}
printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
for (int i = 0; i < n; i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].at, p[i].bt, p[i].ct,
p[i].wt, p[i].tat);
}
printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
printf("Average Turnaround Time: %.2f\n", totaltat / n);
}
int main()
{
int n;
struct process p[max];
printf("Enter number of processes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
printf("Enter arrival time for process %d: ", i);
scanf("%d", &p[i].at);
printf("Enter burst time for process %d: ", i);
scanf("%d", &p[i].bt);
p[i].done = 0;
}
sjf(p, n);
return 0;
}












