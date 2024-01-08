
#include "cube3d.h"

//allocates memory for a blank image, pixel-by-pixel
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

void	fill_image_buffer(t_main *main, t_math *math, int x)
{
	int		y;
	int32_t	color_1;
	int32_t	color_2;

	color_1 = set_color(153, 102, 255, 1000);
	color_2 = set_color(153, 0, 255, 1000);
	y = math->startPixel;
	while (y <= math->endPixel)
	{
		if (math->side == 1)
			main->image_buffer[y][x] = color_1;
		else
			main->image_buffer[y][x] = color_2;
		y++;
	}
	
}

// static void print_img_buf(uint32_t **map)
// {
// 	for (int i = 0; i < HEIGHT; i++)
// 		for (int j = 0; j < WIDTH; j++)
// 			printf("%d", map[i][j]);
// }

void clear_image_buffer(t_main *main)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x< WIDTH)
		{
			main->image_buffer[y][x] = 0;
			x++;
		}
		y++;
	}

}
