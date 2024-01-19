
#include "cube3d.h"

#define ROT_SPEED 0.03
#define MOV_SPEED 0.06


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
	
	new_posX = (int)((math->posX) + math->dirX * MOV_SPEED);
	new_posY = (int)((math->posY) + math->dirY * MOV_SPEED);

	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->posX += math->dirX * MOV_SPEED;
		math->posY += math->dirY * MOV_SPEED;
	}
}

void	move_back(t_main *main, t_math *math)
{
	int	new_posX;
	int	new_posY;

	new_posX = (int)(math->posX - math->dirX * MOV_SPEED);
	new_posY = (int)(math->posY - math->dirY * MOV_SPEED);

	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->posX -= math->dirX * MOV_SPEED;
		math->posY -= math->dirY * MOV_SPEED;
	}
}

void	move_left(t_main *main, t_math *math)
{
	int	new_posX;
	int	new_posY;

	new_posX = (int)(math->posX - math->planeX * MOV_SPEED);
	new_posY = (int)(math->posY - math->planeY * MOV_SPEED);

	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->posX -= math->planeX * MOV_SPEED;
		math->posY -= math->planeY * MOV_SPEED;
	}
}

void	move_right(t_main *main, t_math *math)
{
	int	new_posX;
	int	new_posY;

	new_posX = (int)(math->posX + math->planeX * MOV_SPEED);
	new_posY = (int)(math->posY + math->planeY * MOV_SPEED);

	if (player_hits_wall(main, new_posX, new_posY) == false)
	{
		math->posX += math->planeX * MOV_SPEED;
		math->posY += math->planeY * MOV_SPEED;
	}
}

void	turn_right(t_math *math)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = math->dirX;
	math->dirX = math->dirX * cos(ROT_SPEED) - math->dirY * sin(ROT_SPEED);
	math->dirY = oldDirX * sin(ROT_SPEED) + math->dirY * cos(ROT_SPEED);

	oldPlaneX = math->planeX;
	math->planeX = math->planeX * cos(ROT_SPEED) - math->planeY * sin(ROT_SPEED);
	math->planeY = oldPlaneX * sin(ROT_SPEED) + math->planeY * cos(ROT_SPEED);
}

void	turn_left(t_math *math)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = math->dirX;
	math->dirX = math->dirX * cos(-ROT_SPEED) - math->dirY * sin(-ROT_SPEED);
	math->dirY = oldDirX * sin(-ROT_SPEED) + math->dirY * cos(-ROT_SPEED);

	oldPlaneX = math->planeX;
	math->planeX = math->planeX * cos(-ROT_SPEED) - math->planeY * sin(-ROT_SPEED);
	math->planeY = oldPlaneX * sin(-ROT_SPEED) + math->planeY * cos(-ROT_SPEED);
}
