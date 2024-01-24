
#include "cube3d.h"

int	check_if_input_are_valid(char **map)
{
	int		found_pos;
	int		x;
	int		y;

	y = -1;
	found_pos = 0;
	if (!map)
		return (1);
	while (map[++y])
	{
		x = -1;
		while (map && map[y][++x] && map[y][x] != '\n')
		{
			if (map[y][x] == 'W' || map[y][x] == 'N'
				|| map[y][x] == 'S' || map[y][x] == 'E')
				found_pos++;
			if (map[y][x] != 'W' && map[y][x] != 'N'
				&& map[y][x] != 'S' && map[y][x] != 'E'
				&& map[y][x] != ' ' && map[y][x] != '0' && map[y][x] != '1')
				return (1);
		}
	}
	if (found_pos == 0 || found_pos > 1)
		return (1);
	return (0);
}

int	find_player_start(t_main *main)
{
	int		x;
	int		y;

	main->player_pos = malloc(2 * sizeof(int));
	if (!main->player_pos)
		return (1);
	y = 0;
	while (main->map && main->map[y])
	{
		x = 0;
		while (main->map[y][x] && main->map[y][x] != '\n')
		{
			if (main->map[y][x] == 'W' || main->map[y][x] == 'N'
				|| main->map[y][x] == 'S' || main->map[y][x] == 'E')
			{
				main->player_pos[0] = x;
				main->player_pos[1] = y;
				main->direction = main->map[y][x];
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int ft_isspace(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n')
		|| (s[i] == '\v') || (s[i] == '\f') || (s[i] == '\r'))
			i++;
		else if (s[i])
			return (0);
	}
    return (1);
}

int	map_length(t_main *main)
{
	int		count;
	int		fd;
	char	*s;
	int		pos;

	fd = open(main->map_name, O_RDONLY, 0644);
	pos = 0;
	if (fd == -1)
		return (0);
	count = 0;
	s = get_next_line(fd);
	if (!s)
		return (close(fd), 0);
	while (s)
	{
		if (pos > main->map_line)
			count++;
		pos++;
		free(s);
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	close(fd);
	return (count);
}

int	fill_map(t_main *main, int fd)
{
	int		i;
	char	*s;
	int		pos;

	i = 0;
	pos = 0;
	if (fd == -1)
		return (1);
	s = get_next_line(fd);
	if (!s)
		return (1);
	while (s)
	{
		if (s && s[0] && s[0] == '\n')
		{
			pos--;
		}
		if (pos >= main->map_line)
		{
			main->map[i] = ft_strdup(s);
			if (!main->map[i])
				return (free(s), 1);
			i++;
		}
		pos++;
		free(s);
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	main->map[i] = NULL;
	return (0);
}


int	create_map(t_main *main)
{
	int		fd;
	int		size;

	if (!main)
		return (1);
	size = map_length(main);
	if (size < 1)
		return (1);
	fd = open(main->map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (1);
	main->map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!main->map)
		return (close (fd), 1);
	if (fill_map(main, fd))
	{
		free(main->map);
		main->map = NULL;
		return (free_static_char_buff(fd), close(fd), 1);
	}
	close(fd);
	if (check_if_input_are_valid(main->map))
		return (1);
	return (0);
}
