
#include "cube3d.h"


static void init_math(t_main *main, t_math *math)
{
	math->posX = (double)main->player_pos[0];
	math->posY = (double)main->player_pos[1];
	math->dirX = -1;
	math->dirY = 0;
	math->planeX = 0;
	math->planeY = 0.66;
}

int	init_data(t_main *main, t_math *math)
{
	main->image = NULL;
	main->img_buffer = NULL;

	main->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!main->mlx)
		return (1);
	main->image = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	if (!main->image)
		return (1);
	// if (mlx_image_to_window(main->mlx, main->image, 0, 0) == -1)
	// 	return (1);
	init_image_buffer(main);
	main->math = math;
	math->main = main;
	return (0);
}

int main(int argc, char **argv)
{
	t_main	main;
	t_math	math;

	if (ft_map_parsing(argc, argv, &main))
		return (ft_main_free(&main), EXIT_FAILURE);
	init_math(&main, &math);
	if (init_data(&main, &math) == 1)
	{
		//free
		exit(EXIT_FAILURE);	
	}
	mlx_loop_hook(main.mlx, &renderer, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	//ft_main_free(&main);
	return (EXIT_SUCCESS);
}
