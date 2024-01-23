
#include "cube3d.h"

static int	load_wall_north_texture(t_main *main)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(main->north_texture);
	if (!texture)
		return (1);
	main->north_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->north_texture_img)
		return (mlx_delete_texture(texture), 1);
	mlx_delete_texture(texture);
	return (0);
}

static int	load_wall_south_texture(t_main *main)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(main->south_texture);
	if (!texture)
		return (1);
	main->south_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->south_texture_img)
		return (mlx_delete_texture(texture), 1);
	mlx_delete_texture(texture);
	return (0);
}

static int	load_wall_west_texture(t_main *main)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(main->west_texture);
	if (!texture)
		return (1);
	main->west_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->west_texture_img)
		return (mlx_delete_texture(texture), 1);
	mlx_delete_texture(texture);
	return (0);
}

static int	load_wall_east_texture(t_main *main)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(main->east_texture);
	if (!texture)
		return (1);
	main->east_texture_img = mlx_texture_to_image(main->mlx, texture);
	if (!main->east_texture_img)
		return (mlx_delete_texture(texture), 1);
	mlx_delete_texture(texture);
	return (0);
}

int	load_wall_textures(t_main *main)
{
	if (load_wall_north_texture(main) == 1
		|| load_wall_south_texture(main) == 1
		|| load_wall_west_texture(main) == 1
		|| load_wall_east_texture(main) == 1)
	{
		return (1);
	}
	if (init_pixel_grids(main) == 1)
		return (1);
	convert_pixels_to_grids(main);
	return (0);
}
