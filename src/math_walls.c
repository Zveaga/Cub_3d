/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_walls.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 18:14:32 by raanghel      #+#    #+#                 */
/*   Updated: 2024/01/23 18:44:08 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	calculate_side_dist(t_math *math)
{
	if (math->ray_dir_x < 0)
	{
		math->step_x = -1;
		math->side_dist_x = (math->pos_x - math->map_x) * math->delta_dist_x;
	}
	else
	{
		math->step_x = 1;
		math->side_dist_x = (math->map_x + 1.0 - math->pos_x) * math->delta_dist_x;
	}
	if (math->ray_dir_y < 0)
	{
		math->step_y = -1;
		math->side_dist_y = (math->pos_y - math->map_y) * math->delta_dist_y;
	}
	else
	{
		math->step_y = 1;
		math->side_dist_y = (math->map_y + 1.0 - math->pos_y) * math->delta_dist_y;
	}
}

static void	calculate_delta_dist(t_math *math)
{
	if (math->ray_dir_x == 0)
		math->delta_dist_x = INT32_MAX;
	else
		math->delta_dist_x = fabs(1 / math->ray_dir_x);
	if (math->ray_dir_y == 0)
		math->delta_dist_y = INT32_MAX;
	else
		math->delta_dist_y = fabs(1 / math->ray_dir_y);
}

static void	perform_dda(t_math *math)
{
	int	hit_wall;

	hit_wall = 0;
	while (hit_wall == 0)
	{
		if (math->side_dist_x < math->side_dist_y)
		{
			math->side_dist_x += math->delta_dist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->side_dist_y += math->delta_dist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if (math->main->map[math->map_y][math->map_x] == '1')
			hit_wall = 1;
	}
}

static void	calculate_line_height(t_math *math)
{
	if (math->side == 0)
		math->perp_wall_dist = (math->side_dist_x - math->delta_dist_x);
	else
		math->perp_wall_dist = (math->side_dist_y - math->delta_dist_y);

	math->line_height = (int)(HEIGHT / math->perp_wall_dist);
	math->line_start = -math->line_height / 2 + HEIGHT / 2;
	if (math->line_start < 0)
		math->line_start = 0;
	math->line_end = math->line_height / 2 + HEIGHT / 2;
	if (math->line_end >= HEIGHT)
		math->line_end = HEIGHT - 1;
}

void	calculate_per_vertical_line(t_math *math, int x)
{
	math->camera_x = 2 * (x / (double)WIDTH) - 1;
	math->ray_dir_x = math->dir_x + (math->plane_x * math->camera_x);
	math->ray_dir_y = math->dir_y + (math->plane_y * math->camera_x);
	math->map_x = (int)math->pos_x;
	math->map_y = (int)math->pos_y;
	calculate_delta_dist(math);
	calculate_side_dist(math);
	perform_dda(math);
	calculate_line_height(math);
}
