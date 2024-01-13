
#include "cube3d.h"

int init_pixel_grid(t_main *main, mlx_image_t *texture)
{
	uint32_t	i;

	main->pixel_grid = (int32_t **)malloc(sizeof(int32_t *) * texture->height);
	if (!main->pixel_grid)
		return (1);
	i = 0;
	while (i < texture->height)
	{
		main->pixel_grid[i] = (int32_t *)malloc(sizeof(int32_t) * texture->width);
		if (!main->pixel_grid[i])
			return (1);
		i++;
	}
	return (0);
}



int	convert_pixels_to_grid(t_main *main, mlx_image_t *texture)
{
	int			j;
	uint32_t	x;
	uint32_t	y;
	
	y = -1;
	j = 0;
	init_pixel_grid(main, texture);
	while (++y < texture->height)
	{
		x = -1;
		while (++x < texture->width)
		{
			main->pixel_grid[y][x] = set_color(
				texture->pixels[j],
				texture->pixels[j + 1],
				texture->pixels[j + 2],
				texture->pixels[j + 3]);
			j += 4;
		}
	}
	return (0);
}
