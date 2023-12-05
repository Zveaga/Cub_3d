
#include "cube3d.h"


static int	render_map_2d(t_main *main)
{
	main->wall = create_block_image(0, main);
	if (!main->wall)
		return (1);
	main->floor = create_block_image(1, main);
	if (!main->floor)
		return (1);
	main->player = create_player_image(main);
	if (!main->player)
		return (1);
	if (render_blocks(main, main->map) != 0)
		return (1);
	if (render_player(main, main->map) != 0)
		return (1);
	return (0);
}

void init_math_data(t_main *main, t_math *math)
{
	//t_math math;

	//math = malloc(sizeof(t_math));
	math->pX = main->player_pos[0] * BLOCK_SIZE;
	math->pY = main->player_pos[1] * BLOCK_SIZE;
	math->pdX = 0;
	math->pdY = 0;
	math->pa = 0;
	math->main = main;
	main->math = math;
}

int main(int argc, char **argv)
{
	t_main	main;
	t_math	math;

	if (ft_map_parsing(argc, argv, &main))
		return (EXIT_FAILURE);
	int i = 0;
	while (main.map && main.map[i])
		printf("%s", main.map[i++]);
	
	init_math_data(&main, &math);

	main.mlx = mlx_init(1700, HEIGHT, "MLX42", true);
	if (main.mlx == NULL)
		return (EXIT_FAILURE);
	if (render_map_2d(&main) != 0)
		return (EXIT_FAILURE);
	
	// mlx_loop_hook(main.mlx, ft_hook, &main);
	mlx_key_hook(main.mlx, &move_hook_callback, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	//ft_main_free(&main);
	return (EXIT_SUCCESS);
}
