#include <stdio.h>

int is_valid(int i, int j, int L, int R)
{
	if (L <= (j - i) && (j - i) <= R)
		return 1;
	return 0;
}

int main(void)
{
	int N, L, R;
	scanf("%d %d %d", &N, &L, &R);

	char S[N+1];
	scanf("%s", S);

	int count = 0;

	for (int i=0; i < N; i++)
	{
		for (int j = i + L; j <= i + R; j++)
		{
			if (j >= N)
				break;
			if (!is_valid(i, j, L, R))
				continue;
			if (S[i] == S[j])
				count++;
		}
	}
	printf("%d", count);
	return 0;
}