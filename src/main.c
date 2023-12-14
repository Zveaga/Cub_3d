
#include "cube3d.h"

/* Player initial orientation (for setting NO, SO, WE, EA)

	Up    -> dirX = 0; dirY = -1; AND planeX = 0.66; planeY = 0;
	Down  -> dirX = 0; dirY = 1;  AND planeX = 0.66; planeY = 0;
	Left  -> dirX = -1; dirY = 0; AND planeX = 0; planeY = 0.66;
	Right -> dirX = 1; dirY = 0;  AND planeX = 0; planeY = 0.66;
*/

static void init_math(t_main *main, t_math *math)
{
	math->posX = (double)main->player_pos[0] + 0.5;
	math->posY = (double)main->player_pos[1] + 0.5;
	math->dirX = 0;
	math->dirY = -1;
	math->planeX = 0.66;
	math->planeY = 0;
	// printf("posX: %d\n", (int)math->posX);
	// printf("posY: %d\n", (int)math->posY);
}

int	init_data(t_main *main, t_math *math)
{
	main->image = NULL;
	main->image_buffer = NULL;

	main->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!main->mlx)
		return (1);
	main->image = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	if (!main->image)
		return (1);
	if (mlx_image_to_window(main->mlx, main->image, 0, 0) == -1)
		return (1);
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
	//printf("HEIGHT: %d\n", HEIGHT);
	// printf("posX: %.0f | %.f px \n", main.math->posX, WIDTH / main.math->posX);
	// printf("posY: %.0f | %.f px\n", main.math->posY, HEIGHT / main.math->posY);

	// printf("wallX: %d | %d px \n", 3, WIDTH / 3);
	// printf("wallY: %d | %d px\n\n", 2, HEIGHT / 2);

	//print_map(main.map);
	//draw_single_vert_line(&math, &main);
	//test_render(&main);
	fill_ceiling_floor(&main);
	mlx_loop_hook(main.mlx, &renderer, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ft_main_free(&main);
	return (EXIT_SUCCESS);
}
