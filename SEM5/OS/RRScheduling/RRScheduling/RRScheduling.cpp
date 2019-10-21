#include<stdio.h>
#include<conio.h>

#define MAX 20
void main()
{
	int p[MAX], at[MAX], bt[MAX], ft[MAX], tat[MAX], wt[MAX], rem_bt[MAX], cur_at[MAX];
	int quantum, num, t, total_time = 0, x, y, z;
	bool done= false;
	printf("Enter the number of processes:\n");
	scanf_s("%d", &num);
	printf("\nEnter the Process id, Arrival Time and Burst Time\n");
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d%d%d", &p[i], &at[i], &bt[i]);
		total_time += bt[i];
	}
	for (int i = 0; i < num; i++)
	{
		printf("\n%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time");
		printf("P%-15d%-15d%-15d\n\n", p[i], at[i], bt[i]);
	}
	printf("Enter the time quantum\n");
	scanf_s("%d", &quantum);
	t = 0;
	printf("----------------------------------------------------------------------------------------------------------");
	//SORTING
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (at[j + 1] < at[j])
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
	//TO keep track of current arrival time and remaining burst time
	//Initialise to burst and arrival time at start
	for (int i = 0; i < num; i++)
	{
		rem_bt[i] = bt[i];
		cur_at[i] = at[i];
	}
	while (!done)
	{
		for (int i = 0; i < num; i++)
		{
			//To check if any other process is present in the queue before process i and let it run
			for (int j = 0; j < num; j++)
			{
				if (cur_at[j] < cur_at[i])
				{
					if (t >= at[j])
					{
						if (rem_bt[j] > 0)
						{
							if (rem_bt[j] > quantum)
							{
								t = t + quantum;
								rem_bt[j] = rem_bt[j] - quantum;
							}
							else
							{
								t = t + rem_bt[j];
								rem_bt[j] = 0;
								ft[j] = t;
							}
							cur_at[j] = t;
						}
					}
				}
			}
			//To run process i
			if (t >= at[i])
			{
				if (rem_bt[i] > 0)
				{
					if (rem_bt[i] > quantum)
					{
						t = t + quantum;
						rem_bt[i] = rem_bt[i] - quantum;
					}
					else
					{
						t = t + rem_bt[i];
						rem_bt[i] = 0;
						ft[i] = t;
					}
					cur_at[i] = t;
				}
			}
		}
		if (t == total_time)
			done = true;
	}
	for (int i = 0; i < num; i++)
	{
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