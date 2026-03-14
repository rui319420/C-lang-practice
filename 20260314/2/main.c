#include <stdio.h>

int main(void)
{
	int H;
	int W;
	int Q;

	scanf("%d %d %d", &H, &W, &Q);

	int i = 0;
	int index;
	int n;

	while (i < Q)
	{
		scanf("%d %d", &index, &n);
		if (index == 1)
		{
			printf("%d\n", (n * W));
			H -= n;
		}
		else if (index == 2)
		{
			printf("%d\n", (n * H));
			W -= n;
		}
		i++;
	}
	return 0;
}