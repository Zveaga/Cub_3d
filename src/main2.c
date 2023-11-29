/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: coxer <coxer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 11:12:52 by coxer         #+#    #+#                 */
/*   Updated: 2023/11/29 13:55:22 by coxer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(void)
{
	t_data data;
		
	char map[8][8] = {
    {'1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '1', '0', '0', '1'},
    {'1', '0', '1', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1'},
	};
	
	data.mlx = mlx_init(2048, 1024, "TEST", true);
	
	data.player = mlx_new_image(data.mlx, 64, 64);
	
	data.wall = create_block(0, &data);
	data.floor = create_block(1, &data);
	
	render_blocks(&data, map);
	
	mlx_image_to_window(data.mlx, data.player, 150, 200);

	mlx_loop_hook(data.mlx, create_color, &data);
	mlx_loop_hook(data.mlx, ft_hook, &data);

	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);	
	return (0);
}