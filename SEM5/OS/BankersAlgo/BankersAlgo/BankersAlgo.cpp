#include<stdio.h>
#include<stdlib.h>

void main()
{
	int available[10], max[10][10], need[10][10], allocation[10][10]; 
	int work[10], safeSequence[10], temp[10];
	int n, m;
	bool finish[10];
	printf("Enter the number of processes\n");
	scanf_s("%d", &n);
	printf("\nEnter the number of resource types\n");
	scanf_s("%d", &m);

	printf("\nEnter the instances of resources allocated to each process\n");
	for (int i = 0; i < n; i++)
	{
		finish[i] = false;
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &allocation[i][j]);
		}
	}

	printf("\nEnter the available instances of each resource type\n");
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &available[i]);
		work[i] = available[i];
		temp[i] = work[i];
	}

	printf("\nEnter the max resources the each process has requested\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	int x, index = 0;
	bool state, safe = true, done = false;
	do
	{
		for (int i = 0; i < m; i++)
		{
			if (work[i] != temp[i])
			{
				done = false;
				break;
			}
		}
		x = 1;
		if (!done)
		{
			done = true;
			for (int i = 0; i < m; i++)
			{
				temp[i] = work[i];
			}
			for (int i = 0; i < n; i++)
			{
				if (!finish[i])
				{
					state = true;
					x = 0;
					for (int j = 0; j < m; j++)
					{
						if (need[i][j] > work[j])
						{
							state = false;
							break;
						}
					}
					if (state)
					{
						for (int j = 0; j < m; j++)
						{
							work[j] += allocation[i][j];
						}
						finish[i] = true;
						safeSequence[index++] = i;
					}
				}
			}
		}
	} while (x != 1);

	for (int i = 0; i < n; i++)
	{
		if (!finish[i])
		{
			safe = false;
			break;
		}
	}
	if (safe)
	{
		printf("\nSafe sequence\n");
		for (int i = 0; i < n - 1; i++)
		{
			printf("p%d ->", safeSequence[i]);
		}
		printf("p%d", safeSequence[n - 1]);
	}
	else
		printf("The system is not in safe state");
}