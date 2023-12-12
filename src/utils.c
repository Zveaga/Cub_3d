
#include "cube3d.h"


int32_t	set_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// static void print_map(char **map)
// {
// 	for (int i = 0; map[i]; i++)
// 		printf("%s", map[i]);
// }
