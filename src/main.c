
#include "cube3d.h"


static void init_math(t_main *main, t_math *math)
{
	math->posX = main->player_pos[0] * BLOCK_SIZE;
	math->posY = main->player_pos[1] * BLOCK_SIZE;
	math->dirX = -1;
	math->dirY = 0;
	math->planeX = 0;
	math->planeY = 0.66;
}

int main(int argc, char **argv)
{
	t_main	main;
	t_math	math;

	if (ft_map_parsing(argc, argv, &main))
		return (ft_main_free(&main), EXIT_FAILURE);
	init_math(&main, &math);
	int i = 0;
	while (main.map && main.map[i])
		printf("%s", main.map[i++]);
	init_math(&main, &math);
	main.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (main.mlx == NULL)
		return (EXIT_FAILURE);

	//mlx_loop_hook(main.mlx, &render, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ft_main_free(&main);
	return (EXIT_SUCCESS);
}
