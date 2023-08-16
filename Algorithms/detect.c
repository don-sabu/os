#include<stdio.h>
int requestLessThanWork(int r, int work[], int request[])
{
    for(int i=0;i<r;i++)
        if(work[i] <= request[i])
            // If the any of the request is greater than work then the function exits from here returning false.
            return 0;
    // If there is no request greater than work then this method returns true.
    return 1;
}
int checkDeadlock(int p, int mark[])
{
    for(int i=0;i<p;i++)
        if(mark[i] == 0)
            // If any one process is marked as false then this method ends here returning false.
            return 0;
    // If there is no process marked as false then this method returns true.        
    return 1;
}
int main()
{
    int p, r;
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    printf("Enter the number of resources: ");
    scanf("%d",&r);
    int avail[r], alloc[p][r], request[p][r];
    int work[r], mark[p];
    printf("Enter the available number of instances for each resource:\n");
    for(int i=0;i<r;i++)
    {
        printf("Enter no of instance for resource R%d: " ,i+1);
        scanf("%d", &avail[i]);
        // Initializing work to available resources
        work[i] = avail[i];
        // Marking each process as not processed
        mark[i] = 0;
    }
    // Reading number of resources allocated for each process
    printf("Enter the allocation matrix:\n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    // Reading the number of resources requested by each process
    printf("Enter the request matrix:\n");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&request[i][j]);
    for(int i=0;i<p;i++)
        if(!mark[i])
            if(requestLessThanWork(r, work, request[i]))
            {
                for(int j=0;j<r;j++)
                    work[j] += alloc[i][j];
                    // Adding allocated resources to the available work.
                mark[i] = 1;
                // Marking the process as can be processed.
                i = -1;
                // If a process is marked then we need to start checking again from the beginning.
                // Since only unmarked processed are checked, no infinite loop occurs.
            }
    if(checkDeadlock(p, mark))
        printf("No Deadlock Detected\n");
    else
        printf("Deadlock Detected\n");
}
