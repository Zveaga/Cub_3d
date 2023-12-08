
#include "cube3d.h"

int	ft_check_map_name(char	*map_name)
{
	int fd;

	fd = open(map_name, O_RDWR, 0644);
	if (fd == -1)
		return (close(fd), 1);
	close(fd);
	if (!ft_strncmp(&map_name[ft_strlen(map_name) - 4], ".cub", 4))
		return (0);
	return (1);
}

int	ft_all_number(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	path_check(t_main *main, char	*s, char face)
{
	char	*s1;
	mlx_texture_t	*temp;

	if (!s)
		return (0);
	s1 = ft_strtrim(s, " 	\n");
	if (!s1)
		return (1);
	temp = mlx_load_png(s1);
	if (!temp)
		return (free(s1), 1);
	mlx_delete_texture(temp);
	if (face == 'N' && !main->north_texture)
		main->north_texture = s1;
	else if (face == 'S' && !main->south_texture)
		main->south_texture = s1;
	else if (face == 'W' && !main->west_texture)
		main->west_texture = s1;
	else if (face == 'E' && !main->east_texture)
		main->east_texture = s1;
	else
		return (free(s1), 1);
	return (0);
}

void	assign_color(t_main *main, char **split_color_value, char	floor_or_ceiling)
{
	if (floor_or_ceiling == 'C')
	{
		main->ceiling_color = malloc(sizeof(int) * 3);
		if (!main->ceiling_color || split_color_value[0])
			return ;
		if (!split_color_value[1] || !split_color_value[2])
		{
			free(main->ceiling_color);
			free(main->floor_color);
			return ;
		}
		main->ceiling_color[0] = ft_atoi(split_color_value[0]);
		main->ceiling_color[1] = ft_atoi(split_color_value[1]);
		main->ceiling_color[2] = ft_atoi(split_color_value[2]);
	}
	else
	{
		main->floor_color = (int *) malloc(sizeof(int) * 3);
		if (!main->floor_color || split_color_value[0])
			return ;
		if (!split_color_value[1] || !split_color_value[2])
		{
			free(main->ceiling_color);
			free(main->floor_color);
			return ;
		}
		main->floor_color[0] = ft_atoi(split_color_value[0]);
		main->floor_color[1] = ft_atoi(split_color_value[1]);
		main->floor_color[2] = ft_atoi(split_color_value[2]);
	}
}

int	color_check(t_main *main, char *s, char	floor_or_ceiling)
{
	int		i;
	char	**split_color_value;
	char	*s1;

	i = 1;
	if (!s || !main)
		return (1);
	if ((floor_or_ceiling == 'C' && main->ceiling_color) || (floor_or_ceiling == 'F' && main->floor_color))
		return (1);
	s1 = ft_strtrim(s + i, " 	\n");
	if (!s1)
		return (1);
	split_color_value = ft_split(s1, ',');
	if (!split_color_value)
		return (free(s1), 1);
	free(s1);
	i = 0;
	while(split_color_value && split_color_value[i])
	{
		if (!ft_all_number(split_color_value[i])
			|| ft_atoi(split_color_value[i]) < 0
			|| ft_atoi(split_color_value[i]) > 255)
			return (ft_free_double(split_color_value), 1);
		i++;
	}
	assign_color(main, split_color_value, floor_or_ceiling);
	if (floor_or_ceiling == 'F' && !main->floor_color)
		return (1);
	if (floor_or_ceiling == 'C' && !main->ceiling_color)
		return (1);
	ft_free_double(split_color_value);
	return (0);
}

int	check_more_precise(t_main *main, char	*s)
{
	if (s && (!ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1)))
	{
		if (color_check(main, s + 1, s[0]))
			return (1);
	}
	else
	{
		if (path_check(main, s + 2, s[0]))
			return (1);
	}
	return (0);
}

int	check_credentials_value(t_main *main, char *s)
{
	int	i;
	int	flag;
	
	i = 0;
	flag = 0;
	if (!main || !s)
		return (1);
	while(s && s[i])
	{
		if (s[i] == ' ' || s[i] == '\n')
			i++;
		else
			break;
    }
	if (!ft_strnstr(s + i, "NO", 2) || !ft_strnstr(s + i, "SO", 2)
		|| !ft_strnstr(s + i, "WE", 2) || !ft_strnstr(s + i, "EA", 2)
		|| !ft_strnstr(s + i, "F", 1) || !ft_strnstr(s + i, "C", 1))
		flag++;
	if (flag == 1)
	{
		if (check_more_precise(main, s + i))
			return (1);
	}
	return (0);
}

int	check_credentials(t_main *main)
{
	int		count;
	int		fd;
	char	*s;

	fd = open(main->map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (1);
	count = 0;
	s = get_next_line(fd);
	if (!s)
		return (close(fd), 1);
	main->map_line = 0;
	while (s)
	{
		if (!check_credentials_value(main, s))
			count++;
		else
			return (free(s), free_static_char_buff(fd), 1);
		main->map_line++;
		free(s);
		if (count == 6)
			break ;
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	return (0);
}

int	flood_fill(t_main *main, int x, int y, char	find, char change)
{
	if (!main)
		return (1);
	if (!main->player_pos)
		return (1);
	if (!main->map[y][x] || main->map[y][x] == '\n' || main->map[y][x] == ' ')
		return (1);
	if (main->map && (main->map[y][x] == find || main->map[y][x] == 'N'
		|| main->map[y][x] == 'S' || main->map[y][x] == 'W' || main->map[y][x] == 'E'))
	{
		if (main->map[y][x] != 'N' && main->map[y][x] != 'S'
		&& main->map[y][x] != 'W' && main->map[y][x] != 'E')
			main->map[y][x] = change;
		if (flood_fill(main, x + 1, y, '0', 'A'))
			return (1);
		if (flood_fill(main, x - 1, y, '0', 'A'))
			return (1);
		if (flood_fill(main, x, y + 1, '0', 'A'))
			return (1);
		if (flood_fill(main, x, y - 1, '0', 'A'))
			return (1);
		if (flood_fill(main, x + 1, y + 1, '0', 'A'))
			return (1);
		if (flood_fill(main, x + 1, y - 1, '0', 'A'))
			return (1);
		if (flood_fill(main, x - 1, y - 1, '0', 'A'))
			return (1);
		if (flood_fill(main, x - 1, y + 1, '0', 'A'))
			return (1);
	}
	return(0);
}

int	ft_map_checking(char *map_name, t_main *main)
{
	main->map_name = map_name;
	if (!main->map_name || ft_check_map_name(map_name))
		return (1);
	if (check_credentials(main))
		return (1);
	if (create_map(main))
		return (1);
	if (find_player_start(main))
		return (1);
	if (flood_fill(main, main->player_pos[0], main->player_pos[1], '0', 'A') == 1)
		return (1);
	return (0);
}

int	ft_map_parsing(int argc, char **argv, t_main *main)
{
	if (argc < 2)
		return (ft_putstr_fd("Map not inserted\n", 2), 1);
	if (ft_map_checking(argv[1], main) == 1)
		return (ft_putstr_fd("Map Error\n", 2), 1);
	return (0);
}
