/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeing1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 17:32:33 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/23 17:34:56 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_image_buffer(uint32_t **img_buf)
{
	int	i;

	i = 0;
	if (!img_buf)
		return ;
	while (i < HEIGHT)
	{
		free(img_buf[i]);
		i++;
	}
	free(img_buf);
}

void	ft_main_free(t_main *main)
{
	ft_free_double(main->map);
	if (main->player_pos)
		free(main->player_pos);
	if (main->ceiling_color)
		free(main->ceiling_color);
	if (main->floor_color)
		free(main->floor_color);
	if (main->north_texture)
		free(main->north_texture);
	if (main->south_texture)
		free(main->south_texture);
	if (main->west_texture)
		free(main->west_texture);
	if (main->east_texture)
		free(main->east_texture);
	if (main->image)
		mlx_delete_image(main->mlx, main->image);
	if (main->image_buffer)
		free_image_buffer(main->image_buffer);
	main->image_buffer = NULL;
	free_pixel_grids(main);
}
