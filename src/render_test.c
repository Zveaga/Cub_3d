
#include "cube3d.h"
#include <float.h>

int32_t	set_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	calculate_sideDist(t_math *math)
{
	if (math->rayDirX < 0)
	{
		math->stepX = -1;
		math->sideDistX = (math->posX - math->mapX) * math->deltaDistX;
	}
	else
	{
		math->stepX = 1;
		math->sideDistX = (math->mapX + 1 + math->posX) * math->deltaDistX;
	}
	if (math->rayDirY < 0)
	{
		math->stepY = -1;
		math->sideDistY = (math->posY - math->mapY) * math->deltaDistY;
	}
	else
	{
		math->stepY = 1;
		math->sideDistY = (math->mapY + 1 + math->posY) * math->deltaDistY;
	}
}

static void	calculate_deltaDist(t_math *math)
{
	if (math->rayDirX == 0)
		math->deltaDistX = INT32_MAX;
	else
		math->deltaDistX = fabs(1 / math->rayDirX);

	if (math->rayDirY == 0)
		math->deltaDistY = INT32_MAX;
	else
		math->deltaDistY = fabs(1 / math->rayDirY);
}

static void	perform_dda(t_math *math)
{
	int	hit_wall;

	hit_wall = 0;
	while (hit_wall == 0)
	{
		if (math->sideDistX < math->sideDistY)
		{
			math->sideDistX += math->deltaDistX;
			math->mapX += math->stepX;
			math->side = 0;
		}
		else
		{
			math->sideDistY += math->deltaDistY;
			math->mapY += math->stepY;
			math->side = 1;
		}
		if (math->main->map[math->mapY][math->mapX] == '1')
			hit_wall = 1;
	}
}

static void	calculate_line_height(t_math *math)
{
	if (math->side == 0)
		math->perpWallDist = (math->sideDistX - math->deltaDistX);
	else
		math->perpWallDist = (math->sideDistY - math->deltaDistY);
	
	math->lineHeight = (int)(HEIGHT / math->perpWallDist);
	math->startPixel = -math->lineHeight / 2 + HEIGHT / 2;
	if (math->startPixel < 0)
		math->startPixel = 0;
	
	math->endPixel = math->lineHeight / 2 + HEIGHT / 2;
	if (math->endPixel >= HEIGHT)
		math->endPixel = HEIGHT - 1;
}

void calculate_per_vertical_line(t_math *math, int x)
{
	//ray position and direction
	math->cameraX = (2 * x) / ((double)WIDTH - 1);
	math->rayDirX = math->dirX + math->planeX * math->cameraX;
	math->rayDirY = math->dirY + math->planeY * math->cameraX;

	//in which box we are in
	math->mapX = (int)math->posX;
	math->mapY = (int)math->posY;

	calculate_deltaDist(math);
	calculate_sideDist(math);
	perform_dda(math);
	calculate_line_height(math);

}

// static void moves(t_main *map, t_math *math)
// {

// }

void	renderer(void *param)
{
	t_main *main;
	int		x;
	main = param;
	
	printf("%f\n", main->math->posX);
	printf("%f\n", main->math->posY);

	x = 0;
	while (x < WIDTH) // for every vertial pixel line
	{
		//usleep(1000);
		calculate_per_vertical_line(main->math, x);

		printf("draw start: %d\n", main->math->startPixel);
		printf("draw end: %d\n", main->math->endPixel);
		// printf("line_H: %d\n", main->math->lineHeight);
		// printf("x: %d\n\n", x);

		x++;
	}
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(main->mlx);
		exit(EXIT_SUCCESS);
	}


}

