
#include "cube3d.h"

# define texWidth 64
# define texHeight 64

static void calculate_wallX(t_math *math)
{
	if (math->side == 0) // x side was hit
		math->wallX = math->posY + math->perpWallDist * math->rayDirY;
	else                 // y side was hit
		math->wallX = math->posX + math->perpWallDist * math->rayDirX;
	math->wallX -= floor(math->wallX);
}

static void calculate_texX(t_math *math)
{
	math->texX = (int)(math->wallX * (double)texWidth);
	if (math->side == 0 && math->rayDirX > 0)
		math->texX = texWidth - math->texX - 1;
	if (math->side == 1 && math->rayDirY < 0)
		math->texX = texWidth - math->texX - 1;
}


void	texture_calculations(t_math *math, char **map, int x)
{	
	(void)map;
	//math->texNum = map[math->mapY][math->mapX] - 1;
	
	calculate_wallX(math);
	calculate_texX(math);

	// --how much to increase the tex coordinate per vertical screen line (x)--
	math->step = (double)texHeight / math->lineHeight;

	// --start of texture coordinate--
	math->texPos = (math->startPixel - HEIGHT / 2 + math->lineHeight / 2) * math->step;
	
	int					y;
	uint32_t			color;
	y = math->startPixel;
	while (y < math->endPixel)
	{
		math->texY = (int)math->texPos & (texHeight - 1);
		math->texPos += math->step;


		color = math->main->pixel_grid[math->texY][math->texX];
		
		// --make y sides darker--
		// if (math->side == 1)
		// 	color = (color >> 1) & 8355711;
		math->main->image_buffer[y][x] = color; //set the individual pixel
		//printf("%d: %d\n", i, color);
		y++;
	}
}
