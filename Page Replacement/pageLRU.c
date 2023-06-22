#include<stdlib.h>
#include<stdio.h>
#define max 100
#define min 10
int ref[max],count,frame[min],n;
void input()
{
	int i,temp;
	count=0;
	printf("Enter the number of page frames: ");
	scanf("%d",&n);
	printf("Enter the reference string (-1 for end):\n");
	scanf("%d",&temp);
	while(temp != -1)
	{
		ref[count++]=temp;
		scanf("%d",&temp);
	}
}
void LRU()
{
    int i,j,k,stack[min],top=0,fault=0;
    system("CLS");
    for(i=0;i<count;i++)
    {
        if(top<n)
            stack[top++]=ref[i],fault++;
        else
        {
            for(j=0;j<n;j++)
                if(stack[j]==ref[i])
                    break;
            if(j<n)
            {
                for(k=j;k<n-1;k++)
                stack[k]=stack[k+1];
                stack[k]=ref[i];
            }
            else
            {
                for(k=0;k<n-1;k++)
                stack[k]=stack[k+1];
                stack[k]=ref[i];
                fault++;
            }
        }
        printf("After inserting %d the stack status is: ",ref[i]);
        for(j=0;j<top;j++)
            printf("%d ",stack[j]);
        printf("\n");
    }
    printf("End to inserting the reference string.\n");
    printf("Total page fault is %d.\n",fault);
}
void main()
{
    int x;
    while(1)
    {
        printf("-----------------MENU-----------------\n");
        printf("1. Input\n");
        printf("2. LRU (Least Recently Used) Algorithm\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            input();
            break;
        case 2:
            LRU();
            break;
        case 0:
        	printf("Exiting the program...\n");
            exit(0);
        }
    }
}
