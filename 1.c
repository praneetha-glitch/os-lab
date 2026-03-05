#include<stdio.h>
struct process{
   int at;
   int bt;
   int wt;
   int tat;
   int ct;
};
#define max 10
void sortprocesses(struct process p[],int n){
 for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
       if (p[j].at>p[j+1].at){
         struct process temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;

       }
    }
 }
}
void fcfs(struct process p[],int n){
  int t=0;
  for(int i=0;i<n;i++){
     if(t<p[i].at){
     t=p[i].at;
     }
     p[i].wt=t-p[i].at;
     p[i].ct=t+p[i].bt;
     p[i].tat=p[i].ct-p[i].at;
     t=t+p[i].bt;
  }
  printf("\n%-5s%-5s%-5s%-5s%-5s%-5s\n", "PID", "AT", "BT", "CT", "WT", "TAT");
  for(int i=0;i<n;i++){
     printf("%-5d%-5d%-5d%-5d%-5d%-5d\n", i, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);

  }
  float awt=0.0;
  float atat=0.0;
  for(int i=0;i<n;i++){
  awt=awt+p[i].wt;
  atat=atat+p[i].tat;
  }
  awt=awt/n;
  atat=atat/n;
 printf("AWT ATAT %5.2f %5.2f", awt, atat);
}

int main()
{
int n;
struct process p[max];
printf("Enter nummber of processes--- ");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
printf("Enter arrival time for process %d----",i);
scanf("%d",&p[i].at);
printf("Enter burst time for process %d----",i);
scanf("%d",&p[i].bt);
}
sortprocesses(p,n);
fcfs(p,n);
}
