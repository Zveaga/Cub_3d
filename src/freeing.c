/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 14:55:02 by ibehluli      #+#    #+#                 */
/*   Updated: 2024/01/25 14:59:41 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_static_char_buff(int fd)
{
	char	*s;

	if (fd == -1)
		return ;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}

void	ft_free_double(char	**double_arr)
{
	int	i;

	i = 0;
	if (!double_arr)
		return ;
	while (double_arr && double_arr[i])
	{
		free(double_arr[i]);
		i++;
	}
	if (double_arr)
		free(double_arr);
}

void	free_pixel_grid(int32_t **pixel_grid, mlx_image_t *texture)
{
	uint32_t	i;

	if (!pixel_grid)
		return ;
	i = 0;
	while (i < texture->height)
	{
		free(pixel_grid[i]);
		i++;
	}
	free(pixel_grid);
}

void	free_pixel_grids(t_main *main)
{
	free_pixel_grid(main->north_tex_pixel_grid, main->north_texture_img);
	free_pixel_grid(main->south_tex_pixel_grid, main->south_texture_img);
	free_pixel_grid(main->west_tex_pixel_grid, main->west_texture_img);
	free_pixel_grid(main->east_tex_pixel_grid, main->east_texture_img);
}
