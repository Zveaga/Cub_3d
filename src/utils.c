
#include "cube3d.h"


int32_t	set_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void print_pixel_grid(int32_t **pixel_grid)
{
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
			printf("%d ", pixel_grid[i][j]);
		printf("\n");
	}
}

