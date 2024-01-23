
#include "cube3d.h"

static void calculate_wallX(t_math *math)
{
	if (math->side == 0)
		math->wallX = math->posY + math->perpWallDist * math->rayDirY;
	else
		math->wallX = math->posX + math->perpWallDist * math->rayDirX;
	math->wallX -= floor(math->wallX);
}

static void calculate_texX(t_math *math, mlx_image_t *texture)
{
	math->texX = (int)(math->wallX * (double)texture->width);
	if (math->side == 0 && math->rayDirX > 0)
		math->texX = texture->width - math->texX - 1;
	if (math->side == 1 && math->rayDirY < 0)
		math->texX = texture->width - math->texX - 1;
}

void	texture_calculations(t_main *main, t_math *math, int x, int32_t **texture)
{	
	int					y;
	uint32_t			color;
	
	y = math->startPixel;
	calculate_wallX(math);
	calculate_texX(math, main->north_texture_img);
	math->step = (double)main->north_texture_img->height / math->lineHeight;
	math->texPos = (math->startPixel - HEIGHT / 2 + math->lineHeight / 2) * math->step;
	color = -1;
	while (y < math->endPixel)
	{
		math->texY = (int)math->texPos & (main->north_texture_img->height - 1);
		math->texPos += math->step;
		color = texture[math->texY][math->texX];
		main->image_buffer[y][x] = color;
		y++;
	}
}
