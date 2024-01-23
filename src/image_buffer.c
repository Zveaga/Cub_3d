
#include "cube3d.h"

int	init_image_buffer(t_main *main)
{
	int	y;

	main->image_buffer = (uint32_t **)malloc(sizeof(uint32_t *) * HEIGHT);
	if (!main->image_buffer)
		return (1);
	y = 0;
	while (y < HEIGHT)
	{
		main->image_buffer[y] = (uint32_t *)malloc(sizeof(uint32_t) * WIDTH);
		if (!main->image_buffer)
			return (1);
		y++;
	}
	return (0);
}

void	clear_image_buffer(t_main *main)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			main->image_buffer[y][x] = 0;
			x++;
		}
		y++;
	}
}
