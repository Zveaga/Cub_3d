
#include "cube3d.h"
#include <float.h>

static void get_key_input(t_main *main, t_math *math)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
	{
		ft_main_free(main);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
		move_up(main, math);
	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
		move_back(main, math);
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
		turn_left(math);
	if (mlx_is_key_down(main->mlx, MLX_KEY_RIGHT))
		turn_right(math);
	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
		move_left(main, math);
	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
		move_right(main, math);
}

static void put_pixels_to_image(t_main *main)
{
	int x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(main->image, x, y, main->image_buffer[y][x]);
			x++;
		}
		y++;
	}
}

void fill_ceiling_floor(t_main *main)
{
	int32_t	floor_color;
	int32_t	ceiling_color;
	int		x;
	int		y;

	ceiling_color = set_color(main->ceiling_color[0], main->ceiling_color[1],
		main->ceiling_color[2], 255);
	floor_color = set_color(main->floor_color[0], main->floor_color[1],
		main->floor_color[2], 255);
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			main->image_buffer[y][x] = ceiling_color;
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			main->image_buffer[y][x] = floor_color;
	}
}

static int32_t **select_texture(t_main *main, t_math *math)
{
	int32_t **texture;

	texture = NULL;
	if (math->side == 1 && math->rayDirY > 0)
		texture = main->north_tex_pixel_grid;
	else if (math->side == 1 && math->rayDirY < 0)
		texture = main->south_tex_pixel_grid;
	else if (math->side == 0 && math->rayDirX > 0)
		texture = main->west_tex_pixel_grid;
	else if (math->side == 0 && math->rayDirX < 0)
		texture = main->east_tex_pixel_grid;
	return (texture);
}

void	renderer(void *param)
{
	t_main *main;
	int		x;

	main = param;
	x = 0;
	fill_ceiling_floor(main);
	while (x < WIDTH) // for every vertial pixel line
	{
		calculate_per_vertical_line(main->math, x);
		texture_calculations(main, main->math, x, select_texture(main, main->math));
		x++;
	}
	put_pixels_to_image(main);
	clear_image_buffer(main);
	get_key_input(main, main->math);

}
