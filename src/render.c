
#include "cube3d.h"
#include <float.h>



static void get_key_input(t_main *main, t_math *math)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(main->mlx);
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
			// if (y == (HEIGHT / 2) || x == (WIDTH/2))
			// 	mlx_put_pixel(main->image, x, y, set_color(255, 0, 0, 255));
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

	ceiling_color = set_color(main->ceiling_color[0], main->ceiling_color[1],main->ceiling_color[2], 255);
	floor_color = set_color(main->floor_color[0], main->floor_color[1],main->floor_color[2], 255);
	// printf("%d %d %d\n", main->ceiling_color[0], main->ceiling_color[1],main->ceiling_color[2]);
	// printf("%d %d %d\n", main->floor_color[0], main->floor_color[1],main->floor_color[2]);
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			main->image_buffer[y][x] = ceiling_color;
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			main->image_buffer[y][x] = floor_color;
			x++;
		}
		y++;
	}
	//put_pixels_to_image(main);
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
		fill_image_buffer(main, main->math, x);

		// printf("draw start: %d\n", main->math->startPixel);
		// printf("draw end: %d\n", main->math->endPixel);
		// printf("line_H: %d\n", main->math->lineHeight);

		x++;
	}
	// printf("math->cameraX: %f, math->rayDirX: %f, math->rayDirY: %f\n", main->math->cameraX, main->math->rayDirX, main->math->rayDirY);
	// printf("draw start: %d\n", main->math->startPixel);
	// printf("draw end: %d\n", main->math->endPixel);
	// printf("main->math->lineHeight: %d\n", main->math->lineHeight);
	// printf("main->math->sideDistX: %f\n", main->math->sideDistX);
	// printf("main->math->sideDistY: %f\n", main->math->sideDistY);
	// printf("main->math->deltaDistX: %f\n", main->math->deltaDistX);
	// printf("main->math->deltaDistY: %f\n", main->math->deltaDistY);
	if (add_texture(main))
		return ; // free or something
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
