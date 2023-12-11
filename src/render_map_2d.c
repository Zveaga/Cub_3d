
#include "cube3d.h"


// USE THIS TO SET COLOR AS A SINGLE INT
int32_t	set_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// void ft_hook(void* param)
// {
// 	t_main	*main;

// 	main = param;

// 	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
// 	{
// 		mlx_close_window(main->mlx);
// 		exit(EXIT_SUCCESS);
// 	}
// 	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
// 		main->player->instances[0].y -= 5;
// 	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
// 		main->player->instances[0].y += 5;
// 	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
// 		main->player->instances[0].x -= 5;
// 	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
// 		main->player->instances[0].x += 5;
// }

void	move_hook_callback(mlx_key_data_t keydata, void *param)
{
	t_main	*main;

	main = param;

	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(main->mlx);
	
	if ((keydata.key == MLX_KEY_W) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		printf("angle: %.2f\n", main->math->pa);
		printf("pdX: %.2f\n", main->math->pdX);
		printf("pdY: %.2f\n\n", main->math->pdY);
		main->player->instances[0].x += main->math->pdX;
		main->player->instances[0].y += main->math->pdY;

		main->dir_line->instances[0].x += main->math->pdX;
		main->dir_line->instances[0].y += main->math->pdY;
	}
	if ((keydata.key == MLX_KEY_S) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		printf("angle: %.2f\n", main->math->pa);
		printf("pdX: %.2f\n", main->math->pdX);
		printf("pdY: %.2f\n\n", main->math->pdY);
		main->player->instances[0].x -= main->math->pdX;
		main->player->instances[0].y -= main->math->pdY;

		main->dir_line->instances[0].x -= main->math->pdX;
		main->dir_line->instances[0].y -= main->math->pdY;
	}
	if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{

		main->math->pa -= 0.1;
		if (main->math->pa < 0)
		{
			printf("RESET\n");
			printf("angle: %.2f\n", main->math->pa);
			main->math->pa += 2 * PI;
		}
		main->math->pdX = cos(main->math->pa) * 5;
		main->math->pdY = sin(main->math->pa) * 5;
		printf("left\n");
		printf("angle: %.2f\n\n", main->math->pa);
		main->dir_line->instances[0].x -= main->math->pdX;
		main->dir_line->instances[0].y -= main->math->pdY;
	}
	if ((keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{

		main->math->pa += 0.1;
		if (main->math->pa > 2 * PI)
		{
			printf("RESET\n");
			printf("angle: %.2f\n", main->math->pa);
			main->math->pa -= 2 * PI;
		}		
		main->math->pdX = cos(main->math->pa) * 5;
		main->math->pdY = sin(main->math->pa) * 5;
		printf("right\n");
		printf("angle: %.2f\n\n", main->math->pa);

		main->dir_line->instances[0].x += main->math->pdX;
		main->dir_line->instances[0].y += main->math->pdY;
	}
}

mlx_image_t *create_block_image(int block_type, t_main *main)
{
	int	i;
	int	j;
	int	color;
	mlx_image_t	*block_image;

	i = 0;
	block_image = mlx_new_image(main->mlx, 64, 64);
	if (!block_image)
		return (mlx_close_window(main->mlx), NULL);
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			if (block_type == 0)
				color = set_color(1, 1, 1, 1023);
			else
				color = set_color(179, 179, 179, 1023);
			mlx_put_pixel(block_image, i, j, color);
			j++;
		}
		i++;
	}
	return (block_image);
}

mlx_image_t *create_player_image(t_main *main)
{
	int	i;
	int	j;
	int	color;
	mlx_image_t	*player_image;

	i = 0;
	player_image = mlx_new_image(main->mlx, 16, 16);
	if (!player_image)
		return (mlx_close_window(main->mlx), NULL);
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			color = set_color(255, 80, 80, 1023);
			mlx_put_pixel(player_image, i, j, color);
			j++;

		}
		i++;
	}
	return (player_image);
}

mlx_image_t *create_line_image(t_main *main)
{
	int	i;
	int	j;
	int	color;
	mlx_image_t	*dir_line;

	i = 0;
	dir_line = mlx_new_image(main->mlx, 50, 3);
	if (!dir_line)
		return (mlx_close_window(main->mlx), NULL);
	while (i < 50)
	{
		j = 0;
		while (j < 3)
		{
			color = set_color(255, 20, 20, 1023);
			mlx_put_pixel(dir_line, i, j, color);
			j++;

		}
		i++;
	}
	return (dir_line);
}

int	render_blocks(t_main *main, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				if (mlx_image_to_window(main->mlx, main->wall, (j * 64), (i * 64)) == -1)
					return (mlx_close_window(main->mlx), 1);
			}
			else if (map[i][j] == 'A' || map[i][j] == 'N')
			{
				if (mlx_image_to_window(main->mlx, main->floor, (j * 64), (i * 64)) == -1)
					return (mlx_close_window(main->mlx), 1);
			}
			j++;
		}	
		i++;
	}
	return (0);
}

int render_player(t_main *main, char **map)
{
	(void)map;
	int	px;
	int	py;

	px = main->player_pos[0];
	py = main->player_pos[1];
	if (mlx_image_to_window(main->mlx, main->player,
		(px * BLOCK_SIZE), (py * BLOCK_SIZE)) == -1)
	{
		return (mlx_close_window(main->mlx), 1);
	}
	mlx_image_to_window(main->mlx, main->dir_line, px * BLOCK_SIZE, (py * BLOCK_SIZE) + 6);

	return (0);

}

// void init_math_data(t_main *main, t_math *math)
// {
// 	//t_math math;

// 	//math = malloc(sizeof(t_math));
// 	math->pX = main->player_pos[0] * BLOCK_SIZE;
// 	math->pY = main->player_pos[1] * BLOCK_SIZE;
// 	math->pdX = 0;
// 	math->pdY = 0;
// 	math->pa = 0;
// 	math->main = main;
// 	main->math = math;
// }

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
	main->dir_line = create_line_image(main);
	if (!main->dir_line)
		return (1);
	if (render_blocks(main, main->map) != 0)
		return (1);
	if (render_player(main, main->map) != 0)
		return (1);
	return (0);
}
