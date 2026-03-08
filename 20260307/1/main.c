#include <stdio.h>
#include <unistd.h>

int main(void) 
{
	int n;
	int x;

	scanf("%d %d", &n, &x);

	int array[n];
	int i = 0;
	while (i < n)
	{
		scanf("%d", &array[i]);
		if (array[i] < x)
		{
			x = array[i];
			write(1, "1\n", 2);
		}
		else
			write(1, "0\n", 2);
		i++;
	}
	return 0;
}