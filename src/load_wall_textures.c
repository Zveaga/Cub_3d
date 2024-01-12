
#include "cube3d.h"

static int	load_wall_north_texture(t_main *main)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("./textures/redbrick.png");
	if (!texture)
		return (1);
	main->north_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->north_texture_img)
		return (1);
	main->north_tex = texture;
	return (0);
}

static int	load_wall_south_texture(t_main *main)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("./textures/bluestone.png");
	if (!texture)
		return (1);
	main->south_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->south_texture_img)
		return (1);
	return (0);
}

static int	load_wall_west_texture(t_main *main)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("./textures/colorstone.png");
	if (!texture)
		return (1);
	main->west_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->west_texture_img)
		return (1);
	return (0);
}

static int	load_wall_east_texture(t_main *main)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("./textures/greystone.png");
	if (!texture)
		return (1);
	main->east_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->east_texture_img)
		return (1);
	return (0);
}

int load_wall_textures(t_main *main)
{
	if (load_wall_north_texture(main) == 1
		|| load_wall_south_texture(main) == 1
		|| load_wall_west_texture(main) == 1
		|| load_wall_east_texture(main) == 1)
	{
		return (1);
	}

	// for (int i = 0; i < 16384; i++)
	// 	printf("%d: %d\n", i, main->north_texture_img->pixels[i]);
	// {
	// 	for (int i = 0; i < 64; i++)
	// 		printf("%d\n", main->north_texture_img->pixels[i]);
	// }
	convert_pixels_to_grid(main, main->north_texture_img);
	print_pixel_grid(main->pixel_grid);
	return (0);
}

