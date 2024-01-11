
#include "cube3d.h"

# define texWidth 64
# define texHeight 64


// static int32_t color_as_single_int(int r, int g, int b, int a)
// {
// 	int32_t color;

// 	1
// }



int	convert_pixels_to_grid(t_main *main, mlx_image_t *texture)
{
	int			j;
	uint32_t	i;
	uint32_t	x;
	uint32_t	y;

	if (!(main->pixel_grid = (int32_t **)malloc(sizeof(int32_t *) * 64)))
	{
		printf("-\n");

		return (1);
	}
	i = 0;
	while (i++ < texture->height)
	{
		if (!(main->pixel_grid[i] == (int32_t *)malloc(sizeof(int32_t) * 64)))
		{
			printf("+\n");
			return (1);
		}
	}
	y = 0;
	j = 0;
	while (y++ < texture->height)
	{
		x = 0;
		while (x++ < texture->width)
		{
			main->pixel_grid[y][x] = set_color(texture->pixels[j], texture->pixels[j + 1],
				texture->pixels[j + 2], texture->pixels[j + 2]);
			j += 4;
		}
	}
	printf("++++++\n");
	return (0);
} 

void	texture_calculations(t_math *math, char **map, int x)
{	
	math->texNum = map[math->mapY][math->mapX] - 1;
	// calculate wallX
	if (math->side == 0) // x side was hit
		math->wallX = math->posY + math->perpWallDist * math->rayDirY;
	else // y side was hit
		math->wallX = math->posX + math->perpWallDist * math->rayDirX;
	math->wallX -= floor(math->wallX);
	// calculate x coordinate of texture
	math->texX = (int)(math->wallX * (double)texWidth);
	if (math->side == 0 && math->rayDirX > 0)
		math->texX = texWidth - math->texX - 1;
	if (math->side == 1 && math->rayDirY < 0)
		math->texX = texWidth - math->texX - 1;
	

	// how much to increase the tex coordinate per vertical screen line (x)
	math->step = 1.0 * texHeight / math->lineHeight;

	// start of texture coordinate
	math->texPos = (math->startPixel - HEIGHT / 2 + math->lineHeight / 2) * math->step;
	
	int					y;
	uint32_t			color;
	y = math->startPixel;
	while (y < math->endPixel)
	{
		math->texY = (int)math->texPos & (texHeight - 1);
		math->texPos += math->step;

		//color = 64 * math->texY + math->texX;
		color = math->main->north_texture_img->pixels[64 * math->texY + math->texX];
		
		//make y sides darker
		// if (math->side == 1)
		// 	color = (color >> 1) & 8355711;
		math->main->image_buffer[y][x] = color; //set the individual pixel
		//printf("%d: %d\n", i, color);
		y++;
	}
}
