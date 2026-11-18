
#include<stdio.h>

int main(){

    int bt[20], wt[20], tat[20], n;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("Enter Burst Time for P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    // First process
    wt[0] = 0;
    tat[0] = bt[0];

    // Calculate waiting and turnaround time
    for(int i=1; i<n; i++){
        wt[i] = tat[i-1];
        tat[i] = bt[i] + wt[i];
    }

    // Calculate averages
    for(int i=0; i<n; i++){
        wtavg += wt[i];
        tatavg += tat[i];
    }

    wtavg = wtavg/n;
    tatavg = tatavg/n;

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

    for(int i=0; i<n; i++){
        printf("\nP%d\t%d\t\t%d\t\t%d",
               i+1,bt[i],wt[i],tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f",wtavg);
    printf("\nAverage Turnaround Time = %.2f\n",tatavg);

    return 0;
}
