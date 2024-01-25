/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_textures.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: coxer <coxer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 17:32:10 by coxer         #+#    #+#                 */
/*   Updated: 2024/01/25 15:48:42 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	calculate_wall_x(t_math *math)
{
	if (math->side == 0)
		math->wall_x = math->pos_y + math->perp_wall_dist * math->ray_dir_y;
	else
		math->wall_x = math->pos_x + math->perp_wall_dist * math->ray_dir_x;
	math->wall_x -= floor(math->wall_x);
}

static void	calculate_tex_x(t_math *math, mlx_image_t *texture)
{
	math->tex_x = (int)(math->wall_x * (double)texture->width);
	if (math->side == 0 && math->ray_dir_x > 0)
		math->tex_x = texture->width - math->tex_x - 1;
	if (math->side == 1 && math->ray_dir_y < 0)
		math->tex_x = texture->width - math->tex_x - 1;
}

static void	calculate_step_and_start_tex(t_main *main, t_math *math)
{
	math->step = (double)main->north_texture_img->height / math->line_height;
	math->tex_pos = (math->line_start - HEIGHT / 2 + math->line_height / 2)
		* math->step;
}

void	fill_img_buffer(t_main *main, t_math *math, int x, int32_t **texture)
{
	int					y;
	uint32_t			color;

	y = math->line_start;
	while (y < math->line_end)
	{
		math->tex_y = (int)math->tex_pos;
		math->tex_pos += math->step;
		color = texture[math->tex_y][math->tex_x];
		main->image_buffer[y][x] = color;
		y++;
	}
}

void	calculate_tex(t_main *main, t_math *math)
{
	calculate_wall_x(math);
	calculate_tex_x(math, main->north_texture_img);
	calculate_step_and_start_tex(main, math);
}
