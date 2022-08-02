#include<stdio.h>

struct process
{
    int pid,AT,BT,CT,TAT,WT;
}p[100],temp;

int n;

void swap(int a,int b)
{
    temp=p[a];
    p[a]=p[b];
    p[b]=temp;
} 

void Display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].pid>p[j+1].pid)
                swap(j,j+1);
        }
    }

    printf("\nPID  AT BT CT TAT WT\n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",p[i].pid);
        printf(" %d ",p[i].AT);
        printf(" %d ",p[i].BT);
        printf(" %d ",p[i].CT);
        printf(" %d ",p[i].TAT);
        printf(" %d \n",p[i].WT);
    }
}



void readInput()
{
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the pid, AT and BT of process %d",i);
        scanf("%d%d%d",&p[i].pid,&p[i].AT,&p[i].BT);
    }
    
}

void fcfs()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].AT>p[j+1].AT)
                swap(j,j+1);
        }
    }

    printf("Guant Chart:");
    int time=0;
    for(int i=0;i<n;i++)
    {
        if(time>=p[i].AT)
        {
            printf("P%d",p[i].pid);
            time=time+p[i].BT;
            p[i].CT=time;
            p[i].TAT=p[i].CT-p[i].AT;
            p[i].WT=p[i].TAT-p[i].BT;
        }
        else
        {
            time++;
            i--;
        }
    }

    Display();
}

void main()
{
    readInput();
    //fcfs();
    
}