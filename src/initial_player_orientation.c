/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_player_orientation.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 18:13:59 by raanghel      #+#    #+#                 */
/*   Updated: 2024/01/23 18:39:59 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	orientate_to_north(t_math *math)
{
	math->dir_x = 0;
	math->dir_y = -1;
	math->plane_x = 0.66;
	math->plane_y = 0;
}

static void	orientate_to_south(t_math *math)
{
	math->dir_x = 0;
	math->dir_y = 1;
	math->plane_x = -0.66;
	math->plane_y = 0;
}

static void	orientate_to_west(t_math *math)
{
	math->dir_x = -1;
	math->dir_y = 0;
	math->plane_x = 0;
	math->plane_y = -0.66;
}

static void	orientate_to_east(t_math *math)
{
	math->dir_x = 1;
	math->dir_y = 0;
	math->plane_x = 0;
	math->plane_y = 0.66;
}

void	set_player_direction(t_math *math)
{
	if (math->main->direction == 'N')
		orientate_to_north(math);
	else if (math->main->direction == 'S')
		orientate_to_south(math);
	else if (math->main->direction == 'W')
		orientate_to_west(math);
	else if (math->main->direction == 'E')
		orientate_to_east(math);
}
