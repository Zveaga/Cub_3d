
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

// static uint32_t select_texture_pixel(t_math *math, int x)
// {
// 	uint32_t	color;



// 	return (color);
// }

// int32_t getWallOrientation(double ray_dir_x, double ray_dir_y, t_math *math)
// {
//     // Check if the ray is more horizontally or vertically oriented
//     double angle = atan2(ray_dir_y, ray_dir_x);
//     angle = fmod((angle + 2 * M_PI), (2 * M_PI)); // Ensure the angle is within [0, 2*PI)

//     if ((angle >= M_PI / 4) && (angle < 3 * M_PI / 4))
//         return (math->main->pixel_grid_east_tex[math->texY][math->texX]); // South wall
//     else if ((angle >= 3 * M_PI / 4) && (angle < 5 * M_PI / 4))
//         return (math->main->pixel_grid_west_tex[math->texY][math->texX]); // West wall
//     else if ((angle >= 5 * M_PI / 4) && (angle < 7 * M_PI / 4))
//         return (math->main->pixel_grid_north_tex[math->texY][math->texX]); // North wall
// 	else
//         return (math->main->pixel_grid_south_tex[math->texY][math->texX]); // East wall
	

// 	return (-1);

// }


void	texture_calculations(t_math *math, char **map, int x, int32_t **texture)
{	
	(void)map;
	//math->texNum = map[math->mapY][math->mapX] - 1;
	
	calculate_wallX(math);
	calculate_texX(math);
	//printf("wallX: %.2f\n", math->wallX);
	// --how much to increase the tex coordinate per vertical screen line (x)--
	math->step = (double)texHeight / math->lineHeight;

	// --start of texture coordinate--
	math->texPos = (math->startPixel - HEIGHT / 2 + math->lineHeight / 2) * math->step;
	
	int					y;
	uint32_t			color;
	y = math->startPixel;

	color = -1;
	while (y < math->endPixel)
	{
		math->texY = (int)math->texPos & (texHeight - 1);
		math->texPos += math->step;
		

		//color = getWallOrientation(math->rayDirX, math->rayDirY, math);
		color = texture[math->texY][math->texX];
		// if (math->rayDirX < 0 && math->rayDirY < 0)
		// 	color = math->main->pixel_grid_east_tex[math->texY][math->texX];
		// else if (math->rayDirX < 0 && math->rayDirY > 0)
		// 	color = math->main->pixel_grid_west_tex[math->texY][math->texX];
		// else if (math->rayDirX > 0 && math->rayDirY > 0)
		// 	color = math->main->pixel_grid_north_tex[math->texY][math->texX];
		// else if (math->rayDirX > 0 && math->rayDirY < 0)
		// 	color = math->main->pixel_grid_south_tex[math->texY][math->texX];
			
		// --make y sides darker--
		// if (math->side == 1)
		// 	color = (color >> 1) & 8355711;

		math->main->image_buffer[y][x] = color; //set the individual pixel
		//printf("%d: %d\n", i, color);
		y++;
	}
}
