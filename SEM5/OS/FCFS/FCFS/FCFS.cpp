#include<stdio.h>
#include<conio.h>

#define MAX 20
void main()
{
	int num, x, y, z;
	int p[MAX], at[MAX], bt[MAX], ft[MAX], tat[MAX], wt[MAX];
	printf("Enter the number of processes\n");
	scanf_s("%d", &num);
	printf("\nEnter the Process number, Arrival time and Burst time\n");
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d%d%d", &p[i], &at[i], &bt[i]);
	}
	for (int i = 0; i < num; i++)
	{
		printf("\n%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time");
		printf("P%-15d%-15d%-15d\n\n", p[i], at[i], bt[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------");
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (at[j+1] < at[j])
			{
				x = p[j];
				y = at[j];
				z = bt[j];
				p[j] = p[j + 1];
				at[j] = at[j + 1];
				bt[j] = bt[j + 1];
				p[j + 1] = x;
				at[j + 1] = y;
				bt[j + 1] = z;
			}
		}
	}
	ft[0] = bt[0];
	tat[0] = ft[0] - at[0];
	wt[0] = tat[0] - bt[0];
	for (int i = 1; i < num; i++)
	{
		ft[i] = bt[i - 1] + bt[i];
		tat[i] = ft[i] - at[i];
		wt[i] = tat[i] - bt[i];
	}
	for (int i = 0; i < num; i++)
	{
		printf("\n%-16s%-16s%-16s%-16s%-16s%-16s\n", "Process", "Arrival Time", "Burst Time", "Finish Time", "TurnAround Time", "Waiting Time\n");
		printf("P%-16d%-16d%-16d%-16d%-16d%-16d\n", p[i], at[i], bt[i], ft[i], tat[i], wt[i]);
	}
	_getch();
}

