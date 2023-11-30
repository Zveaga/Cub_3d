
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 13:36:08 by raanghel      #+#    #+#                 */
/*   Updated: 2023/11/29 20:48:08 by coxer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

# define BLOCK_SIZE 128

static int32_t	set_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param)
{
	t_main	*main;

	main = param;

	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(main->mlx);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
		main->player->instances[0].y -= 5;
	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
		main->player->instances[0].y += 5;
	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
		main->player->instances[0].x -= 5;
	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
		main->player->instances[0].x += 5;
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
			else if (map[i][j] == '0' || map[i][j] == 'N')
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
	int	i;
	int	j;


	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				if (mlx_image_to_window(main->mlx, main->player,
					(j * 64) + 32, (i * 64) + 32) == -1)
				{
					return (mlx_close_window(main->mlx), 1);
				}
			}
			j++;
		}	
		i++;
	}
	return (0);
}
