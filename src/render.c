
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

// static int32_t **select_texture_2(double ray_dir_x, double ray_dir_y, t_math *math)
// {
//     // Check if the ray is more horizontally or vertically oriented
//     double angle = atan2(ray_dir_y, ray_dir_x);
//     angle = fmod((angle + 2 * M_PI), (2 * M_PI)); // Ensure the angle is within [0, 2*PI)

//     if ((angle >= M_PI / 4) && (angle < 3 * M_PI / 4))
//         return (math->main->pixel_grid_south_tex); // South wall
//     else if ((angle >= 3 * M_PI / 4) && (angle < 5 * M_PI / 4))
//         return (math->main->pixel_grid_west_tex); // West wall
//     else if ((angle >= 5 * M_PI / 4) && (angle < 7 * M_PI / 4))
//         return (math->main->pixel_grid_north_tex); // North wall
// 	else
//         return (math->main->pixel_grid_south_tex); // East wall
	

// 	return (NULL);

// }

static int32_t **select_texture(t_main *main, t_math *math)
{
	int32_t **texture;

	texture = NULL;
	if (math->side == 1 && math->rayDirY > 0)
		texture = main->pixel_grid_north_tex;
	else if (math->side == 1 && math->rayDirY < 0)
		texture = main->pixel_grid_south_tex;
	else if (math->side == 0 && math->rayDirX > 0)
		texture = main->pixel_grid_west_tex;
	else if (math->side == 0 && math->rayDirX < 0)
		texture = main->pixel_grid_east_tex;
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
		//fill_image_buffer(main, main->math, x);
		//printf("rayDirX: %.2f\nrayDirY: %.2f\n",main->math->rayDirX, main->math->rayDirY);
		// printf("planeX: %.2f\n", main->math->planeX);
		// printf("planeY: %.2f\n", main->math->planeY);
		//printf("side:   %d\n", main->math->side);
		// printf("dirX:   %.2f\n", main->math->dirX);
		// printf("dirY:   %.2f\n\n", main->math->dirY);
		texture_calculations(main->math, main->map, x, select_texture(main, main->math));
		// texture_calculations(main->math, main->map, x, select_texture_2(main->math->rayDirX, main->math->rayDirY, main->math));

		// printf("draw start: %d\n", main->math->startPixel);
		// printf("draw end: %d\n", main->math->endPixel);
		// printf("line_H: %d\n", main->math->lineHeight);
		// printf("x: %d\n\n", x);

		x++;
	}
	put_pixels_to_image(main);
	clear_image_buffer(main);
	get_key_input(main, main->math);

}



// static void test_render(t_main *main)
// {
// 	int x = 0;
	
// 	while (x < WIDTH) // for every vertial pixel line
// 	{
// 		calculate_per_vertical_line(main->math, x);
// 		//draw_single_vert_line(main);
// 		fill_image_buffer(main, main->math, x);
// 		//printf("x: %d\n", x);
// 		x++;
// 	}
// 	put_pixels_to_image(main);
// 	mlx_image_to_window(main->mlx, main->image, 0, 0);
// }


// void draw_single_vert_line(t_main *main)
// {
// 	int	line_height = main->math->lineHeight;
// 	int start = main->math->startPixel;
// 	int end = main->math->endPixel;

// 	while (line_height > 0)
// 	{
// 		mlx_put_pixel(main->image, end, start, set_color(102, 153, 255, 1000));
// 		line_height--;
// 		start++;
// 	}
// 	printf("draw start: %d\n", main->math->startPixel);
// 	printf("draw end:   %d\n", main->math->endPixel);
// 	printf("line_H:     %d\n", main->math->lineHeight);
// }
