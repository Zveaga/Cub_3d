
#include "cube3d.h"


static void perform_dda(t_main *main, t_math *math, int x)
{
	//ray position and direction
	math->cameraX = 2 * x / (double)WIDTH - 1;
	math->rayDirX = math->dirX + math->planeX * math->cameraX;
	math->rayDirY = math->dirY + math->planeY * math->cameraX;

	//in which box we are in
	math->mapX = (int)math->posX;
	math->mapY = (int)math->posY;

	

}

void	render(void *param)
{
	t_main *main;
	int		x;

	main = param;
	x = 0;

	while (x < WIDTH) // for every vertial pixel line
	{

		x++;
	}


}

