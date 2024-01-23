/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_moves.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 18:14:51 by raanghel      #+#    #+#                 */
/*   Updated: 2024/01/23 18:39:59 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	player_hits_wall(t_main *main, int x, int y)
{
	if (main->map[y][x] == '1')
		return (true);
	return (false);
}

void	move_up(t_main *main, t_math *math)
{
	int	new_posX;
	int	new_posY;

	new_posX = (int)((math->pos_x) + math->dir_x * MOV_SPEED);
	new_posY = (int)((math->pos_y) + math->dir_y * MOV_SPEED);
	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->pos_x += math->dir_x * MOV_SPEED;
		math->pos_y += math->dir_y * MOV_SPEED;
	}
}

void	move_back(t_main *main, t_math *math)
{
	int	new_posX;
	int	new_posY;

	new_posX = (int)(math->pos_x - math->dir_x * MOV_SPEED);
	new_posY = (int)(math->pos_y - math->dir_y * MOV_SPEED);

	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->pos_x -= math->dir_x * MOV_SPEED;
		math->pos_y -= math->dir_y * MOV_SPEED;
	}
}

void	move_left(t_main *main, t_math *math)
{
	int	new_posX;
	int	new_posY;

	new_posX = (int)(math->pos_x - math->plane_x * MOV_SPEED);
	new_posY = (int)(math->pos_y - math->plane_y * MOV_SPEED);
	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->pos_x -= math->plane_x * MOV_SPEED;
		math->pos_y -= math->plane_y * MOV_SPEED;
	}
}

void	move_right(t_main *main, t_math *math)
{
	int	new_posX;
	int	new_posY;

	new_posX = (int)(math->pos_x + math->plane_x * MOV_SPEED);
	new_posY = (int)(math->pos_y + math->plane_y * MOV_SPEED);

	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->pos_x += math->plane_x * MOV_SPEED;
		math->pos_y += math->plane_y * MOV_SPEED;
	}
}

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
