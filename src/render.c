/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 13:36:08 by raanghel      #+#    #+#                 */
/*   Updated: 2023/11/29 17:25:54 by coxer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

# define BLOCK_SIZE 128

int32_t	set_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param)
{
	t_data	*data;
	
	data = param;
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->player->instances[0].y -= 4;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player->instances[0].y += 4;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->player->instances[0].x -= 4;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player->instances[0].x += 4;
}

mlx_image_t *create_block_image(int block_type, t_data *data)
{
	mlx_image_t	*block_image;
	int	i;
	int	j;
	int	color;

	i = 0;
	block_image = mlx_new_image(data->mlx, 128, 128);
	while (i < 128)
	{
		j = 0;
		while (j < 128)
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

mlx_image_t *create_player_image(t_data *data)
{
	mlx_image_t	*player_image;
	int	i;
	int	j;
	int	color;

	i = 0;
	player_image = mlx_new_image(data->mlx, 64, 64);
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			color = set_color(153, 204, 255, 1023);
			mlx_put_pixel(player_image, i, j, color);
			j++;
		}
		i++;
	}
	return (player_image);
}


void render_blocks(t_data *data, char map[8][8])
{
	int	i;
	int	j;


	i = 0;
	j = 0;
	while(i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->wall, (j * 128), (i * 128));
			else
				mlx_image_to_window(data->mlx, data->floor, (j * 128), (i * 128));
			j++;
		}	
		i++;
	}
}

// void	render_vertical_blocks(t_data *data, char map[8][8])
// {
// 	int	i;
// 	int	j;
// 	i = 0;
// 	j = 0;
// 	while(i < 8)
// 	{
// 		j = 0;
// 		while (j < 8)
// 		{
// 			if (map[i][j] == '1')
// 				mlx_image_to_window(data->mlx, data->wall, (j * 128), (i * 128));
// 			else
// 				mlx_image_to_window(data->mlx, data->floor, (j * 128), (i * 128));
// 			j++;
// 		}	
// 	}
// }

void render_player(t_data *data, char map[8][8])
{
	int	i;
	int	j;


	i = 0;
	j = 0;
	while(i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (map[i][j] == 'P')
				mlx_image_to_window(data->mlx, data->player, j * 128, i * 128);
			j++;
		}	
		i++;
	}
}
