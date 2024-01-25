/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 18:14:51 by raanghel      #+#    #+#                 */
/*   Updated: 2024/01/25 15:47:04 by ibehluli      ########   odam.nl         */
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
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)((math->pos_x) + math->dir_x * MOV_SPEED);
	new_pos_y = (int)((math->pos_y) + math->dir_y * MOV_SPEED);
	if (player_hits_wall(main, new_pos_x, new_pos_y) == false)
	{
		math->pos_x += math->dir_x * MOV_SPEED;
		math->pos_y += math->dir_y * MOV_SPEED;
	}
}

void	move_back(t_main *main, t_math *math)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(math->pos_x - math->dir_x * MOV_SPEED);
	new_pos_y = (int)(math->pos_y - math->dir_y * MOV_SPEED);
	if (player_hits_wall(main, new_pos_x, new_pos_y) == false)
	{
		math->pos_x -= math->dir_x * MOV_SPEED;
		math->pos_y -= math->dir_y * MOV_SPEED;
	}
}

void	move_left(t_main *main, t_math *math)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(math->pos_x - math->plane_x * MOV_SPEED);
	new_pos_y = (int)(math->pos_y - math->plane_y * MOV_SPEED);
	if (player_hits_wall(main, new_pos_x, new_pos_y) == false)
	{
		math->pos_x -= math->plane_x * MOV_SPEED;
		math->pos_y -= math->plane_y * MOV_SPEED;
	}
}

void	move_right(t_main *main, t_math *math)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(math->pos_x + math->plane_x * MOV_SPEED);
	new_pos_y = (int)(math->pos_y + math->plane_y * MOV_SPEED);
	if (player_hits_wall(main, new_pos_x, new_pos_y) == false)
	{
		math->pos_x += math->plane_x * MOV_SPEED;
		math->pos_y += math->plane_y * MOV_SPEED;
	}
}
