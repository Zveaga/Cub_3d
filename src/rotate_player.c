/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: coxer <coxer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 17:31:49 by coxer         #+#    #+#                 */
/*   Updated: 2024/01/24 17:42:35 by coxer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	turn_right(t_math *math)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = math->dir_x;
	math->dir_x = math->dir_x * cos(ROT_SPEED) - math->dir_y * sin(ROT_SPEED);
	math->dir_y = oldDirX * sin(ROT_SPEED) + math->dir_y * cos(ROT_SPEED);
	oldPlaneX = math->plane_x;
	math->plane_x = math->plane_x * cos(ROT_SPEED) - math->plane_y * sin(ROT_SPEED);
	math->plane_y = oldPlaneX * sin(ROT_SPEED) + math->plane_y * cos(ROT_SPEED);
}

void	turn_left(t_math *math)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = math->dir_x;
	math->dir_x = math->dir_x * cos(-ROT_SPEED) - math->dir_y * sin(-ROT_SPEED);
	math->dir_y = oldDirX * sin(-ROT_SPEED) + math->dir_y * cos(-ROT_SPEED);
	oldPlaneX = math->plane_x;
	math->plane_x = math->plane_x * cos(-ROT_SPEED) - math->plane_y * sin(-ROT_SPEED);
	math->plane_y = oldPlaneX * sin(-ROT_SPEED) + math->plane_y * cos(-ROT_SPEED);
}
