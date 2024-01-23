/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 18:14:23 by raanghel      #+#    #+#                 */
/*   Updated: 2024/01/23 18:38:41 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	init_math(t_main *main, t_math *math)
{
	math->pos_x = (double)main->player_pos[0] + 0.5;
	math->pos_y = (double)main->player_pos[1] + 0.5;
	main->math = math;
	math->main = main;
	set_player_direction(math);
}

void	init_main(t_main *main)
{
	main->map = NULL;
	main->map_name = NULL;
	main->north_texture = NULL;
	main->south_texture = NULL;
	main->west_texture = NULL;
	main->east_texture = NULL;
	main->ceiling_color = NULL;
	main->floor_color = NULL;
	main->player_pos = NULL;
	main->image = NULL;
	main->image_buffer = NULL;
	main->mlx = NULL;
	main->north_tex_pixel_grid = NULL;
	main->south_tex_pixel_grid = NULL;
	main->west_tex_pixel_grid = NULL;
	main->east_tex_pixel_grid = NULL;
	main->map_line = -1;
}

int	init_images(t_main *main)
{
	main->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!main->mlx)
		return (1);
	main->image = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	if (!main->image)
		return (1);
	if (mlx_image_to_window(main->mlx, main->image, 0, 0) == -1)
		return (1);
	if (init_image_buffer(main) == 1)
		return (1);
	return (0);
}

void print_map(char **map)
{
	for (int i = 0; map[i]; i++)
		printf("%d %s", i, map[i]);
}

int	main(int argc, char **argv)
{
	t_main	main;
	t_math	math;

	init_main(&main);
	if (ft_map_parsing(argc, argv, &main))
		return (ft_main_free(&main), EXIT_FAILURE);
	init_math(&main, &math);
	if (init_images(&main) == 1 || load_wall_textures(&main) == 1)
	{
		printf("Initialization error\n");
		return (ft_main_free(&main), EXIT_FAILURE);
	}
	print_map(main.map);
	mlx_loop_hook(main.mlx, &renderer, &main);
	mlx_loop(main.mlx);
	ft_main_free(&main);
	mlx_terminate(main.mlx);
	return (EXIT_SUCCESS);
}

