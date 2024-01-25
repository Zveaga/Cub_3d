/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: coxer <coxer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 17:31:49 by coxer         #+#    #+#                 */
/*   Updated: 2024/01/25 15:43:10 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	turn_right(t_math *math)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = math->dir_x;
	math->dir_x = math->dir_x * cos(ROT_SPEED) - math->dir_y * sin(ROT_SPEED);
	math->dir_y = old_dir_x * sin(ROT_SPEED) + math->dir_y * cos(ROT_SPEED);
	old_plane_x = math->plane_x;
	math->plane_x = math->plane_x * cos(ROT_SPEED)
		- math->plane_y * sin(ROT_SPEED);
	math->plane_y = old_plane_x * sin(ROT_SPEED)
		+ math->plane_y * cos(ROT_SPEED);
}

void	turn_left(t_math *math)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = math->dir_x;
	math->dir_x = math->dir_x * cos(-ROT_SPEED) - math->dir_y * sin(-ROT_SPEED);
	math->dir_y = old_dir_x * sin(-ROT_SPEED) + math->dir_y * cos(-ROT_SPEED);
	old_plane_x = math->plane_x;
	math->plane_x = math->plane_x * cos(-ROT_SPEED)
		- math->plane_y * sin(-ROT_SPEED);
	math->plane_y = old_plane_x * sin(-ROT_SPEED)
		+ math->plane_y * cos(-ROT_SPEED);
}
