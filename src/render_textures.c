
#include "cube3d.h"

# define texWidth 64
# define texHeight 64

void	texture_calculations(t_math *math, char **map, int x)
{	
	math->texNum = map[math->mapY][math->mapX] - 1;
	// calculate wallX
	if (math->side == 0) // x side was hit
		math->wallX = math->posY + math->perpWallDist * math->rayDirY;
	else // y side was hit
		math->wallX = math->posX + math->perpWallDist * math->rayDirX;
	math->wallX = floor(math->wallX);

	// calculate x coordinate of texture
	math->texX = (int)(math->wallX * (double)texWidth);
	if (math->side == 0 && math->rayDirX > 0)
		math->texX = texWidth - math->texX - 1;
	if (math->side == 1 && math->rayDirX < 0)
		math->texX = texWidth - math->texX - 1;
	

	// how much to increase the tex coordinate per vertical screen line (x)
	math->step = 1.0 * texHeight / math->lineHeight;

	// start of texture coordinate
	math->texPos = (math->startPixel - HEIGHT / 2 + math->lineHeight / 2) * math->step;
	
	int				y;
	uint32_t		color;

	y = math->startPixel;
	while (y < math->endPixel)
	{
		math->texY = (int)math->texPos & (texHeight - 1);
		math->texPos += math->step;

		color = math->main->north_texture_img->height * math->texY + math->texX;
		
		//make y sides darker
		if (math->side == 1)
			color = (color >> 1) & 8355711;
		math->main->image_buffer[y][x] = color; //set the individual pixel
		y++;
	}
}