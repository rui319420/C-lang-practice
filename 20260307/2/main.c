#include <stdio.h>

int main(void)
{
	int N;
	int M;
	int count = 0;

	scanf("%d %d", &M, &N);

	int C[N];
	int i = 0;
	while (i < N)
	{
		scanf("%d", &C[i]);
		i++;
	}
	int A[M];
	int B[M];
	i = 0;
	while (i < M)
	{
		scanf("%d %d", &A[i], &B[i]);
		i++;
	}
	i = 0;
	while (i < M)
	{
		if (C[A[i] - 1] > 0)
		{
			for (int j = 0; j < B[i]; j++)
			{
				C[A[i] - 1]--;
				count++;
				if (C[A[i] - 1] == 0)
					break;
			}
		}
		i++;
	}
	printf("%d", count);
	return 0;
}