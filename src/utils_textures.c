/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: coxer <coxer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 17:43:07 by coxer         #+#    #+#                 */
/*   Updated: 2024/01/24 17:43:09 by coxer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int init_grid(mlx_image_t *texture, int32_t ***pixel_grid)
{
	uint32_t	i;

	(*pixel_grid) = (int32_t **)malloc(sizeof(int32_t *) * texture->height);
	if (!(*pixel_grid))
		return (1);
	i = 0;
	while (i < texture->height)
	{
		(*pixel_grid)[i] = (int32_t *)malloc(sizeof(int32_t) * texture->width);
		if (!(*pixel_grid)[i])
		{
			free(*pixel_grid);
			*pixel_grid = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_pixel_grids(t_main *main)
{
	if (init_grid(main->north_texture_img, &main->north_tex_pixel_grid) == 1
		|| init_grid(main->south_texture_img, &main->south_tex_pixel_grid) == 1
		|| init_grid(main->west_texture_img, &main->west_tex_pixel_grid) == 1
		|| init_grid(main->east_texture_img, &main->east_tex_pixel_grid) == 1)
	{
		return (1);
	}
	return (0);
}

static void	convert_pixels(mlx_image_t *texture, int32_t **pixel_grid)
{
	int			j;
	uint32_t	x;
	uint32_t	y;
	
	y = -1;
	j = 0;
	while (++y < texture->height)
	{
		x = -1;
		while (++x < texture->width)
		{
			pixel_grid[y][x] = set_color(
				texture->pixels[j],
				texture->pixels[j + 1],
				texture->pixels[j + 2],
				texture->pixels[j + 3]);
			j += 4;
		}
	}
}

void	convert_pixels_to_grids(t_main *main)
{
	convert_pixels(main->north_texture_img, main->north_tex_pixel_grid);
	convert_pixels(main->south_texture_img, main->south_tex_pixel_grid);
	convert_pixels(main->west_texture_img, main->west_tex_pixel_grid);
	convert_pixels(main->east_texture_img, main->east_tex_pixel_grid);
}
