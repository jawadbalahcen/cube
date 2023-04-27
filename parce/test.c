
#include "cub3d.h"
#include <stdlib.h>
#include <sys/time.h>
int	main(void)
{
	struct timeval time;
	struct timeval time1;

	double a = 0;
	double b = 0;
	gettimeofday(&time, NULL);

	printf("[%ld]\n", ((time.tv_sec * 1000) + (time.tv_usec / 1000)));

	while (a < (2 * M_PI))
	{
		b = cos(a);
		b = cos(a);
		b = cos(a);
		b = cos(a);
		b = cos(a);
		b = cos(a);
		b = cos(a);
		b = cos(a);
		b = sin(a);
		b = sin(a);
		b = sin(a);
		b = sin(a);
		a += ANG_BTW_RAY;
	}
	gettimeofday(&time1, NULL);
	printf("[%ld]\n", ((time1.tv_sec * 1000) + (time1.tv_usec / 1000)));
}