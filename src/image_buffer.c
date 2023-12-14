
#include "cube3d.h"

//allocates memory for a blank image, pixel-by-pixel
void	init_image_buffer(t_main *main)
{
	int	y;

	main->image_buffer = (uint32_t **)malloc(sizeof(uint32_t *) * HEIGHT);
	// if (!main->img_buffer)
	 	//free and exit
	y = 0;
	while (y < HEIGHT)
	{
		main->image_buffer[y] = (uint32_t *)malloc(sizeof(uint32_t) * WIDTH);
		// if (!main->img_buffer[y])
		 	//free and exit
		y++;
	}
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

// static void print_map(uint32_t **map)
// {
// 	for (int i = 0; map[i]; i++)
// 		for (int j = 0; map[i][j]; j++)
// 			printf("%d", map[i][j]);
// }

void clear_image_buffer(t_main *main)
{
	// printf("+++++\n");

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
	// ft_free_array(main->image_buffer, HEIGHT);
	//print_map(main->image_buffer);
}
