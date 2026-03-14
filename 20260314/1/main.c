#include <stdio.h>
#include <math.h>

int main(void)
{
	double D;
	double R;
	double area;
	scanf("%le", &D);

	R = D / 2;
	area = 3.141592653589793 * R * R;

	printf("%le", area);
	return 0;
}
