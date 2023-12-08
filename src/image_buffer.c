
#include "cube3d.h"

//allocates memory for a blank image, pixel-by-pixel
void	init_image_buffer(t_main *main)
{
	int	y;

	main->img_buffer = (uint32_t **)malloc(sizeof(uint32_t *) * HEIGHT);
	// if (!main->img_buffer)
	 	//free and exit
	y = 0;
	while (y < HEIGHT)
	{
		main->img_buffer[y] = (uint32_t *)malloc(sizeof(uint32_t) * WIDTH);
		// if (!main->img_buffer[y])
		 	//free and exit
		y++;
	}
}

// void	fill_image_buffer(t_main *main)
// {

// }