
#include "cube3d.h"

static void	orientate_to_north(t_math *math)
{
	math->dirX = 0;
	math->dirY = -1;
	math->planeX = 0.66;
	math->planeY = 0;
}

static void	orientate_to_south(t_math *math)
{
	math->dirX = 0;
	math->dirY = 1;
	math->planeX = -0.66;
	math->planeY = 0;
}

static void	orientate_to_west(t_math *math)
{
	math->dirX = -1;
	math->dirY = 0;
	math->planeX = 0;
	math->planeY = -0.66;
}

static void	orientate_to_east(t_math *math)
{
	math->dirX = 1;
	math->dirY = 0;
	math->planeX = 0;
	math->planeY = 0.66;
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
