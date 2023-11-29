/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 13:36:08 by raanghel      #+#    #+#                 */
/*   Updated: 2023/11/29 13:55:57 by coxer         ########   odam.nl         */
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
		data->player->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->player->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player->instances[0].x += 5;
}

mlx_image_t *create_block(int block_type, t_data *data)
{
	(void)data;
	mlx_image_t	*block;
	int	i;
	int	j;
	int	color;

	i = 0;
	block = mlx_new_image(data->mlx, 128, 128);
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			if (block_type == 0)
				color = set_color(1, 1, 1, 1023);
			else
				color = set_color(179, 179, 179, 1023);
			mlx_put_pixel(block, i, j, color);
			j++;
		}
		i++;
	}
	return (block);
}

// void create_block(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	color;

// 	i = 0;
// 	while (i < BLOCK_SIZE)
// 	{
// 		j = 0;
// 		while (j < BLOCK_SIZE)
// 		{
// 			color = set_color(1, 1, 1, 1023);
// 			mlx_put_pixel(data->wall, i, j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	create_color(void *param)
{
	t_data			*data;
	int32_t			color;
	uint32_t		i;
	uint32_t 		j;
	
	data = param;
	i = 0;
	while (++i < data->player->width)
	{
		j = 0;
		while (++j < data->player->height)
		{
			color = set_color(153, 204, 255, 1023);
			mlx_put_pixel(data->player, i, j, color);
		}
	}
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
				mlx_image_to_window(data->mlx, data->wall, j * BLOCK_SIZE, i * BLOCK_SIZE);
			else if (map[i][j] == '0')
				mlx_image_to_window(data->mlx, data->floor, j * BLOCK_SIZE, i * BLOCK_SIZE);				
			j++;
		}	
		i++;
	}
}
