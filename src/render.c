
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
	// if (mlx_is_key_down(main->mlx, MLX_KEY_A))
	// 	move_left();
	// if (mlx_is_key_down(main->mlx, MLX_KEY_D))
	// 	move_right();
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


void	renderer(void *param)
{
	t_main *main;
	int		x;
	main = param;
	
	memset(main->image->pixels, 0, WIDTH * HEIGHT);

	x = 0;
	while (x < WIDTH) // for every vertial pixel line
	{
		calculate_per_vertical_line(main->math, x);
		fill_image_buffer(main, main->math, x);

		// printf("draw start: %d\n", main->math->startPixel);
		// printf("draw end: %d\n", main->math->endPixel);
		// printf("line_H: %d\n", main->math->lineHeight);
		// printf("x: %d\n\n", x);

		x++;
	}

	put_pixels_to_image(main);
	//clear_image_buffer(main);
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
