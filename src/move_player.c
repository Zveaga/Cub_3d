
#include "cube3d.h"

#define ROT_SPEED 0.2
#define MOV_SPEED 0.2


void	move_up(t_main *main, t_math *math)
{
	if (main->map[(int)(math->posX + math->dirX * MOV_SPEED)][(int)math->posY] != '1')
		math->posX += math->dirX * MOV_SPEED;
    if (main->map[(int)math->posX][(int)(math->posY + math->dirY * MOV_SPEED)] != '1')
		math->posY += math->dirY * MOV_SPEED;
}

void	move_back(t_main *main, t_math *math)
{
	if(main->map[(int)(math->posX - math->dirX * MOV_SPEED)][(int)math->posY] != '1')
		math->posX -= math->dirX * MOV_SPEED;
    if(main->map[(int)math->posX][(int)(math->posY - math->dirY * MOV_SPEED)] != '1')
		math->posY -= math->dirY * MOV_SPEED;
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
	printf("x: %.f, y: %.f\n", math->planeX, math->planeY);
}
