
#include "cube3d.h"


int32_t	set_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void print_map(char **map)
{
	for (int i = 0; map[i]; i++)
		printf("%s", map[i]);
}

void	revert_map_to_original_symbols(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'A')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}
